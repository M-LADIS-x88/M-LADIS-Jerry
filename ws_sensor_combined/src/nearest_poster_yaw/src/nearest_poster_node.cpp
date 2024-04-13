#include <functional>
#include <memory>
#include <cmath>
#include <limits>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_array.hpp"
//#include "geometry_msgs/msg/vector3.hpp"
#include "std_msgs/msg/float64.hpp"
#include "geometry_msgs/msg/point.hpp"

class PosterDetector : public rclcpp::Node {
public:
    PosterDetector()
    : Node("poster_detector") {
        // Set up subscriber for the object_detection topic
        posters_subscriber_ = this->create_subscription<geometry_msgs::msg::PoseArray>(
            "/posters",
            1,
            std::bind(&PosterDetector::objectDetectionCallback, this, std::placeholders::_1));

        // Set up subscriber for the position topic
        position_subscriber_ = this->create_subscription<geometry_msgs::msg::Point>(
            "/position",
            1,
            std::bind(&PosterDetector::positionCallback, this, std::placeholders::_1));

        // Set up publisher for the poster_yaw topic
        poster_yaw_publisher_ = this->create_publisher<std_msgs::msg::Float64>(
            "/poster_yaw",
            1);

        // Set up publisher for the poster_point topic
        poster_point_publisher_ = this->create_publisher<geometry_msgs::msg::Point>(
            "/poster_point",
            1);

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
        float range = 10;
        geometry_msgs::msg::Point nearest_poster_point; // Point to store the nearest poster info
        nearest_poster_point.z = 0; // Set default to out of range

        for (size_t i = 0; i < updated_msg.poses.size(); ++i) {
            const auto& pose = updated_msg.poses[i];
            
            if (pose.orientation.w == 0.0) { // If poster is not classified
                double dx = pose.position.x - current_position_.x;
                double dy = pose.position.y - current_position_.y;
                double distance = std::hypot(dx, dy);

                if (distance < closest_distance) {
                    closest_distance = distance;
                    target_angle = std::atan2(dy, dx); // Compute angle
                    target_found = true;

                    nearest_poster_point.x = pose.position.x;
                    nearest_poster_point.y = pose.position.y;
                    nearest_poster_point.z = closest_distance <= range ? 1.0 : 0.0; // Set z field based on range check
                }
            }
        }

        if (target_found) {
            std_msgs::msg::Float64 angle_msg;
            angle_msg.data = target_angle;
            poster_yaw_publisher_->publish(angle_msg); // Publish angle

            poster_point_publisher_->publish(nearest_poster_point); // Publish the point
        } 
        else {
            RCLCPP_INFO(this->get_logger(), "No unclassified poster found.");
        }
    }

    void positionCallback(const geometry_msgs::msg::Point::SharedPtr msg) {
        // Update current position (z not used)
        current_position_.x = msg->x;
        current_position_.y = msg->y;
    }

    geometry_msgs::msg::Point current_position_;
    rclcpp::Subscription<geometry_msgs::msg::PoseArray>::SharedPtr posters_subscriber_;
    rclcpp::Subscription<geometry_msgs::msg::Point>::SharedPtr position_subscriber_;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr poster_yaw_publisher_;
    rclcpp::Publisher<geometry_msgs::msg::Point>::SharedPtr poster_point_publisher_; // Publisher for Point message
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<PosterDetector>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
