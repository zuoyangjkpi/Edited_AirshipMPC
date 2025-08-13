// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from neural_network_detector:msg/NeuralNetworkDetectionArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "neural_network_detector/msg/detail/neural_network_detection_array__rosidl_typesupport_introspection_c.h"
#include "neural_network_detector/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "neural_network_detector/msg/detail/neural_network_detection_array__functions.h"
#include "neural_network_detector/msg/detail/neural_network_detection_array__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `detections`
#include "neural_network_detector/msg/neural_network_detection.h"
// Member `detections`
#include "neural_network_detector/msg/detail/neural_network_detection__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void neural_network_detector__msg__NeuralNetworkDetectionArray__rosidl_typesupport_introspection_c__NeuralNetworkDetectionArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  neural_network_detector__msg__NeuralNetworkDetectionArray__init(message_memory);
}

void neural_network_detector__msg__NeuralNetworkDetectionArray__rosidl_typesupport_introspection_c__NeuralNetworkDetectionArray_fini_function(void * message_memory)
{
  neural_network_detector__msg__NeuralNetworkDetectionArray__fini(message_memory);
}

size_t neural_network_detector__msg__NeuralNetworkDetectionArray__rosidl_typesupport_introspection_c__size_function__NeuralNetworkDetectionArray__detections(
  const void * untyped_member)
{
  const neural_network_detector__msg__NeuralNetworkDetection__Sequence * member =
    (const neural_network_detector__msg__NeuralNetworkDetection__Sequence *)(untyped_member);
  return member->size;
}

const void * neural_network_detector__msg__NeuralNetworkDetectionArray__rosidl_typesupport_introspection_c__get_const_function__NeuralNetworkDetectionArray__detections(
  const void * untyped_member, size_t index)
{
  const neural_network_detector__msg__NeuralNetworkDetection__Sequence * member =
    (const neural_network_detector__msg__NeuralNetworkDetection__Sequence *)(untyped_member);
  return &member->data[index];
}

void * neural_network_detector__msg__NeuralNetworkDetectionArray__rosidl_typesupport_introspection_c__get_function__NeuralNetworkDetectionArray__detections(
  void * untyped_member, size_t index)
{
  neural_network_detector__msg__NeuralNetworkDetection__Sequence * member =
    (neural_network_detector__msg__NeuralNetworkDetection__Sequence *)(untyped_member);
  return &member->data[index];
}

void neural_network_detector__msg__NeuralNetworkDetectionArray__rosidl_typesupport_introspection_c__fetch_function__NeuralNetworkDetectionArray__detections(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const neural_network_detector__msg__NeuralNetworkDetection * item =
    ((const neural_network_detector__msg__NeuralNetworkDetection *)
    neural_network_detector__msg__NeuralNetworkDetectionArray__rosidl_typesupport_introspection_c__get_const_function__NeuralNetworkDetectionArray__detections(untyped_member, index));
  neural_network_detector__msg__NeuralNetworkDetection * value =
    (neural_network_detector__msg__NeuralNetworkDetection *)(untyped_value);
  *value = *item;
}

void neural_network_detector__msg__NeuralNetworkDetectionArray__rosidl_typesupport_introspection_c__assign_function__NeuralNetworkDetectionArray__detections(
  void * untyped_member, size_t index, const void * untyped_value)
{
  neural_network_detector__msg__NeuralNetworkDetection * item =
    ((neural_network_detector__msg__NeuralNetworkDetection *)
    neural_network_detector__msg__NeuralNetworkDetectionArray__rosidl_typesupport_introspection_c__get_function__NeuralNetworkDetectionArray__detections(untyped_member, index));
  const neural_network_detector__msg__NeuralNetworkDetection * value =
    (const neural_network_detector__msg__NeuralNetworkDetection *)(untyped_value);
  *item = *value;
}

bool neural_network_detector__msg__NeuralNetworkDetectionArray__rosidl_typesupport_introspection_c__resize_function__NeuralNetworkDetectionArray__detections(
  void * untyped_member, size_t size)
{
  neural_network_detector__msg__NeuralNetworkDetection__Sequence * member =
    (neural_network_detector__msg__NeuralNetworkDetection__Sequence *)(untyped_member);
  neural_network_detector__msg__NeuralNetworkDetection__Sequence__fini(member);
  return neural_network_detector__msg__NeuralNetworkDetection__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember neural_network_detector__msg__NeuralNetworkDetectionArray__rosidl_typesupport_introspection_c__NeuralNetworkDetectionArray_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(neural_network_detector__msg__NeuralNetworkDetectionArray, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "detections",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(neural_network_detector__msg__NeuralNetworkDetectionArray, detections),  // bytes offset in struct
    NULL,  // default value
    neural_network_detector__msg__NeuralNetworkDetectionArray__rosidl_typesupport_introspection_c__size_function__NeuralNetworkDetectionArray__detections,  // size() function pointer
    neural_network_detector__msg__NeuralNetworkDetectionArray__rosidl_typesupport_introspection_c__get_const_function__NeuralNetworkDetectionArray__detections,  // get_const(index) function pointer
    neural_network_detector__msg__NeuralNetworkDetectionArray__rosidl_typesupport_introspection_c__get_function__NeuralNetworkDetectionArray__detections,  // get(index) function pointer
    neural_network_detector__msg__NeuralNetworkDetectionArray__rosidl_typesupport_introspection_c__fetch_function__NeuralNetworkDetectionArray__detections,  // fetch(index, &value) function pointer
    neural_network_detector__msg__NeuralNetworkDetectionArray__rosidl_typesupport_introspection_c__assign_function__NeuralNetworkDetectionArray__detections,  // assign(index, value) function pointer
    neural_network_detector__msg__NeuralNetworkDetectionArray__rosidl_typesupport_introspection_c__resize_function__NeuralNetworkDetectionArray__detections  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers neural_network_detector__msg__NeuralNetworkDetectionArray__rosidl_typesupport_introspection_c__NeuralNetworkDetectionArray_message_members = {
  "neural_network_detector__msg",  // message namespace
  "NeuralNetworkDetectionArray",  // message name
  2,  // number of fields
  sizeof(neural_network_detector__msg__NeuralNetworkDetectionArray),
  neural_network_detector__msg__NeuralNetworkDetectionArray__rosidl_typesupport_introspection_c__NeuralNetworkDetectionArray_message_member_array,  // message members
  neural_network_detector__msg__NeuralNetworkDetectionArray__rosidl_typesupport_introspection_c__NeuralNetworkDetectionArray_init_function,  // function to initialize message memory (memory has to be allocated)
  neural_network_detector__msg__NeuralNetworkDetectionArray__rosidl_typesupport_introspection_c__NeuralNetworkDetectionArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t neural_network_detector__msg__NeuralNetworkDetectionArray__rosidl_typesupport_introspection_c__NeuralNetworkDetectionArray_message_type_support_handle = {
  0,
  &neural_network_detector__msg__NeuralNetworkDetectionArray__rosidl_typesupport_introspection_c__NeuralNetworkDetectionArray_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_neural_network_detector
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, neural_network_detector, msg, NeuralNetworkDetectionArray)() {
  neural_network_detector__msg__NeuralNetworkDetectionArray__rosidl_typesupport_introspection_c__NeuralNetworkDetectionArray_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  neural_network_detector__msg__NeuralNetworkDetectionArray__rosidl_typesupport_introspection_c__NeuralNetworkDetectionArray_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, neural_network_detector, msg, NeuralNetworkDetection)();
  if (!neural_network_detector__msg__NeuralNetworkDetectionArray__rosidl_typesupport_introspection_c__NeuralNetworkDetectionArray_message_type_support_handle.typesupport_identifier) {
    neural_network_detector__msg__NeuralNetworkDetectionArray__rosidl_typesupport_introspection_c__NeuralNetworkDetectionArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &neural_network_detector__msg__NeuralNetworkDetectionArray__rosidl_typesupport_introspection_c__NeuralNetworkDetectionArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
