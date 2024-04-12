#!/usr/bin/env python3

import os
import numpy as np
import cv2
import math
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Point, PoseStamped
from std_msgs.msg import Float64
from px4_msgs.msg import TrajectorySetpoint
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
        #self.prev_waypoint = [0.0, 0.0, 1.0]
        self.prev_waypoint = [0.0, 0.0]

        model_path = "/home/blake/M-LADIS-Jerry/ws_sensor_combined/src/wpgen/EXAMPLE/drone_test"
        self.model = PPO.load(model_path)

        self.publisher_ = self.create_publisher(TrajectorySetpoint, '/fmu/in/autonomy_waypoint', 1)
        self.cam_publisher = self.create_publisher(Point, '/captured_poster', 1)
        
        # Subscriptions
        self.position_subscription = self.create_subscription(Point, '/position', self.position_callback, 1)
        self.predator_subscription = self.create_subscription(Point, '/Tom', self.predator_callback, 1)
        self.walls_subscription = self.create_subscription(PoseStamped, '/walls', self.walls_callback, 1)
        self.poster_yaw_subscription = self.create_subscription(Float64, '/poster_yaw', self.poster_yaw_callback, 1)
        self.poster_point_subscription = self.create_subscription(Point, '/poster_point', self.poster_point_callback, 1)
        
        self.timer = self.create_timer(1.0, self.generate_waypoint)

    def position_callback(self, msg):
        self.position = [msg.x, msg.y, msg.z]
        #self.get_logger().info('jerry_x={}, jerry_y={}, jerry_z={}'.format(self.position[0],self.position[1],self.position[2]))

    def predator_callback(self, msg):
        self.predator_position = [msg.x, msg.y, msg.z]
        self.get_logger().info('tom_x={}, tom_y={}, tom_z={}'.format(self.predator_position[0],self.predator_position[1],self.predator_position[2]))

    def walls_callback(self, msg):
        self.x_range = msg.pose.orientation.x - msg.pose.position.x
        self.y_range = msg.pose.orientation.y - msg.pose.position.y
        self.get_logger().info('x_width={}, y_length={}'.format(self.x_range, self.y_range))

    def poster_yaw_callback(self, msg):
        self.yaw = msg.data
        self.get_logger().info('Yaw to nearest poster: {}'.format(self.yaw))

    def poster_point_callback(self, msg):
        self.poster_point = [msg.x, msg.y, msg.z]
        if msg.z == 1:  # Check if in range to take a photo
            self.get_logger().info('In Range')
            self.take_photo_and_publish_poster(msg.x, msg.y)
        else:
            self.get_logger().info('Out of Range')

    def take_photo_and_publish_poster(self, x, y):
        image_name = f"image_{len(self.image_data)}.jpg"
        self.capture_image(image_name)
        entry = (x, y, image_name)
        self.image_data.append(entry)                
        # After saving the photo, publish the poster's location
        point_msg = Point(x=x, y=y)
        self.cam_publisher.publish(point_msg)
        self.get_logger().info(f'Published captured poster at x: {x}, y: {y}')

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
            ((pos[0] - x_half) / x_half) if x_half else 0.0,
            ((pos[1] - y_half) / y_half) if y_half else 0.0
        ]

    def generate_waypoint(self):
        normalized_position = self.normalize_position(self.position, self.x_range, self.y_range)
        normalized_predator = self.normalize_position(self.predator_position, self.x_range, self.y_range)
        normalized_poster = self.normalize_position(self.poster_point[:2], self.x_range, self.y_range)
        
        observation = OrderedDict()
        observation['current_waypoint'] = np.array(self.prev_waypoint, dtype=np.float32)
        observation['enemy_position'] = np.array(normalized_predator, dtype=np.float32)
        observation['nearest_poster'] = np.array(normalized_poster, dtype=np.float32)
        observation['position'] = np.array(normalized_position, dtype=np.float32)
        
        
        action, _states = self.model.predict(observation, deterministic=False)
        new_waypoint = [float(action[0]), float(action[1])]
        # new_waypoint = [float(action[0]), float(action[1]), float(action[2])]

        setpoint_msg = TrajectorySetpoint()
        
        x_half = abs(self.x_range) / 2.0
        y_half = abs(self.y_range) / 2.0

        setpoint_msg.position = [self.prev_waypoint[0] * x_half, self.prev_waypoint[1] * y_half, 3.0]

        # if new_waypoint[2] < 0:
        #     setpoint_msg.position = [self.prev_waypoint[0] * x_half, self.prev_waypoint[1] * y_half, 3.0]
        # else:
        #     setpoint_msg.position = [new_waypoint[0] * x_half, new_waypoint[1] * y_half, 3.0]
        # Create TrajectorySetpoint message and publish
        
        self.prev_waypoint = new_waypoint
        setpoint_msg.yaw = self.yaw
        self.publisher_.publish(setpoint_msg)
        self.get_logger().info(f'Published recommended waypoint x:{setpoint_msg.position[0]}, y:{setpoint_msg.position[1]}, z:3.0, yaw:{self.yaw}')

def main(args=None):
    rclpy.init(args=args)
    ml_agent = MLAgent()
    rclpy.spin(ml_agent)
    ml_agent.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()