# ROS1 到 ROS2 Jazzy 迁移文件清单

## 概述
本文档列出了所有需要从ROS1迁移到ROS2 Jazzy的文件。这些文件分布在主仓库的src目录和两个submodules（AirCap和pytorch_ssd_server）中。

## 1. 主仓库 src 目录下的文件

### 1.1 blimp_nmpc_wrapper_node 包
- **package.xml** - 需要更新到ROS2格式
- **CMakeLists.txt** - 需要更新到ament_cmake格式
- **nodes/blimp_nmpc_wrapper_node.py** - 需要更新Python ROS API
- **nodes/formation_config.py** - 可能需要更新（如果包含ROS相关代码）
- **launch/one_blimp.launch** - 需要转换为Python launch文件

### 1.2 其他Python文件
- **blimps_costtest.py** - 需要检查是否包含ROS代码
- **blimps_ros.py** - 需要更新Python ROS API

## 2. AirCap Submodule 中的文件

### 2.1 Flight 包

#### 2.1.1 camera_configs
- **package.xml** - 需要更新到ROS2格式
- **CMakeLists.txt** - 需要更新到ament_cmake格式
- **src/CameraInfoPublisher.cpp** - 需要更新C++ ROS API
- **launch/*.launch** (6个文件) - 需要转换为Python launch文件

#### 2.1.2 diff_gps
- **package.xml** - 需要更新到ROS2格式
- **CMakeLists.txt** - 需要更新到ament_cmake格式
- **src/gps_serial.cpp** - 需要更新C++ ROS API
- **launch/*.launch** (2个文件) - 需要转换为Python launch文件

#### 2.1.3 generic_potential_field
- **package.xml** - 需要更新到ROS2格式
- **CMakeLists.txt** - 需要更新到ament_cmake格式
- **src/*.cpp** (3个文件) - 需要更新C++ ROS API
- **include/*.hpp** (3个文件) - 需要更新C++ ROS API

#### 2.1.4 neural_network_detector
- **package.xml** - 需要更新到ROS2格式
- **CMakeLists.txt** - 需要更新到ament_cmake格式
- **src/*.cpp** (3个文件) - 需要更新C++ ROS API
- **include/neural_network_detector/*.h** (3个文件) - 需要更新C++ ROS API
- **launch/*.launch** (2个文件) - 需要转换为Python launch文件

#### 2.1.5 nmpc_planner
- **package.xml** - 需要更新到ROS2格式
- **CMakeLists.txt** - 需要更新到ament_cmake格式
- **src/*.cpp** (多个文件) - 需要更新C++ ROS API
- **include/*.h** (多个文件) - 需要更新C++ ROS API
- **launch/*.launch** (多个文件) - 需要转换为Python launch文件

#### 2.1.6 pose_cov_ops_interface
- **package.xml** - 需要更新到ROS2格式
- **CMakeLists.txt** - 需要更新到ament_cmake格式
- **src/*.cpp** (多个文件) - 需要更新C++ ROS API

#### 2.1.7 projection_models/model_distance_from_height
- **package.xml** - 需要更新到ROS2格式
- **CMakeLists.txt** - 需要更新到ament_cmake格式
- **src/*.cpp** (多个文件) - 需要更新C++ ROS API

#### 2.1.8 target_tracker_distributed_kf
- **package.xml** - 需要更新到ROS2格式
- **CMakeLists.txt** - 需要更新到ament_cmake格式
- **src/*.cpp** (多个文件) - 需要更新C++ ROS API
- **launch/*.launch** (多个文件) - 需要转换为Python launch文件

#### 2.1.9 tf_from_uav_pose
- **package.xml** - 需要更新到ROS2格式
- **CMakeLists.txt** - 需要更新到ament_cmake格式
- **src/*.cpp** (多个文件) - 需要更新C++ ROS API

### 2.2 Optional 包

#### 2.2.1 basler_image_capture/Grab
- **package.xml** - 需要更新到ROS2格式
- **CMakeLists.txt** - 需要更新到ament_cmake格式
- **src/*.cpp** (多个文件) - 需要更新C++ ROS API

#### 2.2.2 gcs_visualization
- **package.xml** - 需要更新到ROS2格式
- **setup.py** - 需要更新到ROS2格式
- **src/gcs_visualization/*.py** (3个文件) - 需要更新Python ROS API

#### 2.2.3 ptgrey_image_capture/Grab
- **package.xml** - 需要更新到ROS2格式
- **CMakeLists.txt** - 需要更新到ament_cmake格式
- **src/*.cpp** (多个文件) - 需要更新C++ ROS API

### 2.3 Replay 包

#### 2.3.1 video_replay_only/Grab
- **package.xml** - 需要更新到ROS2格式
- **CMakeLists.txt** - 需要更新到ament_cmake格式
- **src/*.cpp** (多个文件) - 需要更新C++ ROS API

### 2.4 Simulation 包

#### 2.4.1 Gazebo_Plugins
- **package.xml** - 需要更新到ROS2格式
- **CMakeLists.txt** - 需要更新到ament_cmake格式

#### 2.4.2 aircap
- **package.xml** - 需要更新到ROS2格式
- **CMakeLists.txt** - 需要更新到ament_cmake格式
- **launch/*.launch** (4个文件) - 需要转换为Python launch文件

#### 2.4.3 fake_communication_failure
- **package.xml** - 需要更新到ROS2格式
- **CMakeLists.txt** - 需要更新到ament_cmake格式
- **launch/*.launch** (1个文件) - 需要转换为Python launch文件

#### 2.4.4 librepilot_gazebo_bridge
- **package.xml** - 需要更新到ROS2格式
- **CMakeLists.txt** - 需要更新到ament_cmake格式
- **launch/*.launch** (1个文件) - 需要转换为Python launch文件

#### 2.4.5 random_moving_target
- **package.xml** - 需要更新到ROS2格式
- **CMakeLists.txt** - 需要更新到ament_cmake格式
- **src/*.cpp** (4个文件) - 需要更新C++ ROS API
- **src/*.py** (1个文件) - 需要更新Python ROS API
- **launch/*.launch** (5个文件) - 需要转换为Python launch文件

### 2.5 Scripts
- **scripts/simulation/*.py** (7个文件) - 需要检查并更新Python ROS API

## 3. pytorch_ssd_server Submodule 中的文件

### 3.1 Python文件
- **binary_structs.py** - 需要检查是否包含ROS代码
- **model.py** - 需要检查是否包含ROS代码
- **server.py** - 需要检查是否包含ROS代码
- **utils.py** - 需要检查是否包含ROS代码

## 4. 其他需要考虑的文件

### 4.1 多主机设置
- **submodules/AirCap/packages/flight/multimaster_setup/mm_setup.launch** - 需要转换为Python launch文件

### 4.2 配置文件
- **src/blimp_nmpc_wrapper_node/rviz/formationflight-simulation.rviz** - 可能需要更新（RViz2兼容性）

## 总结

总计需要修改的文件类型：
- **package.xml文件**: 19个
- **CMakeLists.txt文件**: 18个
- **C++源文件**: 约50+个
- **C++头文件**: 约20+个
- **Python文件**: 约15个
- **Launch文件**: 约25个
- **其他配置文件**: 若干个

这是一个大规模的迁移项目，需要系统性地处理每个文件类型的ROS1到ROS2的转换。

