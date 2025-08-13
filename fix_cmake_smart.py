#!/usr/bin/env python3
import os
import re
import glob

def fix_cmakelists_smart(file_path):
    """智能修复CMakeLists.txt文件"""
    try:
        with open(file_path, 'r') as f:
            content = f.read()
        
        # 备份原文件
        with open(file_path + '.backup2', 'w') as f:
            f.write(content)
        
        # 获取项目名
        project_match = re.search(r'project\(([^)]+)\)', content)
        project_name = project_match.group(1) if project_match else "unknown_project"
        
        # 查找实际的源文件
        src_dir = os.path.join(os.path.dirname(file_path), 'src')
        cpp_files = []
        if os.path.exists(src_dir):
            cpp_files = [f for f in os.listdir(src_dir) if f.endswith('.cpp') and not f.endswith('.backup')]
        
        # 生成标准的ROS2 CMakeLists.txt
        new_content = f'''cmake_minimum_required(VERSION 3.8)
project({project_name})

# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)

# Include directories
include_directories(include)
'''
        
        # 为每个实际存在的cpp文件创建可执行文件
        for cpp_file in cpp_files:
            exe_name = cpp_file.replace('.cpp', '')
            new_content += f'''
# Executable: {exe_name}
add_executable({exe_name} src/{cpp_file})
ament_target_dependencies({exe_name} rclcpp std_msgs geometry_msgs sensor_msgs)

install(TARGETS {exe_name}
  DESTINATION lib/${{PROJECT_NAME}})
'''
        
        # 添加标准结尾
        new_content += '''
# Install headers
install(DIRECTORY include/
  DESTINATION include/
  FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")

# Export dependencies
ament_export_include_directories(include)
ament_export_dependencies(rclcpp std_msgs geometry_msgs sensor_msgs)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
'''
        
        with open(file_path, 'w') as f:
            f.write(new_content)
        
        print(f"Smart fixed: {file_path} (found {len(cpp_files)} cpp files)")
        return True
    except Exception as e:
        print(f"Error fixing {file_path}: {e}")
        return False

def main():
    # 找到所有需要修复的CMakeLists.txt文件
    cmake_files = glob.glob('submodules/**/CMakeLists.txt', recursive=True)
    
    print(f"Found {len(cmake_files)} CMakeLists.txt files")
    
    # 智能修复所有CMakeLists.txt文件
    for file_path in cmake_files:
        fix_cmakelists_smart(file_path)
    
    print("All CMakeLists.txt files smart fixed!")

if __name__ == "__main__":
    main()
