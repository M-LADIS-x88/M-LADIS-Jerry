# ML Agent Node
import math
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Point
from geometry_msgs.msg import Pose
from geometry_msgs.msg import PoseArray
from std_msgs.msg import Float64
from px4_msgs.msg import TrajectoryWaypoint


from collections import OrderedDict
import gym_drone
from stable_baselines3 import PPO
from stable_baselines3.common.env_util import make_vec_env
from stable_baselines3.common.vec_env import SubprocVecEnv

class MLAgent(Node):
    def __init__(self):
        super().__init__('ml_agent')
        self.publisher_ = self.create_publisher(TrajectoryWaypoint, '/waypoint', 10)
        self.subscription_ = self.create_subscription(Point, '/position', self.position_callback, 10)
        self.subscription_ = self.create_subscription(Point, '/predator', self.enemy_position_callback, 10)
        self.subscription_ = self.create_subscription(Pose, '/walls', self.walls_callback, 10)
        self.subscription_ = self.create_subscription(PoseArray, 'posters', self.poster_data_callback, 10)
        self.subscription_ = self.create_subscription(Float64, '/poster_yaw', self.yaw_callback, 10)
        
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
        self.get_logger().info('Tracking {} posters'.format(len(self.poses)))
    
    def yaw_callback(self, msg):
        self.yaw = msg.yaw
        self.get_logger().info('Yaw to nearest poster: {}'.format(self.yaw))
        
    def get_poster_centroid(self, x_half, y_half):
        total_checked_posters = 0
        centroid_x = 0
        centroid_y = 0

        for poster in self.poster_data:
            if poster.orientation.x == 1:  # Check if the poster has been checked
                centroid_x += poster.position.x
                centroid_y += poster.position.y
                total_checked_posters += 1.0

        centroid_x /= total_checked_posters
        centroid_y /= total_checked_posters

        return [centroid_x / x_half, centroid_y / y_half]

    def get_nearest_poster(self, x_half, y_half):
        if not self.position or not self.poster_data:
            return None

        nearest_distance = float('inf')
        nearest_poster = None

        for poster in self.poster_data:
            if poster.orientation.z == 0:  # Check if the poster is unchecked
                distance = math.sqrt((poster.position.x - self.position[0])**2 + (poster.position.y - self.position[1])**2)
                if distance < nearest_distance:
                    nearest_distance = distance
                    nearest_poster = poster

        return [nearest_poster.x / x_half, nearest_poster.y / y_half]
    
    def resolve_pos(self, pos, x_half, y_half):
        return [pos[0] / x_half, pos[1] / y_half]

    def generate_waypoint(self):
        x_half = abs(self.x_range) / 2.0
        y_half = abs(self.y_range) / 2.0
        obs = OrderedDict()
        if self.enemy_position:
            obs['enemy_position'] = self.resolve_pos(self.enemy_position, x_half, y_half)
        else:
            obs['enemy_position'] = [0, 0]
        if self.get_nearest_poster:
            obs['nearest_poster'] = self.get_nearest_poster(x_half, y_half)
        else:
            obs['nearest_poster'] = [0, 0]
        if self.position:
            obs['position'] = self.resolve_pos(self.position, x_half, y_half)
        else:
            obs['position'] = [0, 0]
        if self.poster_centroid:
            obs['poster_centroid'] = self.get_poster_centroid(x_half, y_half)
        else:
            obs['poster_centroid'] = [0, 0]
        # if self.waypoint:
        #     obs['current_waypoint'] = self.waypoint
        # else:
        #     obs['current_waypoint'] = [0, 0]
                
        env_id = "DroneExploration-v1"
        env = make_vec_env(env_id, n_envs=1, seed=0, vec_env_cls=SubprocVecEnv)
        model = PPO.load("EXAMPLE/drone_test", env=env)
        action, _states = model.predict(obs, deterministic=False)            
        
        self.waypoint = action
        msg = TrajectoryWaypoint()
        msg.position = [self.waypoint[0] * x_half, self.waypoint[1] * y_half, 3]  # Assuming waypoint is a tuple (x, y)
        msg.yaw = self.yaw
        self.publisher_.publish(msg)
        self.get_logger().info('Published recommended waypoint x:{}, y:{}, yaw:{}'.format[msg.x, msg.y, msg.z])
        
def main(args=None):
    rclpy.init(args=args)
    ml_agent = MLAgent()
    ml_agent.generate_waypoint()  # Assuming you want to generate waypoints immediately
    rclpy.spin(ml_agent)
    ml_agent.destroy_node()
    rclpy.shutdown()
if __name__ == '__main__':
    main()
    