#!/usr/bin/env python3
import os
import re
import glob

def fix_project_name(cmake_file):
    """修复CMakeLists.txt中的项目名称"""
    try:
        # 从路径推断正确的项目名
        dir_path = os.path.dirname(cmake_file)
        project_name = os.path.basename(dir_path)
        
        with open(cmake_file, 'r') as f:
            content = f.read()
        
        # 替换project(unknown_project)为正确的项目名
        content = re.sub(r'project\(unknown_project\)', f'project({project_name})', content)
        
        with open(cmake_file, 'w') as f:
            f.write(content)
        
        print(f"Fixed project name in {cmake_file}: {project_name}")
        return True
    except Exception as e:
        print(f"Error fixing {cmake_file}: {e}")
        return False

def main():
    # 找到所有CMakeLists.txt文件
    cmake_files = glob.glob('submodules/**/CMakeLists.txt', recursive=True)
    
    for cmake_file in cmake_files:
        fix_project_name(cmake_file)
    
    print("All project names fixed!")

if __name__ == "__main__":
    main()
