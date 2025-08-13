#!/usr/bin/env python3
"""
修复C++文件中的ROS1头文件包含，转换为ROS2格式
"""

import os
import glob
import re

# ROS1到ROS2头文件映射
HEADER_MAPPINGS = {
    # ROS core
    'ros/ros.h': 'rclcpp/rclcpp.hpp',
    'ros/console.h': 'rclcpp/logging.hpp',
    'ros/time.h': 'rclcpp/time.hpp',
    'ros/duration.h': 'rclcpp/duration.hpp',
    'ros/rate.h': 'rclcpp/rate.hpp',
    'ros/node_handle.h': 'rclcpp/node.hpp',
    'ros/publisher.h': 'rclcpp/publisher.hpp',
    'ros/subscriber.h': 'rclcpp/subscription.hpp',
    'ros/service_server.h': 'rclcpp/service.hpp',
    'ros/service_client.h': 'rclcpp/client.hpp',
    'ros/timer.h': 'rclcpp/timer.hpp',
    
    # Messages
    'std_msgs/String.h': 'std_msgs/msg/string.hpp',
    'std_msgs/Bool.h': 'std_msgs/msg/bool.hpp',
    'std_msgs/Int32.h': 'std_msgs/msg/int32.hpp',
    'std_msgs/Float64.h': 'std_msgs/msg/float64.hpp',
    'std_msgs/Header.h': 'std_msgs/msg/header.hpp',
    'std_msgs/Empty.h': 'std_msgs/msg/empty.hpp',
    
    'geometry_msgs/Point.h': 'geometry_msgs/msg/point.hpp',
    'geometry_msgs/Vector3.h': 'geometry_msgs/msg/vector3.hpp',
    'geometry_msgs/Quaternion.h': 'geometry_msgs/msg/quaternion.hpp',
    'geometry_msgs/Pose.h': 'geometry_msgs/msg/pose.hpp',
    'geometry_msgs/PoseStamped.h': 'geometry_msgs/msg/pose_stamped.hpp',
    'geometry_msgs/Twist.h': 'geometry_msgs/msg/twist.hpp',
    'geometry_msgs/TwistStamped.h': 'geometry_msgs/msg/twist_stamped.hpp',
    'geometry_msgs/Transform.h': 'geometry_msgs/msg/transform.hpp',
    'geometry_msgs/TransformStamped.h': 'geometry_msgs/msg/transform_stamped.hpp',
    
    'sensor_msgs/Image.h': 'sensor_msgs/msg/image.hpp',
    'sensor_msgs/CameraInfo.h': 'sensor_msgs/msg/camera_info.hpp',
    'sensor_msgs/PointCloud2.h': 'sensor_msgs/msg/point_cloud2.hpp',
    'sensor_msgs/LaserScan.h': 'sensor_msgs/msg/laser_scan.hpp',
    'sensor_msgs/Imu.h': 'sensor_msgs/msg/imu.hpp',
    'sensor_msgs/NavSatFix.h': 'sensor_msgs/msg/nav_sat_fix.hpp',
    
    'nav_msgs/Odometry.h': 'nav_msgs/msg/odometry.hpp',
    'nav_msgs/Path.h': 'nav_msgs/msg/path.hpp',
    'nav_msgs/OccupancyGrid.h': 'nav_msgs/msg/occupancy_grid.hpp',
    
    # TF
    'tf/transform_listener.h': 'tf2_ros/transform_listener.h',
    'tf/transform_broadcaster.h': 'tf2_ros/transform_broadcaster.h',
    'tf/transform_datatypes.h': 'tf2_geometry_msgs/tf2_geometry_msgs.hpp',
    'tf2_ros/transform_listener.h': 'tf2_ros/transform_listener.h',
    'tf2_ros/buffer.h': 'tf2_ros/buffer.h',
    
    # Image transport
    'image_transport/image_transport.h': 'image_transport/image_transport.hpp',
    'image_transport/subscriber.h': 'image_transport/subscriber.hpp',
    'image_transport/publisher.h': 'image_transport/publisher.hpp',
    
    # CV Bridge
    'cv_bridge/cv_bridge.h': 'cv_bridge/cv_bridge.h',
    
    # Dynamic reconfigure (no direct equivalent, usually removed)
    'dynamic_reconfigure/server.h': '// dynamic_reconfigure not available in ROS2',
    'dynamic_reconfigure/Config.h': '// dynamic_reconfigure not available in ROS2',
}

def fix_cpp_file_headers(file_path):
    """修复单个C++文件的头文件包含"""
    try:
        with open(file_path, 'r') as f:
            content = f.read()
        
        original_content = content
        
        # 替换头文件包含
        for old_header, new_header in HEADER_MAPPINGS.items():
            old_include = f'#include <{old_header}>'
            if new_header.startswith('//'):
                # 注释掉不可用的头文件
                new_include = f'// {old_include} - {new_header}'
            else:
                new_include = f'#include <{new_header}>'
            
            content = content.replace(old_include, new_include)
        
        # 如果内容有变化，写回文件
        if content != original_content:
            with open(file_path, 'w') as f:
                f.write(content)
            return True
        
        return False
        
    except Exception as e:
        print(f"❌ 修复 {file_path} 时出错: {e}")
        return False

def fix_header_file_headers(file_path):
    """修复单个头文件的包含"""
    return fix_cpp_file_headers(file_path)  # 使用相同的逻辑

def main():
    """主函数"""
    # 查找所有C++源文件和头文件
    cpp_files = glob.glob("submodules/**/src/*.cpp", recursive=True)
    header_files = glob.glob("submodules/**/include/**/*.h", recursive=True)
    header_files += glob.glob("submodules/**/include/**/*.hpp", recursive=True)
    
    all_files = cpp_files + header_files
    
    print(f"找到 {len(all_files)} 个C++文件需要检查...")
    
    modified_count = 0
    for file_path in all_files:
        if fix_cpp_file_headers(file_path):
            print(f"✅ 已修复 {file_path}")
            modified_count += 1
        else:
            print(f"⏭️  跳过 {file_path} (无需修改)")
    
    print(f"\n🎉 修复完成！共修改了 {modified_count} 个文件")

if __name__ == "__main__":
    main()

