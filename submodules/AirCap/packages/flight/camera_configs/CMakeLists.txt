cmake_minimum_required(VERSION 3.8)
project(camera_configs)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(camera_info_manager REQUIRED)

# Add executable
add_executable(camera_info_publisher_node
  src/CameraInfoPublisher.cpp
)

# Specify dependencies
ament_target_dependencies(camera_info_publisher_node
  rclcpp
  sensor_msgs
  camera_info_manager
)

# Install targets
install(TARGETS
  camera_info_publisher_node
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()

