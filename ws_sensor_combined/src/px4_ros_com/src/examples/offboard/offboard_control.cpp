/****************************************************************************
 *
 * Copyright 2020 PX4 Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors
 * may be used to endorse or promote products derived from this software without
 * specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/**
 * @brief Offboard control example
 * @file offboard_control.cpp
 * @addtogroup examples
 * @author Mickey Cowden <info@cowden.tech>
 * @author Nuno Marques <nuno.marques@dronesolutions.io>
 */

#include <px4_msgs/msg/offboard_control_mode.hpp>
#include <px4_msgs/msg/trajectory_setpoint.hpp>
#include <px4_msgs/msg/vehicle_command.hpp>
#include <px4_msgs/msg/vehicle_control_mode.hpp>

#include <rclcpp/rclcpp.hpp>
#include <stdint.h>

#include <chrono>
#include <iostream>

using namespace std::chrono;
using namespace std::chrono_literals;
using namespace px4_msgs::msg;

struct WaypointInfo {
    float x;
    float y;
    float z;
    float yaw;
};


class OffboardControl : public rclcpp::Node
{
public:
	OffboardControl() : Node("offboard_control")
	{

		offboard_control_mode_publisher_ = this->create_publisher<OffboardControlMode>("/fmu/in/offboard_control_mode", 10);
		trajectory_setpoint_publisher_ = this->create_publisher<TrajectorySetpoint>("/fmu/in/trajectory_setpoint", 10);
		vehicle_command_publisher_ = this->create_publisher<VehicleCommand>("/fmu/in/vehicle_command", 10);
		
		x=0.0;;
		y=0.0;
		z=0.0;
		yaw=0.0;
		
		//flight_trajectory_waypoint_ = this->create_subscription<TrajectorySetpoint>("/fmu/in/autonomy_waypoint",10);
		flight_trajectory_waypoint_ = this->create_subscription<TrajectorySetpoint>(
    		"/fmu/in/autonomy_waypoint",10, [this](const px4_msgs::msg::TrajectorySetpoint::SharedPtr msg) {
        		//WaypointInfo waypoint = WaypointMsgCallback(msg);
        		handle_trajectory_waypoint(msg);
        		
		});
		
		offboard_setpoint_counter_ = 0;
		
		//const px4_msgs::msg::TrajectorySetpoint::SharedPtr msg

		auto timer_callback = [this]() -> void {
		

			if (offboard_setpoint_counter_ == 10) {
				// Change to Offboard mode after 10 setpoints
				this->publish_vehicle_command(VehicleCommand::VEHICLE_CMD_DO_SET_MODE, 1, 6);

				// Arm the vehicle
				this->arm();
			}
			
			
			
			// offboard_control_mode needs to be paired with trajectory_setpoint
			publish_offboard_control_mode();
			// publish_trajectory_setpoint();
			
			
			publish_trajectory_setpoint_forward(); // my own thing

			// stop the counter after reaching 11
			if (offboard_setpoint_counter_ < 11) {
				offboard_setpoint_counter_++;
			}
		};
		timer_ = this->create_wall_timer(100ms, timer_callback);
		//timer_ = this->create_wall_timer(100ms, std::bind(timer_callback, std::placeholders::_1));

	}

	void arm();
	void disarm();

private:

	float x;
	float y;
	float z;
	float yaw;
	rclcpp::TimerBase::SharedPtr timer_;
	
	rclcpp::Publisher<OffboardControlMode>::SharedPtr offboard_control_mode_publisher_;
	rclcpp::Publisher<TrajectorySetpoint>::SharedPtr trajectory_setpoint_publisher_;
	rclcpp::Publisher<VehicleCommand>::SharedPtr vehicle_command_publisher_;
	
	rclcpp::Subscription<TrajectorySetpoint>::SharedPtr flight_trajectory_waypoint_;

	std::atomic<uint64_t> timestamp_;   //!< common synced timestamped
	uint64_t offboard_setpoint_counter_;   //!< counter for the number of setpoints sent

	void publish_offboard_control_mode();
	// void publish_trajectory_setpoint();
	
	//void publish_trajectory_setpoint_forward();//my own thing
	
	void publish_vehicle_command(uint16_t command, float param1 = 0.0, float param2 = 0.0);
	//void handle_trajectory_waypoint(const px4_msgs::msg::TrajectorySetpoint::SharedPtr msg);
	
	struct WaypointInfo{};
	WaypointInfo WaypointMsgCallback();
	
	
	//Trying my own thing below:
	void handle_trajectory_waypoint(const px4_msgs::msg::TrajectorySetpoint::SharedPtr msg)
    {
        x = msg->position[0];
        y = msg->position[1];
        z = msg->position[2];
        yaw = msg->yaw;	

        // Do something with the trajectory waypoint data
    }


	void publish_trajectory_setpoint_forward()
{
	TrajectorySetpoint msg{};
	msg.position = {-y, -x, -z};
	msg.yaw = yaw; // [-PI:PI]
	msg.timestamp = this->get_clock()->now().nanoseconds() / 1000;
	trajectory_setpoint_publisher_->publish(msg);
}

};

/**
 * @brief Send a command to Arm the vehicle
 */
void OffboardControl::arm()
{
	publish_vehicle_command(VehicleCommand::VEHICLE_CMD_COMPONENT_ARM_DISARM, 1.0);

	RCLCPP_INFO(this->get_logger(), "Arm command send");
}

/**
 * @brief Send a command to Disarm the vehicle
 */
void OffboardControl::disarm()
{
	publish_vehicle_command(VehicleCommand::VEHICLE_CMD_COMPONENT_ARM_DISARM, 0.0);

	RCLCPP_INFO(this->get_logger(), "Disarm command send");
}

/**
 * @brief Publish the offboard control mode.
 *        For this example, only position and altitude controls are active.
 */
void OffboardControl::publish_offboard_control_mode()
{
	OffboardControlMode msg{};
	msg.position = true;
	msg.velocity = false;
	msg.acceleration = false;
	msg.attitude = false;
	msg.body_rate = false;
	msg.timestamp = this->get_clock()->now().nanoseconds() / 1000;
	offboard_control_mode_publisher_->publish(msg);
}

/**
 * @brief Publish a trajectory setpoint
 *        For this example, it sends a trajectory setpoint to make the
 *        vehicle hover at 5 meters with a yaw angle of 180 degrees.
 */
//void OffboardControl::publish_trajectory_setpoint()
// {
// 	TrajectorySetpoint msg{};
// 	msg.position = {0.0, 0.0, -5.0};
// 	msg.yaw = -3.14; // [-PI:PI]
// 	msg.timestamp = this->get_clock()->now().nanoseconds() / 1000;
// 	trajectory_setpoint_publisher_->publish(msg);
// }

/**
 * @brief Publish vehicle commands
 * @param command   Command code (matches VehicleCommand and MAVLink MAV_CMD codes)
 * @param param1    Command parameter 1
 * @param param2    Command parameter 2
 */
void OffboardControl::publish_vehicle_command(uint16_t command, float param1, float param2)
{
	VehicleCommand msg{};
	msg.param1 = param1;
	msg.param2 = param2;
	msg.command = command;
	msg.target_system = 1;
	msg.target_component = 1;
	msg.source_system = 1;
	msg.source_component = 1;
	msg.from_external = true;
	msg.timestamp = this->get_clock()->now().nanoseconds() / 1000;
	vehicle_command_publisher_->publish(msg);
}




//End to my own thing

int main(int argc, char *argv[])
{
	std::cout << "Starting offboard control node..." << std::endl;
	setvbuf(stdout, NULL, _IONBF, BUFSIZ);
	rclcpp::init(argc, argv);
	rclcpp::spin(std::make_shared<OffboardControl>());

	rclcpp::shutdown();
	return 0;
}