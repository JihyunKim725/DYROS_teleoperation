#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <visualization_msgs/msg/marker_array.hpp>
#include <nlohmann/json.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using json = nlohmann::json;
using namespace std::chrono_literals;

class PicoBridge : public rclcpp::Node {
public:
    PicoBridge() : Node("pico_bridge") {
        // Publishers
        head_pub_ = this->create_publisher<geometry_msgs::msg::PoseStamped>("/pico/head_pose", 10);
        left_ctrl_pub_ = this->create_publisher<geometry_msgs::msg::PoseStamped>("/pico/controller/left_controller", 10);
        right_ctrl_pub_ = this->create_publisher<geometry_msgs::msg::PoseStamped>("/pico/controller/right_controller", 10);
        body_pub_ = this->create_publisher<visualization_msgs::msg::MarkerArray>("/pico/body_joints", 10);

        RCLCPP_INFO(this->get_logger(), "Pico Bridge Node Started. Waiting for JSON data on STDIN...");
    }

    void process_line(const std::string& line) {
        // Look for the prefix [DATA RECEIVED]
        std::string prefix = "[DATA RECEIVED] ";
        size_t prefix_pos = line.find(prefix);
        if (prefix_pos == std::string::npos) {
            return; 
        }

        std::string json_part = line.substr(prefix_pos + prefix.length());
        try {
            parse_and_publish(json_part);
        } catch (const std::exception& e) {
            RCLCPP_ERROR(this->get_logger(), "JSON Parse Error: %s", e.what());
        }
    }

private:
    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr head_pub_;
    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr left_ctrl_pub_;
    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr right_ctrl_pub_;
    rclcpp::Publisher<visualization_msgs::msg::MarkerArray>::SharedPtr body_pub_;

    std::vector<double> parse_pose_str(const std::string& s) {
        std::vector<double> v;
        std::stringstream ss(s);
        std::string token;
        while(std::getline(ss, token, ',')) {
            try { v.push_back(std::stod(token)); } catch(...) {}
        }
        return v;
    }

    geometry_msgs::msg::Pose create_pose_msg(const std::vector<double>& v) {
        geometry_msgs::msg::Pose p;
        if (v.size() >= 7) {
            // Coordinate Conversion: Unity to ROS
            // Unity: X-Right, Y-Up, Z-Forward (Left Handed)
            // ROS: X-Forward, Y-Left, Z-Up (Right Handed)
            
            // Pos: ROS(x,y,z) = Unity(-z, -x, y)
            p.position.x = -v[2];
            p.position.y = -v[0];
            p.position.z = v[1];

            // Rot: ROS(x,y,z,w) = Unity(-z, -x, y, w) ... double check mapping
            // From previous analysis:
            // ROS qx = -qz
            // ROS qy = -qx
            // ROS qz = qy
            // ROS qw = qw
            p.orientation.x = -v[5];
            p.orientation.y = -v[3];
            p.orientation.z = v[4];
            p.orientation.w = v[6];
        }
        return p;
    }

    void parse_and_publish(const std::string& json_str) {
        auto outer = json::parse(json_str);
        if (!outer.contains("value")) return;

        std::string value_str = outer["value"].get<std::string>();
        auto payload = json::parse(value_str);

        // Header timestamp
        rclcpp::Time timestamp = this->now(); // Use current ROS time for simplicity in sync
        if (payload.contains("timeStampNs")) {
            // Optional: Use PICO time if synchronized
            // uint64_t ns = payload["timeStampNs"].get<uint64_t>();
        }

        // 1. Head
        if (payload.contains("Head")) {
            auto head_j = payload["Head"];
            if (head_j.contains("pose")) {
                auto v = parse_pose_str(head_j["pose"].get<std::string>());
                auto msg = std::make_unique<geometry_msgs::msg::PoseStamped>();
                msg->header.stamp = timestamp;
                msg->header.frame_id = "map";
                msg->pose = create_pose_msg(v);
                head_pub_->publish(std::move(msg));
            }
        }

        // 2. Controllers
        if (payload.contains("Controller")) {
            auto ctrl_j = payload["Controller"];
            if (ctrl_j.contains("left")) {
                 auto v = parse_pose_str(ctrl_j["left"]["pose"].get<std::string>());
                 auto msg = std::make_unique<geometry_msgs::msg::PoseStamped>();
                 msg->header.stamp = timestamp;
                 msg->header.frame_id = "map";
                 msg->pose = create_pose_msg(v);
                 left_ctrl_pub_->publish(std::move(msg));
            }
            if (ctrl_j.contains("right")) {
                 auto v = parse_pose_str(ctrl_j["right"]["pose"].get<std::string>());
                 auto msg = std::make_unique<geometry_msgs::msg::PoseStamped>();
                 msg->header.stamp = timestamp;
                 msg->header.frame_id = "map";
                 msg->pose = create_pose_msg(v);
                 right_ctrl_pub_->publish(std::move(msg));
            }
        }

        // 3. Body
        if (payload.contains("Body") && payload["Body"].contains("joints")) {
            visualization_msgs::msg::MarkerArray markers;
            auto joints = payload["Body"]["joints"];
            int id = 0;
            for (const auto& j : joints) {
                if (j.contains("p")) {
                    auto v = parse_pose_str(j["p"].get<std::string>());
                    visualization_msgs::msg::Marker m;
                    m.header.frame_id = "map";
                    m.header.stamp = timestamp;
                    m.ns = "pico_body";
                    m.id = id++;
                    m.type = visualization_msgs::msg::Marker::SPHERE;
                    m.action = visualization_msgs::msg::Marker::ADD;
                    m.scale.x = 0.05; m.scale.y = 0.05; m.scale.z = 0.05;
                    m.color.a = 1.0; m.color.r = 0.0; m.color.g = 1.0; m.color.b = 0.0;
                    m.pose = create_pose_msg(v);
                    markers.markers.push_back(m);
                }
            }
            body_pub_->publish(markers);
        }
    }
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<PicoBridge>();

    // Non-blocking stdin check loop
    // In a real scenario, consider a separate thread for stdin reading
    std::string line;
    while (rclcpp::ok()) {
        if (std::getline(std::cin, line)) {
            node->process_line(line);
        } else {
            // End of stream
            rclcpp::spin_some(node);
            std::this_thread::sleep_for(10ms);
            // Don't break immediately if stdin closes, technically usually means end of process, 
            // but we might want to keep spinning? 
            // If the pipe closes, we should probably exit.
            break;
        }
        rclcpp::spin_some(node);
    }

    rclcpp::shutdown();
    return 0;
}
