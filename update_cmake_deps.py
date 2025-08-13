#!/usr/bin/env python3
import os
import re
import glob

def update_cmake_deps(file_path):
    """更新CMakeLists.txt文件的依赖"""
    try:
        with open(file_path, 'r') as f:
            content = f.read()
        
        # 添加更多依赖
        additional_deps = [
            'find_package(camera_info_manager REQUIRED)',
            'find_package(image_transport REQUIRED)',
            'find_package(cv_bridge REQUIRED)',
            'find_package(tf2_ros REQUIRED)',
            'find_package(tf2_geometry_msgs REQUIRED)',
        ]
        
        # 在find_package(sensor_msgs REQUIRED)后添加
        for dep in additional_deps:
            if dep not in content:
                content = content.replace(
                    'find_package(sensor_msgs REQUIRED)',
                    f'find_package(sensor_msgs REQUIRED)\n{dep}'
                )
        
        # 更新ament_target_dependencies
        content = re.sub(
            r'ament_target_dependencies\((\w+) rclcpp std_msgs geometry_msgs sensor_msgs\)',
            r'ament_target_dependencies(\1 rclcpp std_msgs geometry_msgs sensor_msgs camera_info_manager image_transport cv_bridge tf2_ros tf2_geometry_msgs)',
            content
        )
        
        # 更新export dependencies
        content = re.sub(
            r'ament_export_dependencies\(rclcpp std_msgs geometry_msgs sensor_msgs\)',
            r'ament_export_dependencies(rclcpp std_msgs geometry_msgs sensor_msgs camera_info_manager image_transport cv_bridge tf2_ros tf2_geometry_msgs)',
            content
        )
        
        with open(file_path, 'w') as f:
            f.write(content)
        
        print(f"Updated deps: {file_path}")
        return True
    except Exception as e:
        print(f"Error updating {file_path}: {e}")
        return False

def main():
    # 找到所有CMakeLists.txt文件
    cmake_files = glob.glob('submodules/**/CMakeLists.txt', recursive=True)
    
    print(f"Found {len(cmake_files)} CMakeLists.txt files")
    
    # 更新所有CMakeLists.txt文件
    for file_path in cmake_files:
        update_cmake_deps(file_path)
    
    print("All CMakeLists.txt files updated with additional dependencies!")

if __name__ == "__main__":
    main()
