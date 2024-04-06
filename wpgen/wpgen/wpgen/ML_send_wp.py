# ML Agent Node
import math
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Point
from geometry_msgs.msg import Pose
from geometry_msgs.msg import PoseArray
from std_msgs.msg import Float64
from std_msgs.msg import Bool
from px4_msgs.msg import TrajectoryWaypoint

import numpy as np

from collections import OrderedDict
from stable_baselines3 import PPO


class MLAgent(Node):
    def __init__(self):
        super().__init__('ml_agent')
        self.publisher_ = self.create_publisher(TrajectoryWaypoint, '/waypoint', 10)
        self.in_range_subscription = self.create_subscription(Bool, '/in_range', self.range_callback, 10)
        self.position_subscription = self.create_subscription(Point, '/position', self.position_callback, 10)
        self.predator_subscription = self.create_subscription(Point, '/predator', self.enemy_position_callback, 10)
        self.walls_subscription = self.create_subscription(Pose, '/walls', self.walls_callback, 10)
        self.posters_subscription = self.create_subscription(PoseArray, 'posters', self.poster_data_callback, 10)
        self.poster_yaw_subscription = self.create_subscription(Float64, '/poster_yaw', self.yaw_callback, 10)
        self.yaw_subscription_ = self.create_subscription(Float64, '/yaw', self.current_yaw_callback, 10)
        self.model = PPO.load("EXAMPLE/drone_test")
        
        # Initializing
        self.range_bool = False
        self.position = [0,0]
        self.enemy_position = [0,0]
        self.x_range = 0
        self.y_range = 0
        self.posters = []
        self.yaw = 0
        self.current_yaw = 0
        
    def range_callback(self, msg):
        self.range_bool = msg.data
        self.get_logger().info('freeze={}'.format(self.range_bool))
    
    def position_callback(self, msg):
        self.position = [msg.x, msg.y]
        self.get_logger().info('jerry_x={}, jerry_y={}'.format(self.position[0], self.position[1]))
        
    def enemy_position_callback(self, msg):
        self.enemy_position = [msg.x, msg.y]
        self.get_logger().info('tom_x={}, tom_y={}'.format(self.enemy_position[0], self.enemy_position[1]))
        
    def walls_callback(self, msg):
        self.x_range = msg.orientation.x - msg.position.x
        self.y_range = msg.orientation.y - msg.position.y
        self.get_logger().info('x_width={}, y_length={}'.format(self.x_range, self.y_range))
        
    def poster_data_callback(self, msg):
        self.posters = msg.poses
        self.get_logger().info('Tracking {} posters'.format(len(self.posters)))
    
    def yaw_callback(self, msg):
        self.yaw = msg.data
        self.get_logger().info('Yaw to nearest poster: {}'.format(self.yaw))
        
    def current_yaw_callback(self, msg):
        self.current_yaw = msg.data
        self.get_logger().info('Current yaw: {}'.format(self.yaw))
        
    def get_poster_centroid(self, x_half, y_half):
        total_checked_posters = 0
        centroid_x = 0
        centroid_y = 0

        for poster in self.posters:
            if poster.orientation.x == 1:  # Check if the poster has been checked
                centroid_x += poster.position.x
                centroid_y += poster.position.y
                total_checked_posters += 1.0

        if total_checked_posters != 0:
            centroid_x /= total_checked_posters
            centroid_y /= total_checked_posters
        else:
            centroid_x = 0
            centroid_y = 0

        return [centroid_x / x_half, centroid_y / y_half]

    def get_nearest_poster(self, x_half, y_half):
        if not self.position or not self.posters:
            return [0, 0]

        nearest_distance = float('inf')
        nearest_poster = None

        for poster in self.posters:
            if poster.orientation.z == 0:  # Check if the poster is unchecked
                distance = math.sqrt((poster.position.x - self.position[0])**2 + (poster.position.y - self.position[1])**2)
                if distance < nearest_distance:
                    nearest_distance = distance
                    nearest_poster = poster
        if nearest_poster == None:
            return [0, 0]
        return [nearest_poster.x / x_half, nearest_poster.y / y_half]
    
    def resolve_pos(self, pos, x_half, y_half):
        return [pos[0] / x_half, pos[1] / y_half]

    def generate_waypoint(self):
        x_half = abs(self.x_range) / 2.0
        y_half = abs(self.y_range) / 2.0
        
        obs = OrderedDict()
        
        if self.enemy_position:
            obs['enemy_position'] = np.array(self.resolve_pos(self.enemy_position, x_half, y_half), dtype=np.float32)
        else:
            obs['enemy_position'] = np.array([0, 0], dtype=np.float32)
        if self.get_nearest_poster:
            obs['nearest_poster'] = np.array(self.get_nearest_poster(x_half, y_half), dtype=np.float32)
        else:
            obs['nearest_poster'] = np.array([0, 0], dtype=np.float32)
        if self.position:
            obs['position'] = np.array(self.resolve_pos(self.position, x_half, y_half), dtype=np.float32)
        else:
            obs['position'] = np.array([0, 0], dtype=np.float32)
        if self.poster_centroid:
            obs['poster_centroid'] = np.array(self.get_poster_centroid(x_half, y_half), dtype=np.float32)
        else:
            obs['poster_centroid'] = np.array([0, 0], dtype=np.float32)
        # if self.waypoint:
        #     obs['current_waypoint'] = np.array(self.waypoint, dtype=np.float32)
        # else:
        #     obs['current_waypoint'] = np.array([0, 0], dtype=np.float32)
        
        action, _states = self.model.predict(obs, deterministic=False)            
        
        self.waypoint = action
        msg = TrajectoryWaypoint()
        
        if self.range_bool:
            msg.position = [self.position[0] * x_half, self.position[1] * y_half, 3]
            msg.yaw = self.current_yaw
            # SEND TAKE PHOTO COMMAND
        else: 
            msg.position = [self.waypoint[0] * x_half, self.waypoint[1] * y_half, 3]
            msg.yaw = self.yaw
        self.publisher_.publish(msg)
        self.get_logger().info('Published recommended waypoint x:{}, y:{}, yaw:{}'.format[msg.position[0], msg.position[1], msg.yaw])
        
def main(args=None):
    rclpy.init(args=args)
    ml_agent = MLAgent()
    ml_agent.generate_waypoint()  # Assuming you want to generate waypoints immediately
    rclpy.spin(ml_agent)
    ml_agent.destroy_node()
    rclpy.shutdown()
if __name__ == '__main__':
    main()
    