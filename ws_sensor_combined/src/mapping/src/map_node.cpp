#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/bool.hpp"
#include "lidar_slam/msg/slam_command.hpp"
#include <cstdlib>
#include <string>

class EndFlightSubscriber : public rclcpp::Node
{
public:
    EndFlightSubscriber() : Node("end_flight_subscriber")
    {
        subscriber_ = this->create_subscription<std_msgs::msg::Bool>(
            "/end_flight",
            10,
            std::bind(&EndFlightSubscriber::end_flight_callback, this, std::placeholders::_1));

        publisher_ = this->create_publisher<lidar_slam::msg::SlamCommand>("/slam_command", 10);
    }

private:
    void end_flight_callback(const std_msgs::msg::Bool::SharedPtr msg)
    {
        if (msg->data)
        {
            RCLCPP_INFO(this->get_logger(), "End flight command received, saving map now...");
            save_map();
        }
    }

    void save_map()
    {
        std::string map_path = "/PATH/Map"; // Replace with actual path.

        lidar_slam::msg::SlamCommand slam_command_msg;
        slam_command_msg.command = 17;
        slam_command_msg.string_arg = map_path;

        publisher_->publish(slam_command_msg);
    }

    rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr subscriber_;
    rclcpp::Publisher<lidar_slam::msg::SlamCommand>::SharedPtr publisher_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<EndFlightSubscriber>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}