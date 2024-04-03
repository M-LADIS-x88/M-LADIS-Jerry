#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Vector3
from std_msgs.msg import Float64  # Import the Float64 message type

import math

class OdometryProcessor(Node):
    def __init__(self):
        super().__init__('odometry_processor')
        self.subscription = self.create_subscription(Odometry, '/slam_odom', self.odometry_callback, 10)
        self.position_publisher = self.create_publisher(Vector3, '/position', 10)
        self.yaw_publisher = self.create_publisher(Float64, '/yaw', 10)  # Use Float64 for yaw angle

    def calculate_yaw(self, quaternion):
        # Extract quaternion components
        x, y, z, w = quaternion.x, quaternion.y, quaternion.z, quaternion.w

        # Calculate yaw angle using arctan2
        yaw = math.atan2(2 * (w * z + x * y), 1 - 2 * (y**2 + z**2))

        return yaw

    def odometry_callback(self, msg):
        # Extract position and orientation
        position = msg.pose.pose.position
        orientation = msg.pose.pose.orientation

        # Calculate yaw angle in radians
        yaw_radians = self.calculate_yaw(orientation)

        # Publish position as Vector3
        position_msg = Vector3()
        position_msg.x = position.x
        position_msg.y = position.y
        position_msg.z = position.z
        self.position_publisher.publish(position_msg)

        # Publish yaw angle as Float64 in radians
        yaw_msg = Float64()
        yaw_msg.data = yaw_radians
        self.yaw_publisher.publish(yaw_msg)

def main(args=None):
    rclpy.init(args=args)
    odometry_processor = OdometryProcessor()
    try:
        rclpy.spin(odometry_processor)
    except KeyboardInterrupt:
        pass
    odometry_processor.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
