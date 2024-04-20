#!/usr/bin/env python3

import os
import numpy as np
import pandas as pd
import cv2
import math
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Point, Pose
from std_msgs.msg import Float64, Bool
from px4_msgs.msg import TrajectorySetpoint
from px4_msgs.msg import VehicleOdometry
from stable_baselines3 import PPO
from ament_index_python.packages import get_package_share_directory
from collections import OrderedDict  # Import OrderedDict here

class MLAgent(Node):
    def __init__(self):
        super().__init__('ml_agent')
        self.image_data = []
        default_bounds = [-10.0, 10.0]
        self.position = [0.0, 0.0, 0.0]  # Default position
        self.predator_position = [0.0, 0.0, 0.0]  # Default predator position
        self.poster_point = [0.0, 0.0, 0.0]  # Default poster position and 'in range' flag
        self.yaw = 0.0  # Default yaw
        self.x_range = default_bounds[1] - default_bounds[0]
        self.y_range = default_bounds[1] - default_bounds[0]
        self.velocity = [0.0, 0.0]
        self.enemy_velocity = [0.0, 0.0]
        self.new_action = [0.0, 0.0, 1.0]
        self.prev_action = [0.0, 0.0, 1.0]
        self.first_waypoint_generated = False
        self.count = 0
        self.end_flight = False
        self.waypoint = [0.0, 0.0, 0.0]
        self.waypoint_type = "null"
        self.reject = False
        self.new_tom_scare = True
        self.new_wall_collision = True
        self.tom_scare_penalty = 0
        self.df = pd.DataFrame(columns=['x', 'y', 'poster'])
        self.intermediate_waypoints = []  # store intermediate waypoints here.
        self.num_intermediate_waypoints = 20  # number of intermediate waypoints desired.
        self.current_intermediate_index = 0 

        # self.prev_action = [0.0, 0.0]

        #current_dir = os.path.dirname(os.path.abspath(__file__))
        #model_path = os.path.join("../EXAMPLE/drone_test_sample_final_2")
        model_path = "/home/blake/M-LADIS-Jerry/ws_sensor_combined/src/wpgen/EXAMPLE/drone_test_sample_final_2"
        self.model = PPO.load(model_path)

        self.csv_filepath = "/home/blake/M-LADIS-Jerry/ws_sensor_combined/src/wpgen/post_comp_scoring/image_class_data.csv"
        self.text_filepath = "/home/blake/M-LADIS-Jerry/ws_sensor_combined/src/wpgen/post_comp_scoring/tom_scare.txt"
        
        self.publisher_ = self.create_publisher(TrajectorySetpoint, '/fmu/in/autonomy_waypoint', 1)
        self.cam_publisher = self.create_publisher(Point, '/captured_poster', 1)
        
        # Subscriptions
        self.position_subscription = self.create_subscription(Point, '/position', self.position_callback, 1)
        self.predator_subscription = self.create_subscription(Point, '/Tom', self.predator_callback, 1)
        self.walls_subscription = self.create_subscription(Pose, '/walls', self.walls_callback, 1)
        self.poster_yaw_subscription = self.create_subscription(Float64, '/poster_yaw', self.poster_yaw_callback, 1)
        self.poster_point_subscription = self.create_subscription(Point, '/poster_point', self.poster_point_callback, 1)
        self.imu_subscription = self.create_subscription(VehicleOdometry, '/fmu/out/vehicle_odometry', self.imu_callback, 1)
        self.end_flight_subscription = self.create_subscription(Bool, '/end_flight', self.end_flight_callback, 1)


        self.timer_generate_action = self.create_timer(1.0, self.generate_action)
        self.timer_push_waypoint = self.create_timer(0.25, self.push_waypoint)

    def end_flight_callback(self, msg: Bool):
        self.end_flight = msg.data
        if self.end_flight:
            self.df.to_csv(self.csv_filepath, index=False)
            with open(self.text_file_path, 'w') as file:
            # Write the string to the file
                file.write(f'Tom scare penalty (subtract this value from 100): {self.tom_scare_penalty}')
            self.get_logger().info('End flight received. Preparing to land.')
            
    def position_callback(self, msg):
        self.position = [msg.x, msg.y, msg.z]
        #self.get_logger().info('jerry_x={}, jerry_y={}, jerry_z={}'.format(self.position[0],self.position[1],self.position[2]))

    def predator_callback(self, msg):
        self.enemy_velocity = [msg.x - self.predator_position[0], msg.y - self.predator_position[1]]
        self.predator_position = [msg.x, msg.y, msg.z]
        #self.get_logger().info(f'tom_x={self.predator_position[0]}, tom_y={self.predator_position[1]}, tom_z={self.predator_position[2]}')

    def walls_callback(self, msg):
        self.x_range = abs(msg.orientation.x - msg.position.x)
        self.y_range = abs(msg.orientation.y - msg.position.y)
        self.get_logger().info(f'x_width={self.x_range}, y_length={self.y_range}')

    def poster_yaw_callback(self, msg):
        self.yaw = msg.data
        self.get_logger().info(f'Yaw to nearest poster: {self.yaw}')

    def poster_point_callback(self, msg):
        self.poster_point = [msg.x, msg.y, msg.z]
        if msg.z == 1:  # Check if in range to take a photo
            self.get_logger().info('In Range')
            self.take_photo_and_publish_poster(msg.x, msg.y)
        else:
            self.get_logger().info('Out of Range')
            
    def imu_callback(self, msg):
        self.velocity = [msg.velocity[0], msg.velocity[1]]
        #self.get_logger().info('jerry_vx={}, jerry_vy={}'.format(self.velocity[0],self.velocity[1]))


    def take_photo_and_publish_poster(self, x, y):
        image_name = f"image_{len(self.image_data)}.jpg"
        self.capture_image(image_name)
        entry = (x, y, image_name)
        self.image_data.append(entry)                
        # After saving the photo, publish the poster's location
        point_msg = Point(x=x, y=y)
        self.cam_publisher.publish(point_msg)
        self.get_logger().info(f'Published captured poster at x: {x}, y: {y}')
        new_row = {'x': round(x, 2), 'y': round(y, 2), 'poster': image_name}
        self.df.loc[len(self.df)] = new_row
        

    def capture_image(self, image_name):
        if not os.path.exists('test_images'):
            os.makedirs('test_images')

        # Assuming the webcam device number is 0
        cap = cv2.VideoCapture(0)
        if cap.isOpened():
            ret, frame = cap.read()
            if ret:
                image_path = os.path.join('test_images', image_name)
                cv2.imwrite(image_path, frame)
                self.get_logger().info(f"Image saved to {image_path}")
                cap.release()
                return True
        cap.release()
        return False
    
    def normalize_position(self, pos, x_range, y_range):
        x_half, y_half = abs(x_range) / 2.0, abs(y_range) / 2.0
        return [
            (pos[0] / x_half) if x_half else 0.0,
            (pos[1] / y_half) if y_half else 0.0
        ]
    def calculate_intermediate_waypoints(self, start, end, steps):
        waypoints = []
        for i in range(1, steps + 1):
            ratio = i / float(steps)
            waypoint = [start[0] + ratio * (end[0] - start[0]),
                        start[1] + ratio * (end[1] - start[1]),
                        start[2] + ratio * (end[2] - start[2])]  # Assuming a fixed z altitude
            waypoints.append(waypoint)
        return waypoints

    def generate_action(self):
        if self.end_flight:  # Do nothing more if end_flight flag is set
            return
        
        else: # Else, generate ML action            
            normalized_position = self.normalize_position(self.position, self.x_range, self.y_range)
            normalized_predator = self.normalize_position(self.predator_position, self.x_range, self.y_range)
            normalized_poster = self.normalize_position(self.poster_point[:2], self.x_range, self.y_range)
            normalized_velocity = self.normalize_position(self.velocity, self.x_range, self.y_range)
            normalized_enemy_velocity = self.normalize_position(self.enemy_velocity, self.x_range, self.y_range)
            
            # THIS IS WHERE I THINK WE SHOULD DO THE CLIPPING

            observation = OrderedDict()
            observation['current_waypoint'] = np.array(self.prev_action[:2], dtype=np.float32)
            observation['enemy_position'] = np.array(normalized_predator, dtype=np.float32)
            observation['enemy_velocity'] = np.array(normalized_enemy_velocity, dtype=np.float32)
            observation['nearest_poster'] = np.array(normalized_poster, dtype=np.float32)
            observation['position'] = np.array(normalized_position, dtype=np.float32)
            observation['velocity'] = np.array(normalized_velocity, dtype=np.float32)
            
            action, _states = self.model.predict(observation, deterministic=False)
            self.new_action = [float(action[0]), float(action[1]), float(action[2])]
            
            

    def push_waypoint(self):
        x_half = abs(self.x_range) / 2.0
        y_half = abs(self.y_range) / 2.0
        if self.end_flight:
            # Set the current position with z=0 to land
            self.waypoint = [self.position[0], self.position[1], 0.0]
            self.waypoint_type = "LANDING"

        elif not self.first_waypoint_generated: # For the very first time, publish a liftoff waypoint
            self.prev_action = [0.0, 0.0, 1.0]  # Replace with the correct z value if necessary
            if (self.position[2] < 3.0):
                self.waypoint = [0.0, 0.0, 3.5]
                self.waypoint_type = "TAKEOFF5"
            else:
                self.first_waypoint_generated = True
                
        else:
            if self.intermediate_waypoints == []:
                target_waypoint = [self.new_action[0] * x_half, self.new_action[1] * y_half, 3.5]  # Assuming 3.5 is the desired altitude
                # Calculate the evenly spaced intermediate waypoints
                self.intermediate_waypoints = self.calculate_intermediate_waypoints(self.position, target_waypoint, self.num_intermediate_waypoints)
                self.current_intermediate_index = 0

            # Use an intermediate waypoint
            self.waypoint_type = "ML"
        
            if self.current_intermediate_index < len(self.intermediate_waypoints):
                self.waypoint = self.intermediate_waypoints[self.current_intermediate_index]
                self.current_intermediate_index += 1
                self.waypoint[0] = np.clip(self.waypoint[0], -(x_half - 3), (x_half - 3)) # waypoint clipping in x
                self.waypoint[1] = np.clip(self.waypoint[1], -(y_half - 3), (y_half - 3)) # waypoint clipping in y
                self.waypoint_type = "ML"
            else:
                # All intermediate waypoints have been used, clear the list
                self.intermediate_waypoints = []
                
                
                if self.new_action[2] < 0: # Use the old action if ML doesn't like the new action
                    self.new_action = self.prev_action
                    self.reject = True
                else:
                    self.reject = False
                self.prev_action = self.new_action
                
                #self.waypoint = [3.0, -6.0, 3.5]
                self.waypoint = [self.new_action[0] * x_half, self.new_action[1] * y_half, 3.5]
                self.waypoint[0] = np.clip(self.waypoint[0], -(x_half - 6), (x_half - 6)) # waypoint clipping in x
                self.waypoint[1] = np.clip(self.waypoint[1], -(y_half - 6), (y_half - 6)) # waypoint clipping in y
                self.waypoint_type = "ML"

        setpoint_msg = TrajectorySetpoint()
        setpoint_msg.position = self.waypoint
        setpoint_msg.yaw = self.yaw
        setpoint_msg.yaw = 0.0
        self.publisher_.publish(setpoint_msg)
        self.get_logger().info(f'Published {self.waypoint_type} waypoint x:{setpoint_msg.position[0]}, y:{setpoint_msg.position[1]}, z:{setpoint_msg.position[2]}, yaw:{self.yaw}')
        #self.get_logger().info(f'Rejected : {self.reject}')
    
    def position_scoring(self):
        point1 = np.array(self.position[:2])
        point2 = np.array(self.predator_position[:2])
        distance = np.linalg.norm(point2 - point1)
        if distance < 5 and self.position[:2] != [0.0, 0.0] and self.predator_position[:2] != [0.0, 0.0] and self.new_tom_scare == True:
            self.new_tom_scare = False
            self.tom_scare_penalty += 10
        elif distance > 5:
            self.new_tom_scare = True
        
        

def main(args=None):
    rclpy.init(args=args)
    ml_agent = MLAgent()
    rclpy.spin(ml_agent)
    ml_agent.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()