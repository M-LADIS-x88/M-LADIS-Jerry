from launch import LaunchDescription
from launch.actions import TimerAction, DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def generate_launch_description():
    # Declare the launch arguments
    
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
        #Node(
       #     package='px4_ros_com',
        #    executable='offboard_control',
        #    name='offboard_control'
        #),
        #Node(
         #   package='px4_ros_com',
         #   executable='vis_loc_GPS_spoof',
        #    name='vis_loc_GPS_spoof'
        #),
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
        Node(
            package='wpgen',
            executable='ML_send_wp',
            name='ML_send_wp'
        )
    ]

    # TimerAction to delay launching everything for 4 minutes (240 seconds)
    timer_action = TimerAction(
        period=1.0,  # 4 minutes represented in seconds
        actions=nodes_to_launch
    )

    # Create the LaunchDescription object
    ld = LaunchDescription()

    # Add the launch arguments and delay timer to the LaunchDescription
    ld.add_action(timer_action)

    # Return the LaunchDescription with all actions
    return ld
