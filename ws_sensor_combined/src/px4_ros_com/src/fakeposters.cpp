#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/pose_array.hpp>
#include <geometry_msgs/msg/point.hpp>
#include <cmath>
#include <chrono>

using namespace std::chrono_literals;

class PosterPublisher : public rclcpp::Node {
public:
  PosterPublisher() : Node("poster_publisher"), angle_(0.0) {
    poster_publisher_ = this->create_publisher<geometry_msgs::msg::PoseArray>("current_posters", 10);
    tom_publisher_ = this->create_publisher<geometry_msgs::msg::Point>("/Tom", 10);

    // Timer for posters
    poster_timer_ = this->create_wall_timer(
      1000ms,
      std::bind(&PosterPublisher::poster_timer_callback, this));

    // Timer for Tom
    tom_timer_ = this->create_wall_timer(
      50ms, // Adjust if needed for resolution/smoothness of motion
      std::bind(&PosterPublisher::tom_timer_callback, this));
  }

  void poster_timer_callback() {
    std::vector<std::vector<float>> poster_positions = {
      // Manually specify the XYZ positions for each of the 16 posters
      {13.5, 3.0, 3.5},   // Poster 1
      {13.5, 9.0, 3.5},   // Poster 2
      //{13.5, 15.0, 3.5},  // Poster 3
      {13.5, -3.0, 3.5},  // Poster 4
      {13.5, -9.0, 3.5},  // Poster 5
      //{13.5, -15.0, 3.5}, // Poster 6
      {-11.5, 3.0, 3.5},  // Poster 7
      {-11.5, 9.0, 3.5},  // Poster 8
      //{-11.5, 15.0, 3.5}, // Poster 9
      {-11.5, -3.0, 3.5}, // Poster 10
      {-11.5, -9.0, 3.5}, // Poster 11
      //{-11.5, -15.0, 3.5},// Poster 12
      {6, 19.0, 3.5},     // Poster 13
      {6, -17.0, 3.5},    // Poster 14
      {-6, 19.0, 3.5},    // Poster 15
      {-6, -17.0, 3.5}    // Poster 16
    };

    // Create and populate the PoseArray message
    geometry_msgs::msg::PoseArray pose_array_msg;
    pose_array_msg.header.stamp = this->get_clock()->now();
    pose_array_msg.header.frame_id = "map";

    for (const auto& position : poster_positions) {
      geometry_msgs::msg::Pose pose;
      pose.position.x = position[0];
      pose.position.y = position[1];
      pose.position.z = position[2];
      
      // The orientation is not used, so we just set w to 1.0 for a valid quaternion
      pose.orientation.w = 1.0;

      pose_array_msg.poses.push_back(pose);
    }

    // Publish the PoseArray message
    poster_publisher_->publish(pose_array_msg);
    RCLCPP_INFO(this->get_logger(), "Published poster positions");
  }

  void tom_timer_callback() {
    // Calculate the next position in the circle for Tom
    angle_ += 2.0 * M_PI / (30s / 50ms);

    if (angle_ > 2.0 * M_PI) {
      angle_ -= 2.0 * M_PI; // Reset the angle after a full circle
    }
    
    double x = std::cos(angle_) * 8.0;
    double y = std::sin(angle_) * 8.0;

    geometry_msgs::msg::Point tom_point;
    tom_point.x = x;
    tom_point.y = y;
    tom_point.z = 3.5; // Z is always 3.5

    // Publish the Point message for Tom
    tom_publisher_->publish(tom_point);
  }

private:
  rclcpp::Publisher<geometry_msgs::msg::PoseArray>::SharedPtr poster_publisher_;
  rclcpp::Publisher<geometry_msgs::msg::Point>::SharedPtr tom_publisher_;
  rclcpp::TimerBase::SharedPtr poster_timer_;
  rclcpp::TimerBase::SharedPtr tom_timer_;
  double angle_;
};

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<PosterPublisher>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}