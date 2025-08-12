#!/usr/bin/env python3

import os
import re
import xml.etree.ElementTree as ET

def convert_launch_file(file_path):
    """将XML格式的launch文件转换为Python格式"""
    print(f"正在转换: {file_path}")
    
    try:
        # 读取原始XML文件
        tree = ET.parse(file_path)
        root = tree.getroot()
        
        # 生成Python launch文件内容
        python_content = generate_python_launch(root, tree)
        
        # 创建新的.launch.py文件
        new_file_path = file_path.replace('.launch', '.launch.py')
        
        with open(new_file_path, 'w', encoding='utf-8') as f:
            f.write(python_content)
        
        print(f"成功转换: {file_path} -> {new_file_path}")
        
        # 可选：删除原始.launch文件
        # os.remove(file_path)
        
    except Exception as e:
        print(f"转换失败 {file_path}: {e}")

def find_parent(tree, element):
    """查找元素的父节点"""
    for parent in tree.iter():
        for child in parent:
            if child == element:
                return parent
    return None

def generate_python_launch(root, tree):
    """根据XML元素生成Python launch代码"""
    
    # 开始生成Python代码
    content = """#!/usr/bin/env python3

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, GroupAction
from launch.substitutions import LaunchConfiguration, TextSubstitution
from launch_ros.actions import Node, PushRosNamespace
from launch_ros.substitutions import FindPackageShare
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    # Declare launch arguments
"""
    
    # 收集所有参数
    args = root.findall('.//arg')
    for arg in args:
        name = arg.get('name')
        default = arg.get('default', '')
        content += f"""    {name}_arg = DeclareLaunchArgument(
        '{name}',
        default_value='{default}',
        description='Launch argument for {name}'
    )
    
"""
    
    # 开始构建launch描述
    content += """    # Create launch description
    ld = LaunchDescription()
    
    # Add arguments
"""
    
    for arg in args:
        name = arg.get('name')
        content += f"    ld.add_action({name}_arg)\n"
    
    content += "\n    # Add nodes\n"
    
    # 处理节点
    nodes = root.findall('.//node')
    for i, node in enumerate(nodes):
        node_name = node.get('name')
        pkg = node.get('pkg')
        executable = node.get('type')
        
        # 处理Python可执行文件
        if executable and executable.endswith('.py'):
            executable = executable[:-3]  # 移除.py扩展名
        
        # 处理命名空间
        parent = find_parent(tree, node)
        namespace = ""
        if parent is not None and parent.tag == 'group':
            ns = parent.get('ns')
            if ns:
                namespace = ns
        
        # 处理参数
        params = []
        for param in node.findall('param'):
            param_name = param.get('name')
            param_value = param.get('value')
            params.append(f"'{param_name}': '{param_value}'")
        
        # 处理rosparam文件
        rosparam_files = []
        for rosparam in node.findall('rosparam'):
            file_attr = rosparam.get('file')
            if file_attr:
                # 转换$(find pkg)语法
                file_attr = file_attr.replace('$(find ', '').replace(')', '')
                parts = file_attr.split('/')
                if len(parts) > 1:
                    pkg_name = parts[0]
                    file_path = '/'.join(parts[1:])
                    rosparam_files.append(f"os.path.join(get_package_share_directory('{pkg_name}'), '{file_path}')")
        
        # 生成节点代码
        content += f"""    node_{i+1} = Node(
        package='{pkg}',
        executable='{executable}',
        name='{node_name}',"""
        
        if namespace:
            # 处理命名空间中的变量替换
            if '$(arg ' in namespace:
                var_name = namespace.replace('$(arg ', '').replace(')', '')
                content += f"""
        namespace=[TextSubstitution(text='machine_'), LaunchConfiguration('{var_name}')],"""
            else:
                content += f"""
        namespace='{namespace}',"""
        
        if params:
            content += f"""
        parameters=[{{{', '.join(params)}}}],"""
        
        if rosparam_files:
            content += f"""
        parameters=[{', '.join(rosparam_files)}],"""
        
        content += """
        output='screen'
    )
    
"""
        content += f"    ld.add_action(node_{i+1})\n\n"
    
    # 结束函数
    content += """    return ld

if __name__ == '__main__':
    generate_launch_description()
"""
    
    return content

def main():
    # 查找所有.launch文件
    launch_files = []
    
    for root, dirs, files in os.walk('.'):
        for file in files:
            if file.endswith('.launch'):
                launch_files.append(os.path.join(root, file))
    
    print(f"找到 {len(launch_files)} 个.launch文件")
    
    # 转换每个文件
    for file_path in launch_files:
        convert_launch_file(file_path)
    
    print("所有launch文件转换完成!")

if __name__ == '__main__':
    main()

