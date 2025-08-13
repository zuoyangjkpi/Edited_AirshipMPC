#!/usr/bin/env python3
import os
import re
import glob

def fix_cmakelists(file_path):
    """修复CMakeLists.txt文件"""
    try:
        with open(file_path, 'r') as f:
            content = f.read()
        
        # 备份原文件
        with open(file_path + '.backup', 'w') as f:
            f.write(content)
        
        # 基本替换
        content = re.sub(r'cmake_minimum_required\(VERSION [0-9.]+\)', 'cmake_minimum_required(VERSION 3.8)', content)
        content = re.sub(r'find_package\(catkin[^)]*\)', 'find_package(ament_cmake REQUIRED)', content)
        content = re.sub(r'catkin_package\([^)]*\)', 'ament_package()', content)
        content = re.sub(r'catkin_install_python\([^)]*\)', '# catkin_install_python removed', content)
        content = re.sub(r'\$\{catkin_INCLUDE_DIRS\}', '# catkin_INCLUDE_DIRS removed', content)
        content = re.sub(r'\$\{catkin_LIBRARIES\}', '# catkin_LIBRARIES removed', content)
        
        # 添加ROS2标准头部
        if 'if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")' not in content:
            header_addition = '''
# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

'''
            # 在project()后添加
            content = re.sub(r'(project\([^)]+\))', r'\1' + header_addition, content)
        
        with open(file_path, 'w') as f:
            f.write(content)
        
        print(f"Fixed: {file_path}")
        return True
    except Exception as e:
        print(f"Error fixing {file_path}: {e}")
        return False

def fix_package_xml(file_path):
    """修复package.xml文件"""
    try:
        with open(file_path, 'r') as f:
            content = f.read()
        
        # 备份原文件
        with open(file_path + '.backup', 'w') as f:
            f.write(content)
        
        # 基本替换
        content = re.sub(r'<package[^>]*>', '<package format="3">', content)
        content = re.sub(r'<build_depend>catkin</build_depend>', '<buildtool_depend>ament_cmake</buildtool_depend>', content)
        content = re.sub(r'<run_depend>', '<exec_depend>', content)
        content = re.sub(r'</run_depend>', '</exec_depend>', content)
        content = re.sub(r'<buildtool_depend>catkin</buildtool_depend>', '<buildtool_depend>ament_cmake</buildtool_depend>', content)
        
        # 添加export部分如果不存在
        if '<export>' not in content:
            export_section = '''  <export>
    <build_type>ament_cmake</build_type>
  </export>'''
            content = re.sub(r'(</package>)', export_section + '\n\\1', content)
        
        with open(file_path, 'w') as f:
            f.write(content)
        
        print(f"Fixed: {file_path}")
        return True
    except Exception as e:
        print(f"Error fixing {file_path}: {e}")
        return False

def main():
    # 找到所有需要修复的文件
    cmake_files = glob.glob('submodules/**/CMakeLists.txt', recursive=True)
    package_files = glob.glob('submodules/**/package.xml', recursive=True)
    
    print(f"Found {len(cmake_files)} CMakeLists.txt files")
    print(f"Found {len(package_files)} package.xml files")
    
    # 修复CMakeLists.txt文件
    for file_path in cmake_files:
        fix_cmakelists(file_path)
    
    # 修复package.xml文件
    for file_path in package_files:
        fix_package_xml(file_path)
    
    print("All files processed!")

if __name__ == "__main__":
    main()
