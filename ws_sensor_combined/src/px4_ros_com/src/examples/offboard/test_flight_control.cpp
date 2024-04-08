#include <px4_msgs/msg/offboard_control_mode.hpp>
#include <px4_msgs/msg/trajectory_setpoint.hpp>
#include <px4_msgs/msg/vehicle_command.hpp>
#include <px4_msgs/msg/vehicle_control_mode.hpp>

#include <rclcpp/rclcpp.hpp>
#include <stdint.h>

#include <chrono>
#include <iostream>

using namespace std::chrono_literals;

int counter = 0;

class TrajectorySetpointPublisher : public rclcpp::Node {
public:
    TrajectorySetpointPublisher() : Node("trajectory_setpoint_publisher") {
        autonomy_waypoint_publisher_ = this->create_publisher<px4_msgs::msg::TrajectorySetpoint>(
            "/fmu/in/autonomy_waypoint", 10);

        // Set up a timer to publish messages periodically
        
        //while(counter < 4){
        timer_ = this->create_wall_timer(0.4s,
                                         std::bind(&TrajectorySetpointPublisher::publishTrajectorySetpoint, this));
        //}
        
    }

private:
    rclcpp::Publisher<px4_msgs::msg::TrajectorySetpoint>::SharedPtr autonomy_waypoint_publisher_;

    void publishTrajectorySetpoint() {
        auto message = px4_msgs::msg::TrajectorySetpoint();
        // Set other desired values for position, velocity, acceleration, jerk, yaw, and yawspeed
        if(counter <= 10){
        	message.position = {0, 0, 3.0*counter/10};
	}else if(counter <= 20){
		message.position = {5.0*(counter-10)/10, 0, 3.0};
	}else if(counter <= 30){
		message.position = {5.0, 5.0*(counter-20)/10, 3.0};
	}else if(counter <= 40){
		message.position = {5.0, 5.0, 3-3*(counter-30)/10};
	}else{
		message.position = {5.0, 5.0, 0};
	}
        message.yaw = 0.0;
        message.timestamp = this->get_clock()->now().nanoseconds() / 1000;

        RCLCPP_INFO(this->get_logger(), "Publishing autonomy_waypoint message...");

        autonomy_waypoint_publisher_->publish(message);
        
        std::cout<<counter<<std::endl;
        
        ++counter;
    }

    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    try {
        rclcpp::spin(std::make_shared<TrajectorySetpointPublisher>());
    } catch (const std::exception& e) {
        std::cerr << "Error in TrajectorySetpointPublisher: " << e.what() << std::endl;
    }

    rclcpp::shutdown();
    return 0;
}
