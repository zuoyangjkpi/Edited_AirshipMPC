#!/usr/bin/env python3
"""
修复所有package.xml文件的export标签，确保colcon正确识别为ROS2包
"""

import os
import glob
import re

def fix_package_xml_export(package_xml_path):
    """修复package.xml的export标签"""
    try:
        with open(package_xml_path, 'r') as f:
            content = f.read()
        
        # 检查是否已经有正确的export标签
        if '<build_type>ament_cmake</build_type>' in content:
            return False  # 已经正确，不需要修改
        
        # 查找export标签
        export_pattern = r'<export>\s*<!--[^>]*-->\s*</export>'
        export_replacement = '''<export>
        <build_type>ament_cmake</build_type>
    </export>'''
        
        if re.search(export_pattern, content, re.DOTALL):
            # 替换现有的export标签
            new_content = re.sub(export_pattern, export_replacement, content, flags=re.DOTALL)
        else:
            # 如果没有export标签，在</package>前添加
            export_tag = '''
    <export>
        <build_type>ament_cmake</build_type>
    </export>
</package>'''
            new_content = content.replace('</package>', export_tag)
        
        # 写回文件
        with open(package_xml_path, 'w') as f:
            f.write(new_content)
        
        return True  # 已修改
        
    except Exception as e:
        print(f"❌ 修复 {package_xml_path} 时出错: {e}")
        return False

def main():
    """主函数"""
    # 查找所有submodules中的package.xml文件
    package_xml_files = glob.glob("submodules/**/package.xml", recursive=True)
    
    print(f"找到 {len(package_xml_files)} 个package.xml文件需要检查...")
    
    modified_count = 0
    for package_xml in package_xml_files:
        if fix_package_xml_export(package_xml):
            print(f"✅ 已修复 {package_xml}")
            modified_count += 1
        else:
            print(f"⏭️  跳过 {package_xml} (已正确)")
    
    print(f"\n🎉 修复完成！共修改了 {modified_count} 个文件")

if __name__ == "__main__":
    main()

