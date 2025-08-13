#!/bin/bash
# ROS2修复应用脚本

echo "🔧 开始应用ROS2修复..."

# 备份原始submodules
if [ -d "submodules_backup" ]; then
    echo "⚠️  发现已存在的备份，跳过备份步骤"
else
    echo "📦 备份原始submodules..."
    cp -r submodules submodules_backup
fi

# 下载修复后的版本
echo "⬇️  下载修复后的包文件..."
if [ -f "ros2_fixed_packages.tar.gz" ]; then
    echo "✅ 找到本地修复包文件"
else
    echo "❌ 未找到修复包文件，请确保ros2_fixed_packages.tar.gz在当前目录"
    exit 1
fi

# 应用修复
echo "🔄 应用修复..."
rm -rf submodules
tar -xzf ros2_fixed_packages.tar.gz

echo "✅ 修复应用完成！"

# 验证结果
echo "🔍 验证修复结果..."
package_count=$(colcon list | wc -l)
ament_count=$(colcon list | grep -c "ros.ament_cmake")

echo "📊 包统计："
echo "  总包数: $package_count"
echo "  ROS2包数: $ament_count"

if [ "$ament_count" -gt 10 ]; then
    echo "🎉 修复成功！现在可以开始逐包测试编译了"
else
    echo "⚠️  修复可能不完整，请检查"
fi

echo ""
echo "📋 所有包列表："
colcon list

