from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, DeclareLaunchArgument, TimerAction, OpaqueFunction
from launch.substitutions import LaunchConfiguration
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
import os
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    # Get the directories of the 'lidar_slam' and 'velodyne' packages
    lidar_slam_dir = get_package_share_directory('lidar_slam')
    velodyne_dir = get_package_share_directory('velodyne')

    # Define the paths to the launch files within their respective packages
    slam_launch_file = os.path.join(lidar_slam_dir, 'launch', 'slam_velodyne.py')
    velodyne_launch_file = os.path.join(velodyne_dir, 'launch', 'velodyne-all-nodes-VLP16-launch.py')

    # Declare the launch arguments
    use_sim_time_arg = DeclareLaunchArgument(
        'use_sim_time',
        default_value='false',
        description='Use simulation (Gazebo) clock if true')

    # Define node actions for the delayed launch
    nodes_to_launch = [
        Node(
            package='classifier',
            executable='classifier',
            name='classifier'
        ),
        Node(
            package='px4_ros_com',
            executable='PointCloudProcessor',
            name='PointCloudProcessor'
        ),
        Node(
            package='px4_ros_com',
            executable='offboard_control',
            name='offboard_control'
        ),
        Node(
            package='px4_ros_com',
            executable='vis_loc_GPS_spoof',
            name='vis_loc_GPS_spoof'
        ),
        Node(
            package='nearest_poster_yaw',
            executable='nearest_poster_node',
            name='nearest_poster_node'
        ),
        Node(
            package='localization',
            executable='localization_node',
            name='localization_node'
        ),
        Node(
            package='mapping',
            executable='map_node',
            name='map_node'
        ),
        Node(
            package='px4_ros_com',
            executable='env_reconstruction',
            name='env_reconstruction'
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(slam_launch_file),
            launch_arguments={'use_sim_time': LaunchConfiguration('use_sim_time')}.items()
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(velodyne_launch_file)
        )
    ]

    # TimerAction to delay launching everything for 4 minutes (240 seconds)
    timer_action = TimerAction(
        period=5.0,  # 4 minutes represented in seconds
        actions=nodes_to_launch
    )

    # Create the LaunchDescription object
    ld = LaunchDescription()

    # Add the launch arguments and delay timer to the LaunchDescription
    ld.add_action(use_sim_time_arg)
    ld.add_action(timer_action)

    # Return the LaunchDescription with all actions
    return ld