#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/bool.hpp>
#include <geometry_msgs/msg/pose_array.hpp>
#include <chrono>
#include <memory>

using std::placeholders::_1;

class PoseArrayPublisher : public rclcpp::Node {
public:
    PoseArrayPublisher() : Node("pose_array_publisher_node") {
        // Publishers
        end_flight_publisher_ = this->create_publisher<std_msgs::msg::Bool>("/end_flight", 10);
        posters_publisher_ = this->create_publisher<geometry_msgs::msg::PoseArray>("/posters", 10);

        // Timers
        publish_timer_ = this->create_wall_timer(
            std::chrono::seconds(1),
            std::bind(&PoseArrayPublisher::publishPoseArray, this));

        end_flight_timer_ = this->create_wall_timer(
            std::chrono::seconds(10),
            std::bind(&PoseArrayPublisher::publishEndFlight, this));
    }

private:
    rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr end_flight_publisher_;
    rclcpp::Publisher<geometry_msgs::msg::PoseArray>::SharedPtr posters_publisher_;
    rclcpp::TimerBase::SharedPtr publish_timer_;
    rclcpp::TimerBase::SharedPtr end_flight_timer_;

    void publishPoseArray() {
        auto pose_array_msg = geometry_msgs::msg::PoseArray();
        pose_array_msg.header.stamp = this->now();
        pose_array_msg.header.frame_id = "world";

        for (int i = 0; i < 5; ++i) {
            geometry_msgs::msg::Pose pose;
            pose.position.x = i; // Any x, y, z values
            pose.position.y = i * 2;
            pose.position.z = i * 3;
            pose.orientation.w = (i < 3) ? 1.0 : 0.0;

            pose_array_msg.poses.push_back(pose);
        }

        posters_publisher_->publish(pose_array_msg);
    }

    void publishEndFlight() {
        auto end_flight_msg = std_msgs::msg::Bool();

        // Initially, publish "false"
        end_flight_msg.data = false;
        end_flight_publisher_->publish(end_flight_msg);

        // Wait for 10 seconds
        rclcpp::sleep_for(std::chrono::seconds(10));

        // After 10 seconds, publish "true"
        end_flight_msg.data = true;
        end_flight_publisher_->publish(end_flight_msg);

        // After sending 'true', we shutdown the timers to act only once
        publish_timer_->cancel();
        end_flight_timer_->cancel();
    }
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PoseArrayPublisher>());
    rclcpp::shutdown();
    return 0;
}