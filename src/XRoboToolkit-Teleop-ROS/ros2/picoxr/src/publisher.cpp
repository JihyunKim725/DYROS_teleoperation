#include <chrono>
#include <memory>
#include <iostream>
#include <functional>
#include <mutex>
// JSON
#include <nlohmann/json.hpp>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <array>
#include <cstdlib>  //strtof
// #include <string_view>
// #include <charconv> // for std::from_chars (C++17 High Performance Parsing)



// ROS 2 Headers
#include "rclcpp/rclcpp.hpp"
#include "xr_msgs/msg/custom.hpp"
#include "xr_msgs/msg/head.hpp"
#include "xr_msgs/msg/controller.hpp"
#include "geometry_msgs/msg/transform_stamped.hpp"
#include "tf2_ros/transform_broadcaster.h"

// SDK Header
#include "PXREARobotSDK.h"

using namespace std::chrono_literals;
using json = nlohmann::json;

// [안전장치 1] SDK callback의 스레드 충돌 방지를 위해 Mutex 최소 범위 사용
std::mutex g_data_mutex;

// -------------------------------------------------------------------------
// [최적화 1 & 5] 전역 콜백 및 불필요한 Mutex 제거
// g_callback은 main에서 한 번 세팅되고 변하지 않으므로 Mutex 불필요
// -------------------------------------------------------------------------
std::function<void(void* context, PXREAClientCallbackType type, int status, void* userData)> g_callback;

void callbackForwarder(void* context, PXREAClientCallbackType type, int status, void* userData) {
    if (g_callback) {
        g_callback(context, type, status, userData);
    }
}

// -------------------------------------------------------------------------
// [최적화 2] Fast Float Parser
// stringstream 대신 C++17 charconv 또는 가벼운 순회 사용.
// 포인터 산술 연산 대신 string_view와 인덱싱 활용.
// -------------------------------------------------------------------------
// [안전장치 2] C-Style 파싱 (stringstream 제거, strtof 사용)
inline bool parse_pose_safe(const std::string& input, std::array<float, 7>& out_pose) {
    if (input.empty()) return false;

    const char* ptr = input.c_str();
    char* end_ptr = nullptr;
    int index = 0;

    while (index < 7 && *ptr != '\0') {
        out_pose[index] = std::strtof(ptr, &end_ptr);
        if (ptr == end_ptr) {
            ptr++;
            continue;
        }
        ptr = end_ptr;
        if (*ptr == ',') ptr++;
        index++;
    }
    return (index >= 6);

}

// -------------------------------------------------------------------------
// [최적화 3] 정적 데이터 (상수)
// -------------------------------------------------------------------------
static const std::vector<std::string> JOINT_NAMES = {
    "pico_pelvis", "pico_left_hip", "pico_right_hip", "pico_spine1",
    "pico_left_knee", "pico_right_knee", "pico_spine2", "pico_left_ankle",
    "pico_right_ankle", "pico_spine3", "pico_left_foot", "pico_right_foot",
    "pico_neck", "pico_left_collar", "pico_right_collar", "pico_head_joint",
    "pico_left_shoulder", "pico_right_shoulder", "pico_left_elbow", "pico_right_elbow",
    "pico_left_wrist", "pico_right_wrist", "pico_left_hand", "pico_right_hand"
};

class XRNode : public rclcpp::Node
{
public:
    XRNode() : Node("xr_publisher")
    {
        // 큐 사이즈를 10 -> 1로 줄여 Latency 최적화 (오래된 데이터 버림)
        // 수정 /tf 모드를 Reliable-> BestEffort로 변경
        // tf_broadcaster_ = std::make_unique<tf2_ros::TransformBroadcaster>(*this);
        // 1. QoS 설정 (Best Effort)
        rclcpp::QoS qos_profile(10);
        qos_profile.best_effort();
        publisher_ = this->create_publisher<xr_msgs::msg::Custom>("xr_pose", qos_profile);

        // 2. 생성자에 QoS 전달
        tf_broadcaster_ = std::make_unique<tf2_ros::TransformBroadcaster>(*this);
        
        for (auto& joint_data : body_joints_data_) {
            joint_data.fill(0.0f);
        }

        // // 메모리 미리 확보 (Vector 재할당 방지)
        // tf_msg_buffer_.reserve(30);
        tf_msg_buffer_.reserve(30);
        reset_accumulation();

        RCLCPP_INFO(this->get_logger(), "========================================");
        RCLCPP_INFO(this->get_logger(), " XRNode V5: Safe Optimized Started, Best Effort TF");
        RCLCPP_INFO(this->get_logger(), "========================================");
    }

    void reset_accumulation() {
        has_head_ = false;
        has_left_controller_ = false;
        has_right_controller_ = false;
        has_body_ = false;
        // Map.clear() 대신 플래그만 내리거나 유효성 비트셋을 쓸 수 있음.
        // 여기서는 데이터 덮어쓰기 로직이므로 별도 clear 불필요.
    }

    // [최적화 4] 인라인 함수 및 참조 전달로 복사 방지
    inline void fill_transform(
        geometry_msgs::msg::TransformStamped& t,
        const std::string& child_frame_id,
        const std::array<float, 7>& pose,
        const rclcpp::Time& stamp)
    {
        t.header.stamp = stamp;
        t.header.frame_id = "map";
        t.child_frame_id = child_frame_id;

        // 좌표계 변환 (PICO -> ROS)
        // pose: [px, py, pz, qx, qy, qz, qw]
        t.transform.translation.x = -pose[2]; // -pz
        t.transform.translation.y = -pose[0]; // -px
        t.transform.translation.z =  pose[1]; // py

        t.transform.rotation.x = -pose[5]; // -qz
        t.transform.rotation.y = -pose[3]; // -qx
        t.transform.rotation.z =  pose[4]; // qy
        t.transform.rotation.w =  pose[6]; // qw
    }

    void broadcast_all_tf() {
        // [최적화 3-1] 메모리 재사용 (clear만 수행)
        tf_msg_buffer_.clear();

        rclcpp::Time stamp = this ->now();
        
        // 임시 객체 하나로 재사용
        geometry_msgs::msg::TransformStamped t_temp;

        if (has_head_) {
            fill_transform(t_temp, "pico_head", accumulated_msg_.head.pose, stamp);
            tf_msg_buffer_.push_back(t_temp);
        }
        if (has_left_controller_) {
            fill_transform(t_temp, "pico_left_controller", accumulated_msg_.left_controller.pose, stamp);
            tf_msg_buffer_.push_back(t_temp);
        }
        if (has_right_controller_) {
            fill_transform(t_temp, "pico_right_controller", accumulated_msg_.right_controller.pose, stamp);
            tf_msg_buffer_.push_back(t_temp);
        }

        // [최적화 2-1] Map 순회 대신 배열 인덱스 순회
        if (has_body_) {
            for (size_t i = 0; i < JOINT_NAMES.size(); ++i) {
                // 데이터가 유효한지(0,0,0이라도) 체크는 이미 파싱 단계에서 수행됨
                // 모든 조인트 무조건 발행 (0,0,0 포함)
                fill_transform(t_temp, JOINT_NAMES[i], body_joints_data_[i], stamp);
                tf_msg_buffer_.push_back(t_temp);
            }
        }

        if (tf_msg_buffer_.size() >= 7) {
            tf_broadcaster_->sendTransform(tf_msg_buffer_);
        }
    }

    void OnPXREAClientCallback(void* context, PXREAClientCallbackType type, int status, void* userData) 
    {   // [안전장치 3] 스레드 보호
        std::lock_guard<std::mutex> lock(g_data_mutex);

        (void)context;
        (void)status;
        // 매우 빠른 리턴 조건
        if (type != PXREADeviceStateJson) return;

        auto& dsj = *((PXREADevStateJson*)userData);
        
        try {
            // [최적화 4-1] json::parse의 오버헤드는 피할 수 없으나,
            // 결과 객체를 const reference로 받아 불필요한 복사 방지
            auto json_root = json::parse(dsj.stateJson, nullptr, false); // false = 예외 안던짐
            if (json_root.is_discarded() || !json_root.contains("value")) return;

            // value 문자열 추출 (여기서 string 복사는 어쩔 수 없음)
            std::string value_str = json_root["value"].get<std::string>();
            // [최적화 4-2] 내부 JSON 파싱
            auto value_obj = json::parse(value_str, nullptr, false);
            if (value_obj.is_discarded()) return;

            // Timestamp (디버깅용으로 메시지엔 넣되, TF에는 쓰지 않음)
            if(value_obj.contains("timeStampNs")) {
                accumulated_msg_.timestamp_ns = value_obj["timeStampNs"].get<uint64_t>();
            } else {
                accumulated_msg_.timestamp_ns = this->now().nanoseconds();
            }

            if (value_obj.contains("Input")) accumulated_msg_.input = value_obj["Input"].get<int>();

            // 1. Head Parsing
            if (value_obj.contains("Head")) {
                auto& head_j = value_obj["Head"];
                if (head_j.contains("pose")) {
                    if (parse_pose_safe(head_j["pose"].get<std::string>(), accumulated_msg_.head.pose)) {
                        accumulated_msg_.head.status = head_j.value("status", 0);
                        has_head_ = true;
                    }
                }
            }

            // 2. Controller Parsing
            if (value_obj.contains("Controller")) {
                for (auto& element : value_obj["Controller"].items()) {
                    auto& ctrl_j = element.value();                    
                    xr_msgs::msg::Controller* target_msg = nullptr;
                    if (element.key() == "left") {
                        target_msg = &accumulated_msg_.left_controller;
                        has_left_controller_ = true;
                    } else {
                        target_msg = &accumulated_msg_.right_controller;
                        has_right_controller_ = true;
                    }

                    target_msg->axis_x = ctrl_j.value("axisX", 0.0f);
                    target_msg->axis_y = ctrl_j.value("axisY", 0.0f);
                    target_msg->axis_click = ctrl_j.value("axisClick", false);
                    target_msg->gripper = ctrl_j.value("grip", 0.0f);
                    target_msg->trigger = ctrl_j.value("trigger", 0.0f);
                    target_msg->primary_button = ctrl_j.value("primaryButton", false);
                    target_msg->secondary_button = ctrl_j.value("secondaryButton", false);
                    target_msg->menu_button = ctrl_j.value("menuButton", false);
                    target_msg->status = 3;

                    if (ctrl_j.contains("pose")) {
                        std::string pose_str = ctrl_j["pose"].get<std::string>();
                        parse_pose_safe(pose_str, target_msg->pose);
                        // 파싱 실패해도 0,0,0 상태로 전송 (기존 로직 유지)
                    }
                }
            }

            // 3. Body Parsing [최적화 핵심 구간]
            if (value_obj.contains("Body")) {
                auto body_j = value_obj["Body"];
                if (body_j.contains("joints")) {
                    auto joints_j = body_j["joints"];
                    size_t limit = std::min(joints_j.size(), JOINT_NAMES.size());
                    for (size_t i = 0; i < limit; ++i){
                        if (joints_j[i].contains("p")) {
                            // std::string pose_str = joints_j[i]["p"].get<std::string>();
                            // Map 검색 없이 배열 인덱스(i)에 바로 저장
                            parse_pose_safe(joints_j[i]["p"].get<std::string>(), body_joints_data_[i]);
                        }
                    }
                    
                    if (limit > 0) has_body_ = true;
                }
            }

            // 전송 조건: Head와 Body가 있으면 전송
            if (has_head_ && has_body_) {
                publisher_->publish(accumulated_msg_);
                broadcast_all_tf();
                reset_accumulation();
            }

        } catch (const std::exception& e) {
            // 운영 환경에서는 에러 로그도 최소화 (Latency 원인)
            //  std::cerr << "E" << std::endl; 
        }
    }

private:
    rclcpp::Publisher<xr_msgs::msg::Custom>::SharedPtr publisher_;
    std::unique_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;

    xr_msgs::msg::Custom accumulated_msg_;
    // uint64_t current_frame_timestamp_ = 0;

    bool has_head_ = false;
    bool has_left_controller_ = false;
    bool has_right_controller_ = false;
    bool has_body_ = false;

    // [최적화 2-2] Map 대신 고정 배열 사용
    std::array<std::array<float, 7>, 24> body_joints_data_;
    
    // [최적화 3-2] 재사용을 위한 멤버 변수 버퍼
    std::vector<geometry_msgs::msg::TransformStamped> tf_msg_buffer_;
};

int main(int argc, char * argv[])
{
    // ROS 통신 최적화 옵션 검토 가능 (Intra-process comm 등)
    rclcpp::init(argc, argv);
    auto xrNode = std::make_shared<XRNode>();

    g_callback = [&xrNode] (void* context, PXREAClientCallbackType type, int status, void* userData) {
        xrNode->OnPXREAClientCallback(context, type, status, userData);
    };

    PXREAInit(NULL, callbackForwarder, PXREAFullMask);
    rclcpp::spin(xrNode);
    PXREADeinit();
    rclcpp::shutdown();
    return 0;
}