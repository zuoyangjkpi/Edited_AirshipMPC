cmake_minimum_required(VERSION 3.8)
project(tf_from_uav_pose)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(uav_msgs REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)

# Include directories
include_directories(include)

# Declare a C++ executable
add_executable(${PROJECT_NAME}_node 
  src/tf_from_uav_pose_node.cpp
)

# Specify dependencies for the executable
ament_target_dependencies(${PROJECT_NAME}_node
  rclcpp
  tf2_ros
  geometry_msgs
  uav_msgs
  tf2_geometry_msgs
)

# Install targets
install(TARGETS
  ${PROJECT_NAME}_node
  DESTINATION lib/${PROJECT_NAME}
)

# Install header files
install(DIRECTORY include/
  DESTINATION include/
  FILES_MATCHING PATTERN "*.h"
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()

