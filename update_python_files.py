#!/usr/bin/env python3

import os
import re

def update_python_file(file_path):
    """更新Python文件从ROS1格式到ROS2格式"""
    print(f"正在更新: {file_path}")
    
    try:
        # 读取原始文件
        with open(file_path, 'r', encoding='utf-8') as f:
            content = f.read()
        
        # 检查是否包含ROS相关代码
        if 'rospy' not in content and 'ros.' not in content:
            print(f"跳过 {file_path}: 不包含ROS代码")
            return
        
        # 备份原始内容
        original_content = content
        
        # 1. 更新import语句
        # rospy -> rclpy
        content = re.sub(r'import rospy', 'import rclpy', content)
        content = re.sub(r'from rospy import', 'from rclpy import', content)
        
        # 更新消息导入
        content = re.sub(r'from (\w+)\.msg import', r'from \1.msg import', content)
        
        # 2. 更新节点初始化
        # rospy.init_node() -> rclpy.init()
        content = re.sub(r'rospy\.init_node\([^)]+\)', 'rclpy.init()', content)
        
        # 3. 更新节点类定义（如果有的话）
        # 这需要更复杂的处理，暂时跳过
        
        # 4. 更新发布者和订阅者
        # rospy.Publisher -> self.create_publisher
        # 这需要在节点类的上下文中处理，暂时标记
        
        # 5. 更新日志
        content = re.sub(r'rospy\.loginfo', 'self.get_logger().info', content)
        content = re.sub(r'rospy\.logwarn', 'self.get_logger().warn', content)
        content = re.sub(r'rospy\.logerr', 'self.get_logger().error', content)
        content = re.sub(r'rospy\.logdebug', 'self.get_logger().debug', content)
        
        # 6. 更新时间相关
        content = re.sub(r'rospy\.Time\.now\(\)', 'self.get_clock().now().to_msg()', content)
        content = re.sub(r'rospy\.Duration\(([^)]+)\)', r'rclpy.duration.Duration(seconds=\1)', content)
        
        # 7. 更新spin
        content = re.sub(r'rospy\.spin\(\)', 'rclpy.spin(node)', content)
        content = re.sub(r'rospy\.sleep\(([^)]+)\)', r'time.sleep(\1)', content)
        
        # 8. 更新参数获取
        content = re.sub(r'rospy\.get_param\(([^)]+)\)', r'self.get_parameter(\1).value', content)
        
        # 9. 添加必要的import
        if 'rclpy' in content and 'import time' not in content and 'time.sleep' in content:
            content = 'import time\n' + content
        
        # 10. 更新shebang（如果存在）
        content = re.sub(r'#!/usr/bin/env python', '#!/usr/bin/env python3', content)
        
        # 写回文件
        with open(file_path, 'w', encoding='utf-8') as f:
            f.write(content)
        
        print(f"成功更新: {file_path}")
        
    except Exception as e:
        print(f"更新失败 {file_path}: {e}")

def main():
    # 查找所有Python文件
    python_files = []
    
    for root, dirs, files in os.walk('.'):
        for file in files:
            if file.endswith('.py'):
                python_files.append(os.path.join(root, file))
    
    print(f"找到 {len(python_files)} 个Python文件")
    
    # 过滤掉更新脚本本身
    python_files = [f for f in python_files if not f.endswith('update_package_xml.py') 
                   and not f.endswith('update_cmakelists.py') 
                   and not f.endswith('update_python_files.py')]
    
    print(f"需要检查 {len(python_files)} 个Python文件")
    
    # 更新每个文件
    for file_path in python_files:
        update_python_file(file_path)
    
    print("所有Python文件更新完成!")

if __name__ == '__main__':
    main()

