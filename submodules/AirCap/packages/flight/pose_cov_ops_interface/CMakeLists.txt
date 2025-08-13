cmake_minimum_required(VERSION 3.8)
project(pose_cov_ops_interface)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)

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
  tf2
  tf2_geometry_msgs
)

# Declare a C++ executable for testing (temporarily disabled)
# add_executable(${PROJECT_NAME}_test
#   test/test_interface.cpp
# )

# Specify dependencies for the executable (temporarily disabled)
# ament_target_dependencies(${PROJECT_NAME}_test
#   rclcpp
#   geometry_msgs
#   tf2
#   tf2_geometry_msgs
# )

# Link the library to the executable (temporarily disabled)
# target_link_libraries(${PROJECT_NAME}_test
#   ${PROJECT_NAME}
# )

# Install targets
install(TARGETS
  ${PROJECT_NAME}
  DESTINATION lib/${PROJECT_NAME}
)

# Install test executable (temporarily disabled)
# install(TARGETS
#   ${PROJECT_NAME}_test
#   DESTINATION lib/${PROJECT_NAME}
# )

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
ament_export_dependencies(rclcpp geometry_msgs tf2 tf2_geometry_msgs)

ament_package()

