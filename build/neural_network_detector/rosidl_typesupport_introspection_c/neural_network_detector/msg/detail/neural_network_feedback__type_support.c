// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from neural_network_detector:msg/NeuralNetworkFeedback.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "neural_network_detector/msg/detail/neural_network_feedback__rosidl_typesupport_introspection_c.h"
#include "neural_network_detector/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "neural_network_detector/msg/detail/neural_network_feedback__functions.h"
#include "neural_network_detector/msg/detail/neural_network_feedback__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void neural_network_detector__msg__NeuralNetworkFeedback__rosidl_typesupport_introspection_c__NeuralNetworkFeedback_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  neural_network_detector__msg__NeuralNetworkFeedback__init(message_memory);
}

void neural_network_detector__msg__NeuralNetworkFeedback__rosidl_typesupport_introspection_c__NeuralNetworkFeedback_fini_function(void * message_memory)
{
  neural_network_detector__msg__NeuralNetworkFeedback__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember neural_network_detector__msg__NeuralNetworkFeedback__rosidl_typesupport_introspection_c__NeuralNetworkFeedback_message_member_array[8] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(neural_network_detector__msg__NeuralNetworkFeedback, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ymin",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(neural_network_detector__msg__NeuralNetworkFeedback, ymin),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ymax",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(neural_network_detector__msg__NeuralNetworkFeedback, ymax),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "xcenter",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(neural_network_detector__msg__NeuralNetworkFeedback, xcenter),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "debug_included",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(neural_network_detector__msg__NeuralNetworkFeedback, debug_included),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "head_raw",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(neural_network_detector__msg__NeuralNetworkFeedback, head_raw),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "feet_raw",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(neural_network_detector__msg__NeuralNetworkFeedback, feet_raw),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ycenter",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(neural_network_detector__msg__NeuralNetworkFeedback, ycenter),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers neural_network_detector__msg__NeuralNetworkFeedback__rosidl_typesupport_introspection_c__NeuralNetworkFeedback_message_members = {
  "neural_network_detector__msg",  // message namespace
  "NeuralNetworkFeedback",  // message name
  8,  // number of fields
  sizeof(neural_network_detector__msg__NeuralNetworkFeedback),
  neural_network_detector__msg__NeuralNetworkFeedback__rosidl_typesupport_introspection_c__NeuralNetworkFeedback_message_member_array,  // message members
  neural_network_detector__msg__NeuralNetworkFeedback__rosidl_typesupport_introspection_c__NeuralNetworkFeedback_init_function,  // function to initialize message memory (memory has to be allocated)
  neural_network_detector__msg__NeuralNetworkFeedback__rosidl_typesupport_introspection_c__NeuralNetworkFeedback_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t neural_network_detector__msg__NeuralNetworkFeedback__rosidl_typesupport_introspection_c__NeuralNetworkFeedback_message_type_support_handle = {
  0,
  &neural_network_detector__msg__NeuralNetworkFeedback__rosidl_typesupport_introspection_c__NeuralNetworkFeedback_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_neural_network_detector
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, neural_network_detector, msg, NeuralNetworkFeedback)() {
  neural_network_detector__msg__NeuralNetworkFeedback__rosidl_typesupport_introspection_c__NeuralNetworkFeedback_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!neural_network_detector__msg__NeuralNetworkFeedback__rosidl_typesupport_introspection_c__NeuralNetworkFeedback_message_type_support_handle.typesupport_identifier) {
    neural_network_detector__msg__NeuralNetworkFeedback__rosidl_typesupport_introspection_c__NeuralNetworkFeedback_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &neural_network_detector__msg__NeuralNetworkFeedback__rosidl_typesupport_introspection_c__NeuralNetworkFeedback_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
