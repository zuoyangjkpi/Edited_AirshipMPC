// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from neural_network_detector:msg/NeuralNetworkDetection.idl
// generated code does not contain a copyright notice
#include "neural_network_detector/msg/detail/neural_network_detection__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "neural_network_detector/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "neural_network_detector/msg/detail/neural_network_detection__struct.h"
#include "neural_network_detector/msg/detail/neural_network_detection__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_neural_network_detector
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_neural_network_detector
size_t max_serialized_size_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_neural_network_detector
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Header)();


using _NeuralNetworkDetection__ros_msg_type = neural_network_detector__msg__NeuralNetworkDetection;

static bool _NeuralNetworkDetection__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _NeuralNetworkDetection__ros_msg_type * ros_message = static_cast<const _NeuralNetworkDetection__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->header, cdr))
    {
      return false;
    }
  }

  // Field name: object_class
  {
    cdr << ros_message->object_class;
  }

  // Field name: detection_score
  {
    cdr << ros_message->detection_score;
  }

  // Field name: xmin
  {
    cdr << ros_message->xmin;
  }

  // Field name: xmax
  {
    cdr << ros_message->xmax;
  }

  // Field name: ymin
  {
    cdr << ros_message->ymin;
  }

  // Field name: ymax
  {
    cdr << ros_message->ymax;
  }

  // Field name: variance_xmin
  {
    cdr << ros_message->variance_xmin;
  }

  // Field name: variance_xmax
  {
    cdr << ros_message->variance_xmax;
  }

  // Field name: variance_ymin
  {
    cdr << ros_message->variance_ymin;
  }

  // Field name: variance_ymax
  {
    cdr << ros_message->variance_ymax;
  }

  return true;
}

static bool _NeuralNetworkDetection__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _NeuralNetworkDetection__ros_msg_type * ros_message = static_cast<_NeuralNetworkDetection__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->header))
    {
      return false;
    }
  }

  // Field name: object_class
  {
    cdr >> ros_message->object_class;
  }

  // Field name: detection_score
  {
    cdr >> ros_message->detection_score;
  }

  // Field name: xmin
  {
    cdr >> ros_message->xmin;
  }

  // Field name: xmax
  {
    cdr >> ros_message->xmax;
  }

  // Field name: ymin
  {
    cdr >> ros_message->ymin;
  }

  // Field name: ymax
  {
    cdr >> ros_message->ymax;
  }

  // Field name: variance_xmin
  {
    cdr >> ros_message->variance_xmin;
  }

  // Field name: variance_xmax
  {
    cdr >> ros_message->variance_xmax;
  }

  // Field name: variance_ymin
  {
    cdr >> ros_message->variance_ymin;
  }

  // Field name: variance_ymax
  {
    cdr >> ros_message->variance_ymax;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_neural_network_detector
size_t get_serialized_size_neural_network_detector__msg__NeuralNetworkDetection(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _NeuralNetworkDetection__ros_msg_type * ros_message = static_cast<const _NeuralNetworkDetection__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name header

  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);
  // field.name object_class
  {
    size_t item_size = sizeof(ros_message->object_class);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name detection_score
  {
    size_t item_size = sizeof(ros_message->detection_score);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name xmin
  {
    size_t item_size = sizeof(ros_message->xmin);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name xmax
  {
    size_t item_size = sizeof(ros_message->xmax);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ymin
  {
    size_t item_size = sizeof(ros_message->ymin);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ymax
  {
    size_t item_size = sizeof(ros_message->ymax);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name variance_xmin
  {
    size_t item_size = sizeof(ros_message->variance_xmin);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name variance_xmax
  {
    size_t item_size = sizeof(ros_message->variance_xmax);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name variance_ymin
  {
    size_t item_size = sizeof(ros_message->variance_ymin);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name variance_ymax
  {
    size_t item_size = sizeof(ros_message->variance_ymax);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _NeuralNetworkDetection__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_neural_network_detector__msg__NeuralNetworkDetection(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_neural_network_detector
size_t max_serialized_size_neural_network_detector__msg__NeuralNetworkDetection(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: header
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: object_class
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: detection_score
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: xmin
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: xmax
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: ymin
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: ymax
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: variance_xmin
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: variance_xmax
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: variance_ymin
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: variance_ymax
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = neural_network_detector__msg__NeuralNetworkDetection;
    is_plain =
      (
      offsetof(DataType, variance_ymax) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _NeuralNetworkDetection__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_neural_network_detector__msg__NeuralNetworkDetection(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_NeuralNetworkDetection = {
  "neural_network_detector::msg",
  "NeuralNetworkDetection",
  _NeuralNetworkDetection__cdr_serialize,
  _NeuralNetworkDetection__cdr_deserialize,
  _NeuralNetworkDetection__get_serialized_size,
  _NeuralNetworkDetection__max_serialized_size
};

static rosidl_message_type_support_t _NeuralNetworkDetection__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_NeuralNetworkDetection,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, neural_network_detector, msg, NeuralNetworkDetection)() {
  return &_NeuralNetworkDetection__type_support;
}

#if defined(__cplusplus)
}
#endif
