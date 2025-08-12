#!/usr/bin/env python3

import os
import re

def update_cmakelists(file_path):
    """更新CMakeLists.txt文件从ROS1格式到ROS2格式"""
    print(f"正在更新: {file_path}")
    
    try:
        # 读取原始文件
        with open(file_path, 'r', encoding='utf-8') as f:
            content = f.read()
        
        # 备份原始内容
        original_content = content
        
        # 1. 更新cmake最低版本要求
        content = re.sub(r'cmake_minimum_required\(VERSION\s+[\d.]+\)', 
                        'cmake_minimum_required(VERSION 3.8)', content)
        
        # 2. 添加C++标准要求（如果不存在）
        if 'set(CMAKE_CXX_STANDARD' not in content:
            # 在project行之后添加
            content = re.sub(r'(project\([^)]+\))', 
                           r'\1\n\n# Default to C++17\nif(NOT CMAKE_CXX_STANDARD)\n  set(CMAKE_CXX_STANDARD 17)\nendif()', 
                           content)
        
        # 3. 更新find_package调用
        # 替换catkin相关的find_package
        content = re.sub(r'find_package\(catkin\s+REQUIRED\s+COMPONENTS([^)]+)\)', 
                        lambda m: convert_find_package(m.group(1)), content)
        
        # 4. 移除catkin特定的部分
        # 移除catkin_python_setup()
        content = re.sub(r'#?\s*catkin_python_setup\(\)', '', content)
        
        # 移除大段的catkin注释
        content = re.sub(r'################################################\n## Declare ROS messages, services and actions ##\n################################################.*?(?=\n##|\n#############|\nfind_package|\ncmake_minimum|\nproject|\n$)', 
                        '', content, flags=re.DOTALL)
        
        # 5. 替换catkin_package()
        catkin_package_pattern = r'catkin_package\([^)]*\)'
        if re.search(catkin_package_pattern, content):
            content = re.sub(catkin_package_pattern, '', content)
        
        # 6. 更新安装规则
        # 替换catkin_install_python
        content = re.sub(r'catkin_install_python\(PROGRAMS\s+([^)]+)\s+DESTINATION\s+\$\{CATKIN_PACKAGE_BIN_DESTINATION\}\)', 
                        r'install(PROGRAMS \1\n  DESTINATION lib/${PROJECT_NAME})', content)
        
        # 7. 添加ament相关内容
        # 查找是否有Python节点
        has_python_nodes = 'catkin_install_python' in original_content or '.py' in content
        
        # 在文件末尾添加ament_package()
        if 'ament_package()' not in content:
            # 移除末尾的空行
            content = content.rstrip()
            
            # 添加ament相关内容
            ament_content = '\n\n'
            
            if has_python_nodes:
                ament_content += '# Install Python modules\nament_python_install_package(${PROJECT_NAME})\n\n'
            
            ament_content += '# Install launch files\ninstall(DIRECTORY launch/\n  DESTINATION share/${PROJECT_NAME}/launch\n  FILES_MATCHING PATTERN "*.launch.py"\n)\n\n'
            ament_content += 'ament_package()\n'
            
            content += ament_content
        
        # 8. 清理多余的空行
        content = re.sub(r'\n\s*\n\s*\n', '\n\n', content)
        
        # 写回文件
        with open(file_path, 'w', encoding='utf-8') as f:
            f.write(content)
        
        print(f"成功更新: {file_path}")
        
    except Exception as e:
        print(f"更新失败 {file_path}: {e}")

def convert_find_package(components_str):
    """转换find_package中的组件列表"""
    components = [comp.strip() for comp in components_str.split() if comp.strip()]
    
    # ROS1到ROS2的包名映射
    package_mapping = {
        'roscpp': 'rclcpp',
        'rospy': 'rclpy',
        'message_generation': 'rosidl_default_generators',
        'message_runtime': 'rosidl_default_runtime'
    }
    
    # 转换包名
    converted_components = []
    for comp in components:
        if comp in package_mapping:
            converted_components.append(package_mapping[comp])
        else:
            converted_components.append(comp)
    
    # 生成新的find_package调用
    result = 'find_package(ament_cmake REQUIRED)\n'
    
    for comp in converted_components:
        result += f'find_package({comp} REQUIRED)\n'
    
    return result

def main():
    # 查找所有CMakeLists.txt文件
    cmake_files = []
    
    for root, dirs, files in os.walk('.'):
        for file in files:
            if file == 'CMakeLists.txt':
                cmake_files.append(os.path.join(root, file))
    
    print(f"找到 {len(cmake_files)} 个CMakeLists.txt文件")
    
    # 更新每个文件
    for file_path in cmake_files:
        update_cmakelists(file_path)
    
    print("所有CMakeLists.txt文件更新完成!")

if __name__ == '__main__':
    main()

