// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from neural_network_detector:msg/NeuralNetworkDetection.idl
// generated code does not contain a copyright notice
#include "neural_network_detector/msg/detail/neural_network_detection__rosidl_typesupport_fastrtps_cpp.hpp"
#include "neural_network_detector/msg/detail/neural_network_detection__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace std_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Header &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  std_msgs::msg::Header &);
size_t get_serialized_size(
  const std_msgs::msg::Header &,
  size_t current_alignment);
size_t
max_serialized_size_Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs


namespace neural_network_detector
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_neural_network_detector
cdr_serialize(
  const neural_network_detector::msg::NeuralNetworkDetection & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.header,
    cdr);
  // Member: object_class
  cdr << ros_message.object_class;
  // Member: detection_score
  cdr << ros_message.detection_score;
  // Member: xmin
  cdr << ros_message.xmin;
  // Member: xmax
  cdr << ros_message.xmax;
  // Member: ymin
  cdr << ros_message.ymin;
  // Member: ymax
  cdr << ros_message.ymax;
  // Member: variance_xmin
  cdr << ros_message.variance_xmin;
  // Member: variance_xmax
  cdr << ros_message.variance_xmax;
  // Member: variance_ymin
  cdr << ros_message.variance_ymin;
  // Member: variance_ymax
  cdr << ros_message.variance_ymax;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_neural_network_detector
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  neural_network_detector::msg::NeuralNetworkDetection & ros_message)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.header);

  // Member: object_class
  cdr >> ros_message.object_class;

  // Member: detection_score
  cdr >> ros_message.detection_score;

  // Member: xmin
  cdr >> ros_message.xmin;

  // Member: xmax
  cdr >> ros_message.xmax;

  // Member: ymin
  cdr >> ros_message.ymin;

  // Member: ymax
  cdr >> ros_message.ymax;

  // Member: variance_xmin
  cdr >> ros_message.variance_xmin;

  // Member: variance_xmax
  cdr >> ros_message.variance_xmax;

  // Member: variance_ymin
  cdr >> ros_message.variance_ymin;

  // Member: variance_ymax
  cdr >> ros_message.variance_ymax;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_neural_network_detector
get_serialized_size(
  const neural_network_detector::msg::NeuralNetworkDetection & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: header

  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.header, current_alignment);
  // Member: object_class
  {
    size_t item_size = sizeof(ros_message.object_class);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: detection_score
  {
    size_t item_size = sizeof(ros_message.detection_score);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: xmin
  {
    size_t item_size = sizeof(ros_message.xmin);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: xmax
  {
    size_t item_size = sizeof(ros_message.xmax);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ymin
  {
    size_t item_size = sizeof(ros_message.ymin);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ymax
  {
    size_t item_size = sizeof(ros_message.ymax);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: variance_xmin
  {
    size_t item_size = sizeof(ros_message.variance_xmin);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: variance_xmax
  {
    size_t item_size = sizeof(ros_message.variance_xmax);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: variance_ymin
  {
    size_t item_size = sizeof(ros_message.variance_ymin);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: variance_ymax
  {
    size_t item_size = sizeof(ros_message.variance_ymax);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_neural_network_detector
max_serialized_size_NeuralNetworkDetection(
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


  // Member: header
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: object_class
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: detection_score
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: xmin
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: xmax
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: ymin
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: ymax
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: variance_xmin
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: variance_xmax
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: variance_ymin
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: variance_ymax
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
    using DataType = neural_network_detector::msg::NeuralNetworkDetection;
    is_plain =
      (
      offsetof(DataType, variance_ymax) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _NeuralNetworkDetection__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const neural_network_detector::msg::NeuralNetworkDetection *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _NeuralNetworkDetection__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<neural_network_detector::msg::NeuralNetworkDetection *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _NeuralNetworkDetection__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const neural_network_detector::msg::NeuralNetworkDetection *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _NeuralNetworkDetection__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_NeuralNetworkDetection(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _NeuralNetworkDetection__callbacks = {
  "neural_network_detector::msg",
  "NeuralNetworkDetection",
  _NeuralNetworkDetection__cdr_serialize,
  _NeuralNetworkDetection__cdr_deserialize,
  _NeuralNetworkDetection__get_serialized_size,
  _NeuralNetworkDetection__max_serialized_size
};

static rosidl_message_type_support_t _NeuralNetworkDetection__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_NeuralNetworkDetection__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace neural_network_detector

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_neural_network_detector
const rosidl_message_type_support_t *
get_message_type_support_handle<neural_network_detector::msg::NeuralNetworkDetection>()
{
  return &neural_network_detector::msg::typesupport_fastrtps_cpp::_NeuralNetworkDetection__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, neural_network_detector, msg, NeuralNetworkDetection)() {
  return &neural_network_detector::msg::typesupport_fastrtps_cpp::_NeuralNetworkDetection__handle;
}

#ifdef __cplusplus
}
#endif
