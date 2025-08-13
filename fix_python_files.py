#!/usr/bin/env python3
import os
import re
import glob

def fix_python_file(file_path):
    """修复Python文件中的ROS1导入"""
    try:
        with open(file_path, 'r') as f:
            content = f.read()
        
        # 备份原文件
        with open(file_path + '.backup', 'w') as f:
            f.write(content)
        
        # ROS1到ROS2的基本替换
        replacements = [
            (r'import rospy', 'import rclpy\nfrom rclpy.node import Node'),
            (r'from rospy import', 'from rclpy import'),
            (r'rospy\.init_node\([^)]*\)', 'rclpy.init()\nnode = Node("node_name")'),
            (r'rospy\.Publisher\(', 'node.create_publisher('),
            (r'rospy\.Subscriber\(', 'node.create_subscription('),
            (r'rospy\.Rate\(([^)]+)\)', r'node.create_rate(\1)'),
            (r'rospy\.spin\(\)', 'rclpy.spin(node)'),
            (r'rospy\.loginfo\(', 'node.get_logger().info('),
            (r'rospy\.logwarn\(', 'node.get_logger().warn('),
            (r'rospy\.logerr\(', 'node.get_logger().error('),
            (r'rospy\.logdebug\(', 'node.get_logger().debug('),
            (r'rospy\.get_param\(', 'node.get_parameter('),
            (r'rospy\.set_param\(', 'node.set_parameter('),
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
    # 找到所有Python文件
    py_files = glob.glob('submodules/**/*.py', recursive=True)
    
    print(f"Found {len(py_files)} Python files")
    
    # 修复所有文件
    for file_path in py_files:
        fix_python_file(file_path)
    
    print("All Python files processed!")

if __name__ == "__main__":
    main()
