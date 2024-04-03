#include <functional>
#include <memory>
#include <cmath>
#include <limits>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_array.hpp"
#include "geometry_msgs/msg/vector3.hpp"
#include "std_msgs/msg/float64.hpp"
#include "std_msgs/msg/bool.hpp"

class PosterDetector : public rclcpp::Node {
public:
    PosterDetector()
    : Node("poster_detector") {
        // Set up subscriber for the object_detection topic
        object_detection_subscriber_ = this->create_subscription<geometry_msgs::msg::PoseArray>(
            "/object_detection",
            10,
            std::bind(&PosterDetector::objectDetectionCallback, this, std::placeholders::_1));

        // Set up subscriber for the position topic
        position_subscriber_ = this->create_subscription<geometry_msgs::msg::Vector3>(
            "/position",
            10,
            std::bind(&PosterDetector::positionCallback, this, std::placeholders::_1));

        // Set up publisher for the poster_yaw topic
        poster_yaw_publisher_ = this->create_publisher<std_msgs::msg::Float64>(
            "/poster_yaw",
            10);

        // Set up publisher for the take_picture topic
        take_picture_publisher_ = this->create_publisher<std_msgs::msg::Bool>(
            "/take_picture",
            10);

        // Set up publisher for the updated_posters topic
        updated_posters_publisher_ = this->create_publisher<geometry_msgs::msg::PoseArray>(
            "/updated_posters",
            10);

        // Default our position to origin
        current_position_.x = 0.0;
        current_position_.y = 0.0;
    }

private:
    void objectDetectionCallback(const geometry_msgs::msg::PoseArray::SharedPtr msg) {
        auto updated_msg = *msg; // Copy the incoming message
        double closest_distance = std::numeric_limits<double>::max();
        double target_angle = 0.0;
        bool target_found = false;
        int closest_index = -1;

        for (size_t i = 0; i < updated_msg.poses.size(); ++i) {
            const auto& pose = updated_msg.poses[i];
            
            if (pose.position.z == 0.0) { // If poster is not classified
                double dx = pose.position.x - current_position_.x;
                double dy = pose.position.y - current_position_.y;
                double distance = std::hypot(dx, dy);

                if (distance < closest_distance) {
                    closest_distance = distance;
                    target_angle = std::atan2(dy, dx); // Compute angle
                    target_found = true;
                    closest_index = i;
                }
            }
        }

        if (target_found) {
            std_msgs::msg::Float64 angle_msg;
            angle_msg.data = target_angle;
            poster_yaw_publisher_->publish(angle_msg); // Publish angle

            // Check if we should take a picture and publish on '/take_picture'
            std_msgs::msg::Bool take_picture_msg;
            take_picture_msg.data = (closest_distance <= 2.0);
            
            take_picture_publisher_->publish(take_picture_msg);

            if (take_picture_msg.data) {
                updated_msg.poses[closest_index].position.z = 1.0; // Mark the poster as 'classified'
            }
        } else {
            RCLCPP_INFO(this->get_logger(), "No unclassified poster found.");
        }
        
        // Publish the updated poses array whether or not a picture was taken
        updated_posters_publisher_->publish(updated_msg);
    }

    void positionCallback(const geometry_msgs::msg::Vector3::SharedPtr msg) {
        // Update current position (z not used)
        current_position_.x = msg->x;
        current_position_.y = msg->y;
    }

    geometry_msgs::msg::Vector3 current_position_;
    rclcpp::Subscription<geometry_msgs::msg::PoseArray>::SharedPtr object_detection_subscriber_;
    rclcpp::Subscription<geometry_msgs::msg::Vector3>::SharedPtr position_subscriber_;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr poster_yaw_publisher_;
    rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr take_picture_publisher_;
    rclcpp::Publisher<geometry_msgs::msg::PoseArray>::SharedPtr updated_posters_publisher_;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<PosterDetector>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}