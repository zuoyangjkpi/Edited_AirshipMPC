cmake_minimum_required(VERSION 3.8)
project(pose_cov_ops_interface)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(pose_cov_ops REQUIRED)

# Include directories
include_directories(include)

# Declare a C++ library
add_library(${PROJECT_NAME}
  src/${PROJECT_NAME}/pose_cov_ops_interface.cpp
)

# Specify dependencies for the library
ament_target_dependencies(${PROJECT_NAME}
  rclcpp
  geometry_msgs
  pose_cov_ops
)

# Declare a C++ executable for testing
add_executable(${PROJECT_NAME}_test
  test/test_interface.cpp
)

# Specify dependencies for the executable
ament_target_dependencies(${PROJECT_NAME}_test
  rclcpp
  geometry_msgs
  pose_cov_ops
)

# Link the library to the executable
target_link_libraries(${PROJECT_NAME}_test
  ${PROJECT_NAME}
)

# Install targets
install(TARGETS
  ${PROJECT_NAME}
  DESTINATION lib/${PROJECT_NAME}
)

install(TARGETS
  ${PROJECT_NAME}_test
  DESTINATION lib/${PROJECT_NAME}
)

# Install header files
install(DIRECTORY include/
  DESTINATION include
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

# Export dependencies
ament_export_include_directories(include)
ament_export_libraries(${PROJECT_NAME})
ament_export_dependencies(rclcpp geometry_msgs pose_cov_ops)

ament_package()

