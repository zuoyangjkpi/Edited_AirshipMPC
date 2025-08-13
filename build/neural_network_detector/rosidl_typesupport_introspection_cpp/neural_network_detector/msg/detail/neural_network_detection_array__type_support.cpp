// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from neural_network_detector:msg/NeuralNetworkDetectionArray.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "neural_network_detector/msg/detail/neural_network_detection_array__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace neural_network_detector
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void NeuralNetworkDetectionArray_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) neural_network_detector::msg::NeuralNetworkDetectionArray(_init);
}

void NeuralNetworkDetectionArray_fini_function(void * message_memory)
{
  auto typed_message = static_cast<neural_network_detector::msg::NeuralNetworkDetectionArray *>(message_memory);
  typed_message->~NeuralNetworkDetectionArray();
}

size_t size_function__NeuralNetworkDetectionArray__detections(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<neural_network_detector::msg::NeuralNetworkDetection> *>(untyped_member);
  return member->size();
}

const void * get_const_function__NeuralNetworkDetectionArray__detections(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<neural_network_detector::msg::NeuralNetworkDetection> *>(untyped_member);
  return &member[index];
}

void * get_function__NeuralNetworkDetectionArray__detections(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<neural_network_detector::msg::NeuralNetworkDetection> *>(untyped_member);
  return &member[index];
}

void fetch_function__NeuralNetworkDetectionArray__detections(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const neural_network_detector::msg::NeuralNetworkDetection *>(
    get_const_function__NeuralNetworkDetectionArray__detections(untyped_member, index));
  auto & value = *reinterpret_cast<neural_network_detector::msg::NeuralNetworkDetection *>(untyped_value);
  value = item;
}

void assign_function__NeuralNetworkDetectionArray__detections(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<neural_network_detector::msg::NeuralNetworkDetection *>(
    get_function__NeuralNetworkDetectionArray__detections(untyped_member, index));
  const auto & value = *reinterpret_cast<const neural_network_detector::msg::NeuralNetworkDetection *>(untyped_value);
  item = value;
}

void resize_function__NeuralNetworkDetectionArray__detections(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<neural_network_detector::msg::NeuralNetworkDetection> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember NeuralNetworkDetectionArray_message_member_array[2] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(neural_network_detector::msg::NeuralNetworkDetectionArray, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "detections",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<neural_network_detector::msg::NeuralNetworkDetection>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(neural_network_detector::msg::NeuralNetworkDetectionArray, detections),  // bytes offset in struct
    nullptr,  // default value
    size_function__NeuralNetworkDetectionArray__detections,  // size() function pointer
    get_const_function__NeuralNetworkDetectionArray__detections,  // get_const(index) function pointer
    get_function__NeuralNetworkDetectionArray__detections,  // get(index) function pointer
    fetch_function__NeuralNetworkDetectionArray__detections,  // fetch(index, &value) function pointer
    assign_function__NeuralNetworkDetectionArray__detections,  // assign(index, value) function pointer
    resize_function__NeuralNetworkDetectionArray__detections  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers NeuralNetworkDetectionArray_message_members = {
  "neural_network_detector::msg",  // message namespace
  "NeuralNetworkDetectionArray",  // message name
  2,  // number of fields
  sizeof(neural_network_detector::msg::NeuralNetworkDetectionArray),
  NeuralNetworkDetectionArray_message_member_array,  // message members
  NeuralNetworkDetectionArray_init_function,  // function to initialize message memory (memory has to be allocated)
  NeuralNetworkDetectionArray_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t NeuralNetworkDetectionArray_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &NeuralNetworkDetectionArray_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace neural_network_detector


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<neural_network_detector::msg::NeuralNetworkDetectionArray>()
{
  return &::neural_network_detector::msg::rosidl_typesupport_introspection_cpp::NeuralNetworkDetectionArray_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, neural_network_detector, msg, NeuralNetworkDetectionArray)() {
  return &::neural_network_detector::msg::rosidl_typesupport_introspection_cpp::NeuralNetworkDetectionArray_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
