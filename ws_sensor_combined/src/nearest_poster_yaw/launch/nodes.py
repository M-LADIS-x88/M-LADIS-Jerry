from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, DeclareLaunchArgument, TimerAction, OpaqueFunction
from launch.substitutions import LaunchConfiguration
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
import os
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    # Get the package share directory paths
    # lidar_slam_dir = get_package_share_directory('lidar_slam')
    # velodyne_dir = get_package_share_directory('velodyne')

    # Define the paths to the launch files
    # slam_launch_file = os.path.join(lidar_slam_dir, 'launch', 'slam_velodyne.py')
    # velodyne_launch_file = os.path.join(velodyne_dir, 'launch', 'velodyne-all-nodes-VLP16-launch.py')

    # Declare launch argument for simulation time
    # use_sim_time_arg = DeclareLaunchArgument(
    #     'use_sim_time',
    #     default_value='false',
    #     description='Use simulation (Gazebo) clock if true')

    # Define the gps_spoof node with a TimerAction
    gps_spoof_node = TimerAction(
        period=2.5,  # Delay for launching the gps_spoof node (in seconds)
        actions=[
            Node(
                package='px4_ros_com',
                executable='vis_loc_GPS_spoof',
                name='vis_loc_GPS_spoof'
            )
        ]
    )
    offboard_node = TimerAction(
        period=5.0,  # Delay for launching the gps_spoof node (in seconds)
        actions=[
            Node(
                package='px4_ros_com',
                executable='offboard_control',
                name='offboard_control'
            )
        ]
    )

    # Create the LaunchDescription and add the launch arguments
    ld = LaunchDescription()
    # ld.add_action(use_sim_time_arg)

    # Add the rest of the nodes to LaunchDescription without a timer
    ld.add_action(Node(
        package='classifier',
        executable='classifier',
        name='classifier'
    ))
    ld.add_action(Node(
        package='px4_ros_com',
        executable='PointCloudProcessor',
        name='PointCloudProcessor'
    ))
    ld.add_action(Node(
        package='nearest_poster_yaw',
        executable='nearest_poster_node',
        name='nearest_poster_node'
    ))
    ld.add_action(Node(
        package='localization',
        executable='localization_node',
        name='localization_node'
    ))
    ld.add_action(Node(
        package='mapping',
        executable='map_node',
        name='map_node'
    ))
    ld.add_action(Node(
        package='px4_ros_com',
        executable='poster_recon',
        name='poster_reconstruction'
    ))
    # ld.add_action(Node(
    #     package='wpgen',
    #     executable='ML_send_wp',
    #     name='ML_send_wp'
    # ))
    
    # ld.add_action(IncludeLaunchDescription(
    #     PythonLaunchDescriptionSource(slam_launch_file),
    #     launch_arguments={'use_sim_time': LaunchConfiguration('use_sim_time')}.items()
    # ))
    # ld.add_action(IncludeLaunchDescription(
    #     PythonLaunchDescriptionSource(velodyne_launch_file)
    # ))

    # Add the TimerAction for the gps_spoof node to the LaunchDescription
    ld.add_action(gps_spoof_node)
    ld.add_action(offboard_node)


    return ld