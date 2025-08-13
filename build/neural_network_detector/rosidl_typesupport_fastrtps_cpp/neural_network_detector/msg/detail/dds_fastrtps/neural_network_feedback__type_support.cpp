// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from neural_network_detector:msg/NeuralNetworkFeedback.idl
// generated code does not contain a copyright notice
#include "neural_network_detector/msg/detail/neural_network_feedback__rosidl_typesupport_fastrtps_cpp.hpp"
#include "neural_network_detector/msg/detail/neural_network_feedback__struct.hpp"

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
  const neural_network_detector::msg::NeuralNetworkFeedback & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.header,
    cdr);
  // Member: ymin
  cdr << ros_message.ymin;
  // Member: ymax
  cdr << ros_message.ymax;
  // Member: xcenter
  cdr << ros_message.xcenter;
  // Member: debug_included
  cdr << (ros_message.debug_included ? true : false);
  // Member: head_raw
  cdr << ros_message.head_raw;
  // Member: feet_raw
  cdr << ros_message.feet_raw;
  // Member: ycenter
  cdr << ros_message.ycenter;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_neural_network_detector
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  neural_network_detector::msg::NeuralNetworkFeedback & ros_message)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.header);

  // Member: ymin
  cdr >> ros_message.ymin;

  // Member: ymax
  cdr >> ros_message.ymax;

  // Member: xcenter
  cdr >> ros_message.xcenter;

  // Member: debug_included
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.debug_included = tmp ? true : false;
  }

  // Member: head_raw
  cdr >> ros_message.head_raw;

  // Member: feet_raw
  cdr >> ros_message.feet_raw;

  // Member: ycenter
  cdr >> ros_message.ycenter;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_neural_network_detector
get_serialized_size(
  const neural_network_detector::msg::NeuralNetworkFeedback & ros_message,
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
  // Member: xcenter
  {
    size_t item_size = sizeof(ros_message.xcenter);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: debug_included
  {
    size_t item_size = sizeof(ros_message.debug_included);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: head_raw
  {
    size_t item_size = sizeof(ros_message.head_raw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: feet_raw
  {
    size_t item_size = sizeof(ros_message.feet_raw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ycenter
  {
    size_t item_size = sizeof(ros_message.ycenter);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_neural_network_detector
max_serialized_size_NeuralNetworkFeedback(
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

  // Member: xcenter
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: debug_included
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: head_raw
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: feet_raw
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: ycenter
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = neural_network_detector::msg::NeuralNetworkFeedback;
    is_plain =
      (
      offsetof(DataType, ycenter) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _NeuralNetworkFeedback__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const neural_network_detector::msg::NeuralNetworkFeedback *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _NeuralNetworkFeedback__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<neural_network_detector::msg::NeuralNetworkFeedback *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _NeuralNetworkFeedback__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const neural_network_detector::msg::NeuralNetworkFeedback *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _NeuralNetworkFeedback__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_NeuralNetworkFeedback(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _NeuralNetworkFeedback__callbacks = {
  "neural_network_detector::msg",
  "NeuralNetworkFeedback",
  _NeuralNetworkFeedback__cdr_serialize,
  _NeuralNetworkFeedback__cdr_deserialize,
  _NeuralNetworkFeedback__get_serialized_size,
  _NeuralNetworkFeedback__max_serialized_size
};

static rosidl_message_type_support_t _NeuralNetworkFeedback__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_NeuralNetworkFeedback__callbacks,
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
get_message_type_support_handle<neural_network_detector::msg::NeuralNetworkFeedback>()
{
  return &neural_network_detector::msg::typesupport_fastrtps_cpp::_NeuralNetworkFeedback__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, neural_network_detector, msg, NeuralNetworkFeedback)() {
  return &neural_network_detector::msg::typesupport_fastrtps_cpp::_NeuralNetworkFeedback__handle;
}

#ifdef __cplusplus
}
#endif
