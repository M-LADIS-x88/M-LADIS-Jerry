from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch.launch_description_sources import PythonLaunchDescriptionSource
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

    # Add the launch arguments and include statements for SLAM and Velodyne to the LaunchDescription
    ld.add_action(use_sim_time_arg)
    ld.add_action(
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(slam_launch_file),
            launch_arguments={'use_sim_time': LaunchConfiguration('use_sim_time')}.items()
        )
    )
    ld.add_action(
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(velodyne_launch_file)
        )
    )

    # Return the LaunchDescription with all actions
    return ld