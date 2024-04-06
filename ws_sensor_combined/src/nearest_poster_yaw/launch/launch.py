from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, DeclareLaunchArgument
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

    # Create the LaunchDescription object
    ld = LaunchDescription()

    # Add the launch arguments to the LaunchDescription
    ld.add_action(use_sim_time_arg)

    # Add the classifier_node
    ld.add_action(Node(
    package='classifier',
    executable='pose_array_to_file_node',
    name='pose_array_to_file_node'
    ))
    ld.add_action(Node(
    package='px4_ros_com',
    executable='PointCloudProcessor',
    name='PointCloudProcessor'
    ))
    ld.add_action(Node(
    package='px4_ros_com',
    executable='pose_array_to_file_node',
    name='pose_array_to_file_node'
    ))
    ld.add_action(Node(
    package='px4_ros_com',
    executable='offboard_control',
    name='offboard_control'
    ))

    # Add the nearest_poster_node
    ld.add_action(Node(
    package='nearest_poster_yaw',
    executable='nearest_poster_node',
    name='nearest_poster_node'
    ))

    # Add the odometry_node
    ld.add_action(Node(
        package='localization',
        executable='localization_node',
        name='localization_node'
    ))

    # Include the 'slam_velodyne.py' launch file with arguments
    ld.add_action(IncludeLaunchDescription(
        PythonLaunchDescriptionSource(slam_launch_file),
        launch_arguments={'use_sim_time': LaunchConfiguration('use_sim_time')}.items()
    ))

    # Include the 'velodyne-all-nodes-VLP16-launch.py' launch file without arguments
    ld.add_action(IncludeLaunchDescription(
        PythonLaunchDescriptionSource(velodyne_launch_file)
    ))

    return ld