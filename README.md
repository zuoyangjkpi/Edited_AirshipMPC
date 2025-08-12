# Edited AirshipMPC - ROS2 Jazzy Version

[![ROS2](https://img.shields.io/badge/ROS2-Jazzy-blue.svg)](https://docs.ros.org/en/jazzy/)
[![Ubuntu](https://img.shields.io/badge/Ubuntu-24.04-orange.svg)](https://ubuntu.com/)
[![Python](https://img.shields.io/badge/Python-3.10+-green.svg)](https://python.org/)
[![Conda](https://img.shields.io/badge/Conda-Supported-yellow.svg)](https://conda.io/)

![airship_cover_with_inlay](https://user-images.githubusercontent.com/32105268/192122387-465e4489-5635-44d2-ab37-2071c48651a0.png)

## 概述

本项目是 AirshipMPC 的 ROS2 Jazzy 版本，专为飞艇的模型预测控制（MPC）而设计。该项目已从 ROS1 Noetic 完全迁移到 ROS2 Jazzy，特别优化了 **Ubuntu 24.04** 和 **Conda 环境** 的支持。

**原始论文**: https://arxiv.org/abs/2209.13040

**演示视频**:<br>
[<img src="https://img.youtube.com/vi/ihS0_VRD_kk/0.jpg" width="300" alt="Youtube Video"/>](https://www.youtube.com/watch?v=ihS0_VRD_kk)

## 🚀 新特性 (ROS2 版本)

- ✅ **完全兼容 ROS2 Jazzy** - 所有包都已迁移到 ROS2
- ✅ **Ubuntu 24.04 优化** - 针对最新LTS版本优化
- ✅ **Conda 环境支持** - 完美支持 Miniconda/Anaconda 环境
- ✅ **Python 3.10+ 支持** - 利用最新Python特性
- ✅ **Python Launch 文件** - 所有 launch 文件都转换为 Python 格式
- ✅ **现代化 API** - 使用 rclcpp 和 rclpy 最新 API
- ✅ **改进的构建系统** - 使用 ament_cmake 和 colcon

## 📋 系统要求

### 推荐环境
- **操作系统**: Ubuntu 24.04 LTS (Noble Numbat)
- **ROS版本**: ROS2 Jazzy Jalisco
- **Python**: 3.10+ (推荐使用 Conda 环境)
- **内存**: 最少 8GB RAM（推荐 16GB）
- **存储**: 至少 15GB 可用空间

### 硬件要求
- **GPU**: 可选，用于神经网络检测（CUDA 支持）
- **注意**: 没有GPU时，SSD检测器将无法运行，飞艇将无法"看到"目标人员

## 🐍 Conda 环境设置（推荐）

### 1. 创建专用 Conda 环境
```bash
# 创建新环境
conda create -n airship_env python=3.10 -y

# 激活环境
conda activate airship_env

# 安装基础科学计算包
conda install numpy scipy matplotlib pandas -y
```

### 2. 安装 ROS2 Jazzy
```bash
# 添加 ROS2 源
sudo apt update && sudo apt install curl gnupg lsb-release
sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.asc | sudo apt-key add -
sudo sh -c 'echo "deb [arch=$(dpkg --print-architecture)] http://packages.ros.org/ros2/ubuntu $(lsb_release -cs) main" > /etc/apt/sources.list.d/ros2-latest.list'

# 安装 ROS2 Jazzy Desktop
sudo apt update
sudo apt install ros-jazzy-desktop python3-argcomplete python3-colcon-common-extensions -y
```

### 3. 安装 ROS2 依赖包
```bash
# 安装 ROS2 包（系统级别）
sudo apt install -y \
    ros-jazzy-cv-bridge \
    ros-jazzy-image-transport \
    ros-jazzy-tf2-ros \
    ros-jazzy-tf2-geometry-msgs \
    ros-jazzy-nav-msgs \
    ros-jazzy-sensor-msgs \
    ros-jazzy-geometry-msgs \
    ros-jazzy-std-msgs \
    ros-jazzy-visualization-msgs \
    ros-jazzy-gazebo-ros-pkgs \
    ros-jazzy-robot-state-publisher \
    ros-jazzy-joint-state-publisher \
    ros-jazzy-xacro
```

### 4. 安装 Python 依赖（在 Conda 环境中）
```bash
# 确保在 airship_env 环境中
conda activate airship_env

# 安装项目特定依赖
pip install casadi opengen torch torchvision torchaudio

# 安装 Rust（用于 opengen）
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh -s -- -y
source ~/.cargo/env
```

## 🛠️ 编译项目

### 1. 克隆项目
```bash
# 克隆 manus 分支（包含 ROS2 版本）
git clone --recursive -b manus https://github.com/zuoyangjkpi/Edited_AirshipMPC.git
cd Edited_AirshipMPC
```

### 2. 设置环境
```bash
# 激活 Conda 环境
conda activate airship_env

# 设置 ROS2 环境
source /opt/ros/jazzy/setup.bash

# 设置环境变量（重要！）
export PYTHONPATH=$CONDA_PREFIX/lib/python3.10/site-packages:$PYTHONPATH
export CMAKE_PREFIX_PATH=$CONDA_PREFIX:$CMAKE_PREFIX_PATH
```

### 3. 生成 MPC 求解器
```bash
# 进入 src 目录
cd src

# 生成求解器（需要 Rust）
python blimps_ros.py

# 返回项目根目录
cd ..
```

### 4. 编译项目
```bash
# 使用 colcon 编译
colcon build --symlink-install \
    --cmake-args -DCMAKE_BUILD_TYPE=Release \
    -DPython3_EXECUTABLE=$(which python)

# 设置工作空间环境
source install/setup.bash
```

### 5. 创建环境设置脚本
```bash
# 创建便捷的环境设置脚本
cat > setup_env.sh << 'EOF'
#!/bin/bash
echo "Setting up AirshipMPC ROS2 environment..."
conda activate airship_env
source /opt/ros/jazzy/setup.bash
source install/setup.bash
export PYTHONPATH=$CONDA_PREFIX/lib/python3.10/site-packages:$PYTHONPATH
export CMAKE_PREFIX_PATH=$CONDA_PREFIX:$CMAKE_PREFIX_PATH
echo "✅ Environment ready! Python: $(python --version)"
echo "✅ ROS2 packages available: $(ros2 pkg list | grep blimp | wc -l) blimp packages"
EOF

chmod +x setup_env.sh
```

## 🎮 使用方法

### 每次使用前设置环境
```bash
# 使用便捷脚本
source setup_env.sh

# 或手动设置
conda activate airship_env
source /opt/ros/jazzy/setup.bash
source install/setup.bash
```

### 基本启动
```bash
# 启动单个飞艇
ros2 launch blimp_nmpc_wrapper_node one_blimp.launch.py

# 启动仿真环境
ros2 launch aircap simulation.launch.py num_robots:=3

# 启动目标检测
ros2 launch neural_network_detector one_robot.launch.py
```

### 仿真演示
```bash
# Gazebo仿真（需要先设置环境）
cd experiments/sim
./airship_sim.sh 3

# MPC独立测试
cd src
python blimps_costtest.py
```

## 🔧 故障排除

### 常见问题

#### 1. Python 环境冲突
```bash
# 确保使用正确的 Python
which python  # 应该指向 conda 环境
python --version  # 应该是 3.10+
```

#### 2. ROS2 找不到 Python 包
```bash
# 重新设置 PYTHONPATH
export PYTHONPATH=$CONDA_PREFIX/lib/python3.10/site-packages:$PYTHONPATH
```

#### 3. 编译错误
```bash
# 清理并重新编译
rm -rf build install log
colcon build --symlink-install --cmake-args -DCMAKE_BUILD_TYPE=Release
```

#### 4. Submodule 问题
```bash
# 重新初始化 submodules
git submodule update --init --recursive --force
```

## 🐳 Docker 支持（可选）

如果您遇到环境问题，可以使用 Docker：

```bash
# 构建 Docker 镜像
docker build -t airship-ros2 .

# 运行容器
docker run -it --rm -v $(pwd):/workspace airship-ros2
```

## 📊 性能优化

### Ubuntu 24.04 特定优化
- 使用最新的 GCC 13 编译器
- 利用 Python 3.10+ 的性能改进
- 优化的内存管理

### Conda 环境优势
- 隔离的 Python 环境
- 更好的包版本管理
- 避免系统 Python 冲突

## 📚 文档

- [迁移报告](ROS1_to_ROS2_Migration_Report.md) - 详细的迁移过程
- [交付清单](DELIVERABLES.md) - 完整的文件清单
- [ROS2 Jazzy 文档](https://docs.ros.org/en/jazzy/)

## 🤝 贡献

- **项目维护者**: [zuoyangjkpi](https://github.com/zuoyangjkpi)
- **问题报告**: [GitHub Issues](https://github.com/zuoyangjkpi/Edited_AirshipMPC/issues)
- **原始项目**: [AirCap](https://github.com/robot-perception-group/AirCap)

## 📄 许可证

本项目采用 MIT 许可证 - 详见 [LICENSE](LICENSE) 文件。

---

## 🔄 从 ROS1 迁移

如果您之前使用的是 ROS1 版本，请参考 [迁移指南](ROS1_to_ROS2_Migration_Report.md) 了解详细的变更内容。

### 主要变更
- **构建系统**: catkin → ament_cmake
- **Python API**: rospy → rclpy  
- **C++ API**: ros → rclcpp
- **Launch 文件**: XML → Python
- **包格式**: format="2" → format="3"

---

**享受 Ubuntu 24.04 + ROS2 + Conda 带来的现代化开发体验！** 🚀
