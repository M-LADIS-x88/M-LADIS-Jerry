from launch import LaunchDescription
from launch.actions import TimerAction, OpaqueFunction
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

def launch_nodes(context, *args, **kwargs):
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
        # Removed IncludeLaunchDescription for SLAM
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
   
    # Create the LaunchDescription object
    ld = LaunchDescription()

    # Removed the use_sim_time_arg DeclareLaunchArgument

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
        period=15.0,
        actions=[
            OpaqueFunction(function=launch_wpgen)
        ]
    )

    # Add the timer for each delayed node to the LaunchDescription
    ld.add_action(timer_action_gps_spoof)
    ld.add_action(timer_action_offboard_control)
    ld.add_action(timer_action_wpgen)

    # Add nodes without special delay directly.
    # Removed the kwargs which contained the 'slam_launch_file' argument
    ld.add_action(OpaqueFunction(function=launch_nodes))

    # Return the LaunchDescription with all actions
    return ld