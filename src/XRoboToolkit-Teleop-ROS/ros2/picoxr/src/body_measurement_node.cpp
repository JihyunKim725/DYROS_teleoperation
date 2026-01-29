/**
 * @file body_measurement_node.cpp
 * @brief PICO XR TF 데이터를 구독하여 신체 치수(키, 팔 길이, 어깨 너비 등)를 측정하는 노드
 * @author Kim Jihyun (Request) / Gemini (Generation)
 */

#include <chrono>
#include <memory>
#include <string>
#include <cmath>
#include <iostream>
#include <vector>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/transform_stamped.hpp"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp" // tf2::doTransform 등 사용 시 필요

using namespace std::chrono_literals;

class BodyMeasurementNode : public rclcpp::Node
{
public:
    BodyMeasurementNode() : Node("body_measurement_node")
    {
        // 1. TF Buffer & Listener 초기화
        tf_buffer_ = std::make_unique<tf2_ros::Buffer>(this->get_clock());
        tf_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);

        // 2. 타이머 설정 (1Hz - 1초에 한 번 측정 및 출력)
        timer_ = this->create_wall_timer(
            1000ms, std::bind(&BodyMeasurementNode::timer_callback, this));

        RCLCPP_INFO(this->get_logger(), "Body Measurement Node Started.");
        RCLCPP_INFO(this->get_logger(), "Waiting for TF data from 'publisher.cpp'...");
    }

private:
    void timer_callback()
    {
        // 측정할 프레임 목록 정의
        // [Key Point] map을 기준(Parent)으로 각 관절의 절대 좌표를 조회함
        std::string base_frame = "map";

        try {
            // --- 1. 데이터 조회 (Lookup Transform) ---
            // lookupTransform(target_frame, source_frame, time)
            // source(map)에서 봤을 때 target(body part)의 위치
            auto tf_head = tf_buffer_->lookupTransform(base_frame, "pico_head", tf2::TimePointZero);
            auto tf_pelvis = tf_buffer_->lookupTransform(base_frame, "pico_pelvis", tf2::TimePointZero);
            auto tf_spine3 = tf_buffer_->lookupTransform(base_frame, "pico_spine3", tf2::TimePointZero);
            
            auto tf_l_shoulder = tf_buffer_->lookupTransform(base_frame, "pico_left_shoulder", tf2::TimePointZero);
            auto tf_r_shoulder = tf_buffer_->lookupTransform(base_frame, "pico_right_shoulder", tf2::TimePointZero);
            
            auto tf_l_hand = tf_buffer_->lookupTransform(base_frame, "pico_left_hand", tf2::TimePointZero);
            auto tf_r_hand = tf_buffer_->lookupTransform(base_frame, "pico_right_hand", tf2::TimePointZero);

            // 발 데이터는 선택적 (없으면 0으로 가정하거나 예외 처리)
            // 여기서는 안전하게 존재 여부 체크는 try-catch로 넘김
            auto tf_l_foot = tf_buffer_->lookupTransform(base_frame, "pico_left_foot", tf2::TimePointZero);
            auto tf_r_foot = tf_buffer_->lookupTransform(base_frame, "pico_right_foot", tf2::TimePointZero);


            // --- 2. 치수 계산 (Measurements) ---

            // A. 키 (Height): 머리 Z - 발 평균 Z
            // (발이 바닥에 닿아있지 않더라도, 현재 머리와 발 사이의 수직 거리를 키로 간주)
            double foot_avg_z = (tf_l_foot.transform.translation.z + tf_r_foot.transform.translation.z) / 2.0;
            double height = tf_head.transform.translation.z - foot_avg_z;

            // B. 어깨 너비 (Shoulder Width): 왼쪽 어깨 ~ 오른쪽 어깨 거리
            double shoulder_width = calculate_distance(tf_l_shoulder, tf_r_shoulder);

            // C. 팔 길이 (Arm Length): 어깨 ~ 손 (좌/우)
            double l_arm_len = calculate_distance(tf_l_shoulder, tf_l_hand);
            double r_arm_len = calculate_distance(tf_r_shoulder, tf_r_hand);

            // D. 상체 길이 (Torso): Spine3 ~ Pelvis
            // (척추 라인을 따라가는 것이 정확하나, 두 점 사이의 직선 거리로 근사)
            double torso_len = calculate_distance(tf_spine3, tf_pelvis);


            // --- 3. 결과 출력 (Logging) ---
            print_result("Height (Head-Foot)", height);
            print_result("Shoulder Width", shoulder_width);
            print_result("Left Arm (Shoulder-Hand)", l_arm_len);
            print_result("Right Arm (Shoulder-Hand)", r_arm_len);
            print_result("Torso (Spine3-Pelvis)", torso_len);
            RCLCPP_INFO(this->get_logger(), "------------------------------------------------");

        } catch (const tf2::TransformException & ex) {
            // TF 트리가 아직 완성되지 않았거나, 데이터가 들어오지 않을 때
            RCLCPP_WARN(this->get_logger(), "Could not transform: %s", ex.what());
        }
    }

    // [Helper] 두 Transform 사이의 유클리드 거리 계산 함수
    double calculate_distance(const geometry_msgs::msg::TransformStamped& t1, 
                              const geometry_msgs::msg::TransformStamped& t2)
    {
        double dx = t1.transform.translation.x - t2.transform.translation.x;
        double dy = t1.transform.translation.y - t2.transform.translation.y;
        double dz = t1.transform.translation.z - t2.transform.translation.z;
        
        return std::sqrt(dx*dx + dy*dy + dz*dz);
    }

    // [Helper] 출력 포맷팅
    void print_result(const std::string& label, double value) {
        // 미터(m) 단위를 센티미터(cm)로 변환하여 보기 좋게 출력
        RCLCPP_INFO(this->get_logger(), "%-25s : %.2f cm (%.4f m)", label.c_str(), value * 100.0, value);
    }

    std::shared_ptr<tf2_ros::TransformListener> tf_listener_{nullptr};
    std::unique_ptr<tf2_ros::Buffer> tf_buffer_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<BodyMeasurementNode>());
    rclcpp::shutdown();
    return 0;
}