#!/usr/bin/env python3

import os
import re

def update_cpp_file(file_path):
    """更新C++文件从ROS1格式到ROS2格式"""
    print(f"正在更新: {file_path}")
    
    try:
        # 读取原始文件
        with open(file_path, 'r', encoding='utf-8') as f:
            content = f.read()
        
        # 检查是否包含ROS相关代码
        if 'ros/' not in content and 'ROS_' not in content:
            print(f"跳过 {file_path}: 不包含ROS代码")
            return
        
        # 备份原始内容
        original_content = content
        
        # 1. 更新include语句
        # ros/ros.h -> rclcpp/rclcpp.hpp
        content = re.sub(r'#include <ros/ros\.h>', '#include <rclcpp/rclcpp.hpp>', content)
        
        # 更新其他ROS头文件
        content = re.sub(r'#include <ros/(\w+)\.h>', r'#include <rclcpp/\1.hpp>', content)
        
        # 更新消息头文件
        content = re.sub(r'#include <(\w+)/(\w+)\.h>', r'#include <\1/msg/\2.hpp>', content)
        
        # 2. 更新命名空间
        # ros:: -> rclcpp::
        content = re.sub(r'\bros::', 'rclcpp::', content)
        
        # 3. 更新节点初始化
        # ros::init -> rclcpp::init
        content = re.sub(r'ros::init\(([^)]+)\)', r'rclcpp::init(\1)', content)
        
        # 4. 更新NodeHandle
        # ros::NodeHandle -> rclcpp::Node::SharedPtr
        content = re.sub(r'ros::NodeHandle\s+(\w+)', r'auto \1 = rclcpp::Node::make_shared("node_name")', content)
        
        # 5. 更新发布者和订阅者
        # ros::Publisher -> rclcpp::Publisher
        content = re.sub(r'ros::Publisher', 'rclcpp::Publisher', content)
        content = re.sub(r'ros::Subscriber', 'rclcpp::Subscription', content)
        
        # 6. 更新服务
        content = re.sub(r'ros::ServiceServer', 'rclcpp::Service', content)
        content = re.sub(r'ros::ServiceClient', 'rclcpp::Client', content)
        
        # 7. 更新日志宏
        content = re.sub(r'ROS_INFO\(([^)]+)\)', r'RCLCPP_INFO(rclcpp::get_logger("rclcpp"), \1)', content)
        content = re.sub(r'ROS_WARN\(([^)]+)\)', r'RCLCPP_WARN(rclcpp::get_logger("rclcpp"), \1)', content)
        content = re.sub(r'ROS_ERROR\(([^)]+)\)', r'RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), \1)', content)
        content = re.sub(r'ROS_DEBUG\(([^)]+)\)', r'RCLCPP_DEBUG(rclcpp::get_logger("rclcpp"), \1)', content)
        
        # 8. 更新spin
        content = re.sub(r'ros::spin\(\)', 'rclcpp::spin(node)', content)
        content = re.sub(r'ros::spinOnce\(\)', 'rclcpp::spin_some(node)', content)
        
        # 9. 更新时间
        content = re.sub(r'ros::Time::now\(\)', 'node->get_clock()->now()', content)
        content = re.sub(r'ros::Duration\(([^)]+)\)', r'rclcpp::Duration(std::chrono::duration<double>(\1))', content)
        
        # 10. 更新参数
        content = re.sub(r'(\w+)\.getParam\(([^)]+)\)', r'\1->get_parameter(\2)', content)
        
        # 11. 更新Rate
        content = re.sub(r'ros::Rate\s+(\w+)\(([^)]+)\)', r'rclcpp::Rate \1(\2)', content)
        
        # 写回文件
        with open(file_path, 'w', encoding='utf-8') as f:
            f.write(content)
        
        print(f"成功更新: {file_path}")
        
    except Exception as e:
        print(f"更新失败 {file_path}: {e}")

def main():
    # 查找所有C++文件
    cpp_files = []
    
    for root, dirs, files in os.walk('.'):
        for file in files:
            if file.endswith(('.cpp', '.cc', '.cxx', '.h', '.hpp', '.hxx')):
                cpp_files.append(os.path.join(root, file))
    
    print(f"找到 {len(cpp_files)} 个C++文件")
    
    # 更新每个文件
    for file_path in cpp_files:
        update_cpp_file(file_path)
    
    print("所有C++文件更新完成!")

if __name__ == '__main__':
    main()

