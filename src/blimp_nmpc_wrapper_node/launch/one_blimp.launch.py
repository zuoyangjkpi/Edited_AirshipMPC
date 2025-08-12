#!/usr/bin/env python3

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, GroupAction
from launch.substitutions import LaunchConfiguration, TextSubstitution
from launch_ros.actions import Node, PushRosNamespace
from launch_ros.substitutions import FindPackageShare
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    # Declare launch arguments
    robotID_arg = DeclareLaunchArgument(
        'robotID',
        default_value='1',
        description='Launch argument for robotID'
    )
    
    numRobots_arg = DeclareLaunchArgument(
        'numRobots',
        default_value='1',
        description='Launch argument for numRobots'
    )
    
    # Create launch description
    ld = LaunchDescription()
    
    # Add arguments
    ld.add_action(robotID_arg)
    ld.add_action(numRobots_arg)

    # Add nodes
    node_1 = Node(
        package='nmpc_blimp_formation_planner',
        executable='nmpc_blimp_planner',
        name='nmpc_blimp_planner',
        namespace=[TextSubstitution(text='machine_'), LaunchConfiguration('machine_robotID')],
        parameters=[os.path.join(get_package_share_directory('nmpc_blimp_formation_planner'), 'config/open_params.yaml')],
        output='screen'
    )
    
    ld.add_action(node_1)

    node_2 = Node(
        package='blimp_nmpc_wrapper_node',
        executable='blimp_nmpc_wrapper_node',
        name='blimp_nmpc_wrapper_node',
        namespace=[TextSubstitution(text='machine_'), LaunchConfiguration('machine_robotID')],
        parameters=[{'robotID': '$(arg robotID)', 'numRobots': '$(arg numRobots)'}],
        output='screen'
    )
    
    ld.add_action(node_2)

    return ld

if __name__ == '__main__':
    generate_launch_description()
