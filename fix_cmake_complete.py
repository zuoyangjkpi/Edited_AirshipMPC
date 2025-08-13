#!/usr/bin/env python3
import os
import re
import glob

def fix_cmakelists_complete(file_path):
    """完全重写CMakeLists.txt文件为正确的ROS2格式"""
    try:
        with open(file_path, 'r') as f:
            content = f.read()
        
        # 备份原文件
        with open(file_path + '.backup', 'w') as f:
            f.write(content)
        
        # 获取项目名
        project_match = re.search(r'project\(([^)]+)\)', content)
        project_name = project_match.group(1) if project_match else "unknown_project"
        
        # 检查是否有可执行文件
        has_executables = bool(re.search(r'add_executable', content))
        has_libraries = bool(re.search(r'add_library', content))
        
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

# Build executables and libraries based on original content
'''
        
        # 提取原始的可执行文件和库定义
        executable_matches = re.findall(r'add_executable\s*\(\s*(\w+)[^)]*\)', content)
        library_matches = re.findall(r'add_library\s*\(\s*(\w+)[^)]*\)', content)
        
        # 添加可执行文件
        for exe_name in executable_matches:
            new_content += f'''
# Executable: {exe_name}
add_executable({exe_name} src/{exe_name}.cpp)
ament_target_dependencies({exe_name} rclcpp std_msgs geometry_msgs sensor_msgs)

install(TARGETS {exe_name}
  DESTINATION lib/${{PROJECT_NAME}})
'''
        
        # 添加库
        for lib_name in library_matches:
            new_content += f'''
# Library: {lib_name}
add_library({lib_name} src/{lib_name}.cpp)
ament_target_dependencies({lib_name} rclcpp std_msgs geometry_msgs sensor_msgs)

install(TARGETS {lib_name}
  DESTINATION lib/${{PROJECT_NAME}})
'''
        
        # 如果没有找到可执行文件或库，创建一个默认的
        if not executable_matches and not library_matches:
            # 查找src目录中的cpp文件
            src_dir = os.path.join(os.path.dirname(file_path), 'src')
            if os.path.exists(src_dir):
                cpp_files = [f for f in os.listdir(src_dir) if f.endswith('.cpp')]
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
  DESTINATION include/)

# Install launch files
install(DIRECTORY launch/
  DESTINATION share/${PROJECT_NAME}/launch/
  FILES_MATCHING PATTERN "*.launch.py")

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
        
        print(f"Completely rewrote: {file_path}")
        return True
    except Exception as e:
        print(f"Error fixing {file_path}: {e}")
        return False

def main():
    # 找到所有需要修复的CMakeLists.txt文件
    cmake_files = glob.glob('submodules/**/CMakeLists.txt', recursive=True)
    
    print(f"Found {len(cmake_files)} CMakeLists.txt files")
    
    # 完全重写所有CMakeLists.txt文件
    for file_path in cmake_files:
        fix_cmakelists_complete(file_path)
    
    print("All CMakeLists.txt files completely rewritten!")

if __name__ == "__main__":
    main()
