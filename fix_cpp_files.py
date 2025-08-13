#!/usr/bin/env python3
import os
import re
import glob

def fix_cpp_file(file_path):
    """修复C++文件中的ROS1导入"""
    try:
        with open(file_path, 'r') as f:
            content = f.read()
        
        # 备份原文件
        with open(file_path + '.backup', 'w') as f:
            f.write(content)
        
        # ROS1到ROS2的基本替换
        replacements = [
            (r'#include <ros/ros\.h>', '#include <rclcpp/rclcpp.hpp>'),
            (r'#include "ros/ros\.h"', '#include "rclcpp/rclcpp.hpp"'),
            (r'ros::init\([^)]*\)', 'rclcpp::init(argc, argv)'),
            (r'ros::NodeHandle\s+(\w+)', r'auto \1 = rclcpp::Node::make_shared("node_name")'),
            (r'ros::NodeHandle\s+(\w+)\([^)]*\)', r'auto \1 = rclcpp::Node::make_shared("node_name")'),
            (r'ros::Publisher\s+(\w+)', r'rclcpp::Publisher<>::SharedPtr \1'),
            (r'ros::Subscriber\s+(\w+)', r'rclcpp::Subscription<>::SharedPtr \1'),
            (r'ros::Rate\s+(\w+)\(([^)]+)\)', r'rclcpp::Rate \1(\2)'),
            (r'ros::spinOnce\(\)', 'rclcpp::spin_some(node)'),
            (r'ros::spin\(\)', 'rclcpp::spin(node)'),
            (r'ROS_INFO\(', 'RCLCPP_INFO(node->get_logger(), '),
            (r'ROS_WARN\(', 'RCLCPP_WARN(node->get_logger(), '),
            (r'ROS_ERROR\(', 'RCLCPP_ERROR(node->get_logger(), '),
            (r'ROS_DEBUG\(', 'RCLCPP_DEBUG(node->get_logger(), '),
        ]
        
        modified = False
        for pattern, replacement in replacements:
            if re.search(pattern, content):
                content = re.sub(pattern, replacement, content)
                modified = True
        
        if modified:
            with open(file_path, 'w') as f:
                f.write(content)
            print(f"Fixed: {file_path}")
        
        return True
    except Exception as e:
        print(f"Error fixing {file_path}: {e}")
        return False

def main():
    # 找到所有C++文件
    cpp_files = glob.glob('submodules/**/*.cpp', recursive=True)
    h_files = glob.glob('submodules/**/*.h', recursive=True)
    
    all_files = cpp_files + h_files
    print(f"Found {len(all_files)} C++ files")
    
    # 修复所有文件
    for file_path in all_files:
        fix_cpp_file(file_path)
    
    print("All C++ files processed!")

if __name__ == "__main__":
    main()
