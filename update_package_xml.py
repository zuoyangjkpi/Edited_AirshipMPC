#!/usr/bin/env python3

import os
import re
import xml.etree.ElementTree as ET
from xml.dom import minidom

def update_package_xml(file_path):
    """更新package.xml文件从ROS1格式到ROS2格式"""
    print(f"正在更新: {file_path}")
    
    try:
        # 读取原始文件
        with open(file_path, 'r', encoding='utf-8') as f:
            content = f.read()
        
        # 解析XML
        root = ET.fromstring(content)
        
        # 更新format属性
        root.set('format', '3')
        
        # 更新license标签
        license_elem = root.find('license')
        if license_elem is not None:
            if license_elem.text == 'GPLv3':
                license_elem.text = 'GPL-3.0'
            elif license_elem.text == 'GPL3':
                license_elem.text = 'GPL-3.0'
        
        # 更新buildtool_depend
        buildtool_depends = root.findall('buildtool_depend')
        for elem in buildtool_depends:
            if elem.text == 'catkin':
                elem.text = 'ament_cmake'
        
        # 处理依赖项
        # 收集所有依赖项
        dependencies = set()
        
        # 收集build_depend
        for elem in root.findall('build_depend'):
            dep_name = elem.text
            if dep_name == 'roscpp':
                dependencies.add('rclcpp')
            elif dep_name == 'rospy':
                dependencies.add('rclpy')
            elif dep_name == 'message_generation':
                # 添加到build_depend，稍后处理
                pass
            else:
                dependencies.add(dep_name)
        
        # 收集run_depend和exec_depend
        for elem in root.findall('run_depend'):
            dep_name = elem.text
            if dep_name == 'roscpp':
                dependencies.add('rclcpp')
            elif dep_name == 'rospy':
                dependencies.add('rclpy')
            elif dep_name == 'message_runtime':
                # 稍后处理
                pass
            else:
                dependencies.add(dep_name)
        
        for elem in root.findall('exec_depend'):
            dep_name = elem.text
            if dep_name == 'roscpp':
                dependencies.add('rclcpp')
            elif dep_name == 'rospy':
                dependencies.add('rclpy')
            else:
                dependencies.add(dep_name)
        
        # 收集build_export_depend
        for elem in root.findall('build_export_depend'):
            dep_name = elem.text
            if dep_name == 'roscpp':
                dependencies.add('rclcpp')
            elif dep_name == 'rospy':
                dependencies.add('rclpy')
            else:
                dependencies.add(dep_name)
        
        # 删除所有旧的依赖标签
        for tag in ['build_depend', 'run_depend', 'exec_depend', 'build_export_depend']:
            for elem in root.findall(tag):
                root.remove(elem)
        
        # 在buildtool_depend之后添加新的depend标签
        buildtool_elem = root.find('buildtool_depend')
        if buildtool_elem is not None:
            insert_index = list(root).index(buildtool_elem) + 1
        else:
            insert_index = len(list(root))
        
        # 添加空行元素
        if buildtool_elem is not None:
            empty_line = ET.Element('temp')
            empty_line.text = '\n  '
            empty_line.tail = '\n  '
            root.insert(insert_index, empty_line)
            insert_index += 1
        
        # 添加depend标签
        for dep in sorted(dependencies):
            if dep and dep.strip():
                depend_elem = ET.Element('depend')
                depend_elem.text = dep
                depend_elem.tail = '\n  '
                root.insert(insert_index, depend_elem)
                insert_index += 1
        
        # 检查是否需要消息生成相关的依赖
        has_message_generation = any(elem.text == 'message_generation' for elem in ET.fromstring(content).findall('build_depend'))
        has_message_runtime = any(elem.text == 'message_runtime' for elem in ET.fromstring(content).findall('run_depend'))
        
        if has_message_generation or has_message_runtime:
            # 添加空行
            empty_line = ET.Element('temp')
            empty_line.text = '\n  '
            empty_line.tail = '\n  '
            root.insert(insert_index, empty_line)
            insert_index += 1
            
            # 添加rosidl相关依赖
            build_depend_elem = ET.Element('build_depend')
            build_depend_elem.text = 'rosidl_default_generators'
            build_depend_elem.tail = '\n  '
            root.insert(insert_index, build_depend_elem)
            insert_index += 1
            
            exec_depend_elem = ET.Element('exec_depend')
            exec_depend_elem.text = 'rosidl_default_runtime'
            exec_depend_elem.tail = '\n  '
            root.insert(insert_index, exec_depend_elem)
            insert_index += 1
        
        # 添加测试依赖
        # 添加空行
        empty_line = ET.Element('temp')
        empty_line.text = '\n  '
        empty_line.tail = '\n  '
        root.insert(insert_index, empty_line)
        insert_index += 1
        
        test_depend1 = ET.Element('test_depend')
        test_depend1.text = 'ament_lint_auto'
        test_depend1.tail = '\n  '
        root.insert(insert_index, test_depend1)
        insert_index += 1
        
        test_depend2 = ET.Element('test_depend')
        test_depend2.text = 'ament_lint_common'
        test_depend2.tail = '\n  '
        root.insert(insert_index, test_depend2)
        insert_index += 1
        
        # 更新export标签
        export_elem = root.find('export')
        if export_elem is not None:
            # 清空export内容
            export_elem.clear()
            export_elem.text = '\n    '
            export_elem.tail = '\n'
            
            # 添加build_type
            build_type_elem = ET.Element('build_type')
            build_type_elem.text = 'ament_cmake'
            build_type_elem.tail = '\n  '
            export_elem.append(build_type_elem)
        
        # 移除临时元素
        for elem in root.findall('temp'):
            root.remove(elem)
        
        # 转换为字符串
        rough_string = ET.tostring(root, encoding='unicode')
        
        # 美化XML
        reparsed = minidom.parseString(rough_string)
        pretty_xml = reparsed.toprettyxml(indent="  ")
        
        # 移除多余的空行
        lines = pretty_xml.split('\n')
        lines = [line for line in lines if line.strip()]
        pretty_xml = '\n'.join(lines[1:])  # 移除第一行的XML声明
        
        # 添加正确的XML声明
        final_xml = '<?xml version="1.0"?>\n' + pretty_xml
        
        # 写回文件
        with open(file_path, 'w', encoding='utf-8') as f:
            f.write(final_xml)
        
        print(f"成功更新: {file_path}")
        
    except Exception as e:
        print(f"更新失败 {file_path}: {e}")

def main():
    # 查找所有package.xml文件
    package_xml_files = []
    
    for root, dirs, files in os.walk('.'):
        for file in files:
            if file == 'package.xml':
                package_xml_files.append(os.path.join(root, file))
    
    print(f"找到 {len(package_xml_files)} 个package.xml文件")
    
    # 更新每个文件
    for file_path in package_xml_files:
        update_package_xml(file_path)
    
    print("所有package.xml文件更新完成!")

if __name__ == '__main__':
    main()

