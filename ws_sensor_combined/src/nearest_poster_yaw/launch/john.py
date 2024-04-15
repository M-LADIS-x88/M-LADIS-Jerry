from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, DeclareLaunchArgument, TimerAction, OpaqueFunction
from launch.substitutions import LaunchConfiguration
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
import os
from ament_index_python.packages import get_package_share_directory

def launch_nodes(context, slam_launch_file, velodyne_launch_file, *args, **kwargs):
    return [
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
            executable='poster_recon',
            name='poster_reconstruction'
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(slam_launch_file),
            launch_arguments={'use_sim_time': LaunchConfiguration('use_sim_time')}.items()
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(velodyne_launch_file)
        )
    ]

def launch_gps_spoof(context, *args, **kwargs):
    return [
        Node(
            package='px4_ros_com',
            executable='vis_loc_GPS_spoof',
            name='vis_loc_GPS_spoof'
        ),
    ]

def launch_offboard_control(context, *args, **kwargs):
    return [
        Node(
            package='px4_ros_com',
            executable='offboard_control',
            name='offboard_control'
        ),
    ]

def launch_wpgen(context, *args, **kwargs):
    return [
        Node(
            package='wpgen',
            executable='ML_send_wp',
            name='ML_send_wp'
        ),
    ]

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

    # TimerAction to delay launching GPS spoof for 5 seconds
    timer_action_gps_spoof = TimerAction(
        period=5.0,
        actions=[
            OpaqueFunction(function=launch_gps_spoof)
        ]
    )

    # TimerAction to delay launching offboard control for 10 seconds
    timer_action_offboard_control = TimerAction(
        period=10.0,
        actions=[
            OpaqueFunction(function=launch_offboard_control)
        ]
    )

    # TimerAction to delay launching wpgen for 15 seconds
    timer_action_wpgen = TimerAction(
        period=1.0,
        actions=[
            OpaqueFunction(function=launch_wpgen)
        ]
    )

    # Add the timer for each delayed node to the LaunchDescription
    ld.add_action(timer_action_gps_spoof)
    ld.add_action(timer_action_offboard_control)
    ld.add_action(timer_action_wpgen)

    # Add nodes without special delay directly or with a TimerAction if a delay is needed.
    ld.add_action(OpaqueFunction(function=launch_nodes, 
                                 kwargs={'slam_launch_file': slam_launch_file, 
                                         'velodyne_launch_file': velodyne_launch_file}))

    # Return the LaunchDescription with all actions
    return ld