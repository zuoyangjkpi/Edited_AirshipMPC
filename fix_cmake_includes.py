#!/usr/bin/env python3
"""
修复CMakeLists.txt文件以正确处理include目录和库
"""

import os
import glob

def fix_cmake_includes(package_dir, package_name):
    """修复CMakeLists.txt的include目录和库设置"""
    cmake_path = os.path.join(package_dir, "CMakeLists.txt")
    
    # 检查是否有include目录
    include_dir = os.path.join(package_dir, "include")
    has_include = os.path.exists(include_dir)
    
    # 检查是否有C++源文件
    cpp_files = glob.glob(os.path.join(package_dir, "src", "*.cpp"))
    has_cpp = len(cpp_files) > 0
    
    if not has_cpp:
        return False  # 没有C++文件，不需要修复
    
    # 基本的CMakeLists.txt模板
    cmake_content = f"""cmake_minimum_required(VERSION 3.8)
project({package_name})

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(image_transport REQUIRED)
find_package(OpenCV REQUIRED)
"""

    # 如果有include目录，添加include_directories
    if has_include:
        cmake_content += f"""
# Include directories
include_directories(include)
"""

    # 添加C++可执行文件和库
    if has_cpp:
        cmake_content += f"""
# Dependencies list
set(dependencies
  rclcpp
  std_msgs
  geometry_msgs
  sensor_msgs
  nav_msgs
  tf2
  tf2_ros
  tf2_geometry_msgs
  cv_bridge
  image_transport
  OpenCV
)
"""
        
        # 为每个C++文件创建可执行文件
        for cpp_file in cpp_files:
            exe_name = os.path.splitext(os.path.basename(cpp_file))[0]
            cmake_content += f"""
add_executable({exe_name} src/{os.path.basename(cpp_file)})
ament_target_dependencies({exe_name} ${{dependencies}})

install(TARGETS {exe_name}
  DESTINATION lib/${{PROJECT_NAME}})
"""

    # 安装include目录
    if has_include:
        cmake_content += f"""
# Install include directory
install(DIRECTORY include/
  DESTINATION include/)
"""

    # 安装其他目录
    common_dirs = ["launch", "config", "urdf", "meshes", "worlds"]
    for dir_name in common_dirs:
        dir_path = os.path.join(package_dir, dir_name)
        if os.path.exists(dir_path):
            cmake_content += f"""
install(DIRECTORY {dir_name}/
  DESTINATION share/${{PROJECT_NAME}}/{dir_name}/)
"""

    # 结尾
    cmake_content += """
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
"""

    # 写入文件
    with open(cmake_path, 'w') as f:
        f.write(cmake_content)
    
    return True

def main():
    """主函数"""
    # 需要特殊处理的包
    special_packages = [
        "submodules/AirCap/packages/flight/neural_network_detector",
        "submodules/AirCap/packages/flight/generic_potential_field",
        "submodules/AirCap/packages/flight/target_tracker_distributed_kf",
        "submodules/AirCap/packages/flight/pose_cov_ops_interface"
    ]
    
    for package_dir in special_packages:
        if os.path.exists(package_dir):
            package_name = os.path.basename(package_dir)
            if fix_cmake_includes(package_dir, package_name):
                print(f"✅ 已修复 {package_name} 的 CMakeLists.txt")
            else:
                print(f"⏭️  跳过 {package_name} (无C++文件)")

if __name__ == "__main__":
    main()

