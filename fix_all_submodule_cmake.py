#!/usr/bin/env python3
"""
批量修复所有submodules中的CMakeLists.txt文件，从catkin转换为ament_cmake
"""

import os
import glob
import subprocess

def get_package_name(package_xml_path):
    """从package.xml中提取包名"""
    try:
        with open(package_xml_path, 'r') as f:
            content = f.read()
            import re
            match = re.search(r'<name>([^<]+)</name>', content)
            if match:
                return match.group(1).strip()
    except:
        pass
    return None

def has_cpp_files(package_dir):
    """检查包是否有C++源文件"""
    cpp_files = glob.glob(os.path.join(package_dir, "src", "*.cpp"))
    cpp_files += glob.glob(os.path.join(package_dir, "src", "**", "*.cpp"), recursive=True)
    return len(cpp_files) > 0

def has_python_files(package_dir):
    """检查包是否有Python源文件"""
    python_files = glob.glob(os.path.join(package_dir, "src", "*.py"))
    python_files += glob.glob(os.path.join(package_dir, "scripts", "*.py"))
    python_files += glob.glob(os.path.join(package_dir, "nodes", "*.py"))
    return len(python_files) > 0

def create_ament_cmake_file(package_dir, package_name):
    """为包创建ROS2 ament_cmake格式的CMakeLists.txt"""
    cmake_path = os.path.join(package_dir, "CMakeLists.txt")
    
    has_cpp = has_cpp_files(package_dir)
    has_python = has_python_files(package_dir)
    
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
"""

    # 如果有Python文件，添加Python支持
    if has_python:
        cmake_content += """find_package(rclpy REQUIRED)
find_package(ament_cmake_python REQUIRED)
"""

    # 如果有C++文件，添加C++库和可执行文件
    if has_cpp:
        cmake_content += f"""
# C++ executables
"""
        # 查找所有C++源文件
        cpp_files = glob.glob(os.path.join(package_dir, "src", "*.cpp"))
        for cpp_file in cpp_files:
            exe_name = os.path.splitext(os.path.basename(cpp_file))[0]
            cmake_content += f"""
add_executable({exe_name} src/{os.path.basename(cpp_file)})
ament_target_dependencies({exe_name} rclcpp std_msgs geometry_msgs sensor_msgs nav_msgs tf2 tf2_ros tf2_geometry_msgs)

install(TARGETS {exe_name}
  DESTINATION lib/${{PROJECT_NAME}})
"""

    # 如果有Python文件，安装Python包
    if has_python:
        cmake_content += f"""
# Python package
ament_python_install_package({package_name})

# Install Python scripts
"""
        # 查找Python脚本
        python_dirs = ["scripts", "nodes", "src"]
        for py_dir in python_dirs:
            py_path = os.path.join(package_dir, py_dir)
            if os.path.exists(py_path):
                py_files = glob.glob(os.path.join(py_path, "*.py"))
                for py_file in py_files:
                    if not os.path.basename(py_file).startswith('__'):
                        cmake_content += f"""install(PROGRAMS {py_dir}/{os.path.basename(py_file)}
  DESTINATION lib/${{PROJECT_NAME}})
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
    
    print(f"✅ 已更新 {package_name} 的 CMakeLists.txt")

def main():
    """主函数"""
    # 查找所有submodules中的package.xml文件
    package_xml_files = glob.glob("submodules/**/package.xml", recursive=True)
    
    print(f"找到 {len(package_xml_files)} 个包需要修复...")
    
    for package_xml in package_xml_files:
        package_dir = os.path.dirname(package_xml)
        package_name = get_package_name(package_xml)
        
        if package_name:
            print(f"正在处理包: {package_name} ({package_dir})")
            create_ament_cmake_file(package_dir, package_name)
        else:
            print(f"⚠️  无法获取包名: {package_xml}")
    
    print("\n🎉 所有submodules的CMakeLists.txt已更新完成！")

if __name__ == "__main__":
    main()

