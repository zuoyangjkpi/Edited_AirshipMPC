cmake_minimum_required(VERSION 3.5)
project(blimp_nmpc_wrapper_node)

find_package(ament_cmake REQUIRED)
find_package(nmpc_blimp_formation_planner REQUIRED)
find_package(uav_msgs REQUIRED)

ament_export_dependencies(
  nmpc_blimp_formation_planner
  uav_msgs
)

install(
  PROGRAMS
    nodes/blimp_nmpc_wrapper_node.py
  DESTINATION lib/${PROJECT_NAME}
)

install(
  FILES
    nodes/formation_config.py
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()

