# generated from
# rosidl_cmake/cmake/template/rosidl_cmake_export_typesupport_targets.cmake.in

set(_exported_typesupport_targets
  "__rosidl_generator_c:neural_network_detector__rosidl_generator_c;__rosidl_typesupport_fastrtps_c:neural_network_detector__rosidl_typesupport_fastrtps_c;__rosidl_generator_cpp:neural_network_detector__rosidl_generator_cpp;__rosidl_typesupport_fastrtps_cpp:neural_network_detector__rosidl_typesupport_fastrtps_cpp;__rosidl_typesupport_introspection_c:neural_network_detector__rosidl_typesupport_introspection_c;__rosidl_typesupport_c:neural_network_detector__rosidl_typesupport_c;__rosidl_typesupport_introspection_cpp:neural_network_detector__rosidl_typesupport_introspection_cpp;__rosidl_typesupport_cpp:neural_network_detector__rosidl_typesupport_cpp;__rosidl_generator_py:neural_network_detector__rosidl_generator_py")

# populate neural_network_detector_TARGETS_<suffix>
if(NOT _exported_typesupport_targets STREQUAL "")
  # loop over typesupport targets
  foreach(_tuple ${_exported_typesupport_targets})
    string(REPLACE ":" ";" _tuple "${_tuple}")
    list(GET _tuple 0 _suffix)
    list(GET _tuple 1 _target)

    set(_target "neural_network_detector::${_target}")
    if(NOT TARGET "${_target}")
      # the exported target must exist
      message(WARNING "Package 'neural_network_detector' exports the typesupport target '${_target}' which doesn't exist")
    else()
      list(APPEND neural_network_detector_TARGETS${_suffix} "${_target}")
    endif()
  endforeach()
endif()
