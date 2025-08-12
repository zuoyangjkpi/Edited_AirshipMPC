# Edited AirshipMPC - ROS2 Jazzy Version

[![ROS2](https://img.shields.io/badge/ROS2-Jazzy-blue.svg)](https://docs.ros.org/en/jazzy/)
[![Ubuntu](https://img.shields.io/badge/Ubuntu-22.04-orange.svg)](https://ubuntu.com/)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)

![airship_cover_with_inlay](https://user-images.githubusercontent.com/32105268/192122387-465e4489-5635-44d2-ab37-2071c48651a0.png)

## 概述

本项目是 AirshipMPC 的 ROS2 Jazzy 版本，专为飞艇的模型预测控制（MPC）而设计。该项目已从 ROS1 Noetic 完全迁移到 ROS2 Jazzy，包含了完整的飞行控制、路径规划、目标跟踪和仿真功能。

**原始论文**: https://arxiv.org/abs/2209.13040

**演示视频**:<br>
[<img src="https://img.youtube.com/vi/ihS0_VRD_kk/0.jpg" width="300" alt="Youtube Video"/>](https://www.youtube.com/watch?v=ihS0_VRD_kk)

## 🚀 新特性 (ROS2 版本)

- ✅ **完全兼容 ROS2 Jazzy** - 所有包都已迁移到 ROS2
- ✅ **Python Launch 文件** - 所有 launch 文件都转换为 Python 格式
- ✅ **现代化 API** - 使用 rclcpp 和 rclpy 最新 API
- ✅ **改进的构建系统** - 使用 ament_cmake 和 colcon
- ✅ **更好的性能** - 利用 ROS2 的 DDS 通信优势

## 📋 系统要求

### 必需环境
- **操作系统**: Ubuntu 22.04 LTS
- **ROS版本**: ROS2 Jazzy Jalisco
- **Python**: 3.10+
- **CMake**: 3.16+
- **编译器**: GCC 11+ 或 Clang 12+

### 硬件要求
- **内存**: 最少 8GB RAM（推荐 16GB）
- **存储**: 至少 10GB 可用空间
- **GPU**: 可选，用于神经网络检测（CUDA 支持）

**注意**: 没有GPU时，SSD检测器将无法运行，飞艇将无法"看到"目标人员，会假设目标在地图中心并围绕该静止点飞行。

## 🛠️ 安装指南

### 快速安装
```bash
# 克隆仓库
git clone --recursive https://github.com/zuoyangjkpi/Edited_AirshipMPC.git
cd Edited_AirshipMPC

# 运行自动安装脚本
chmod +x install_and_compile.sh
./install_and_compile.sh
```

### 手动安装

#### 1. 安装 ROS2 Jazzy
```bash
# 添加 ROS2 源
sudo apt update && sudo apt install curl gnupg lsb-release
sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.asc | sudo apt-key add -
sudo sh -c 'echo "deb [arch=$(dpkg --print-architecture)] http://packages.ros.org/ros2/ubuntu $(lsb_release -cs) main" > /etc/apt/sources.list.d/ros2-latest.list'

# 安装 ROS2 Jazzy
sudo apt update
sudo apt install ros-jazzy-desktop python3-argcomplete
sudo apt install python3-colcon-common-extensions
```

#### 2. 安装依赖包
```bash
# ROS2 依赖
sudo apt install ros-jazzy-cv-bridge ros-jazzy-image-transport
sudo apt install ros-jazzy-tf2 ros-jazzy-tf2-ros ros-jazzy-tf2-geometry-msgs
sudo apt install ros-jazzy-nav-msgs ros-jazzy-sensor-msgs ros-jazzy-geometry-msgs
sudo apt install ros-jazzy-std-msgs ros-jazzy-visualization-msgs

# 系统依赖
sudo apt install python3-pip python3-numpy python3-scipy
sudo apt install libopencv-dev python3-opencv
sudo apt install libeigen3-dev libboost-all-dev

# Python 依赖
pip3 install casadi matplotlib numpy scipy
```

#### 3. 编译项目
```bash
# 设置环境
source /opt/ros/jazzy/setup.bash

# 编译
colcon build --symlink-install --cmake-args -DCMAKE_BUILD_TYPE=Release

# 设置环境变量
source install/setup.bash
```

## 🎮 使用方法

### 基本启动
```bash
# 启动单个飞艇
ros2 launch blimp_nmpc_wrapper_node one_blimp.launch.py

# 启动仿真环境（3个飞艇）
ros2 launch aircap simulation.launch.py num_robots:=3

# 启动目标检测
ros2 launch neural_network_detector one_robot.launch.py
```

### 仿真演示
```bash
# Gazebo仿真（带风力和人员跟踪）
cd experiments/sim
./airship_sim.sh 3

# 静止目标仿真
./airship_sim.sh 3 100 test arena_BLIMP_stat_target

# MPC独立测试
cd src
python3 blimps_costtest.py
```

### 参数配置
```bash
# 设置机器人ID和数量
ros2 launch blimp_nmpc_wrapper_node one_blimp.launch.py robotID:=1 numRobots:=3
```

## 🔧 配置和修改

### MPC参数调整
- **配置文件**: `src/blimp_nmpc_wrapper_node/nodes/formation_config.py`
- **包含内容**: MPC约束、编队数量、控制参数
- **注意**: 修改后需要重新编译

### 飞艇物理参数
- **浮力和刚性**: `submodules/AirCap/packages/3rdparty/airship_simulation/deflate_blimp.sh`
- **风力和环境**: `submodules/AirCap/packages/3rdparty/airship_simulation/blimp_description/urdf/description_plugin.xacro`
- **物理模型**: URDF格式的空气动力学属性

### 其他实验
- **脚本位置**: `submodules/AirCap/scripts/simulation/`
- **包含内容**: 标准AirCap多旋翼实验等

## 🚁 真实飞艇部署

### 硬件要求
- **飞控**: OpenPilot Revolution 或兼容飞控
- **计算平台**: NVIDIA Jetson TX1/TX2 或类似设备
- **连接**: USB连接，集成WiFi
- **网络**: 建议使用fkie_multimaster多主机设置

### 部署配置
```bash
# 多主机ROS2设置
export ROS_DOMAIN_ID=<unique_id>
export RMW_IMPLEMENTATION=rmw_cyclonedx_cpp
```

## 📊 性能优化

### ROS2 优势
- **更低延迟** - DDS 通信协议
- **更好的实时性** - 改进的调度机制
- **更强的安全性** - 内置安全特性
- **更好的扩展性** - 支持大规模部署

## 🔄 从 ROS1 迁移

如果您之前使用的是 ROS1 版本，请参考 [迁移指南](ROS1_to_ROS2_Migration_Report.md) 了解详细的变更内容。

### 主要变更
- **构建系统**: catkin → ament_cmake
- **Python API**: rospy → rclpy  
- **C++ API**: ros → rclcpp
- **Launch 文件**: XML → Python
- **包格式**: format="2" → format="3"

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

**享受 ROS2 带来的全新体验！** 🚀
