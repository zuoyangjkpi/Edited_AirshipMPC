// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from neural_network_detector:msg/NeuralNetworkNumberOfDetections.idl
// generated code does not contain a copyright notice

#ifndef NEURAL_NETWORK_DETECTOR__MSG__DETAIL__NEURAL_NETWORK_NUMBER_OF_DETECTIONS__TRAITS_HPP_
#define NEURAL_NETWORK_DETECTOR__MSG__DETAIL__NEURAL_NETWORK_NUMBER_OF_DETECTIONS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "neural_network_detector/msg/detail/neural_network_number_of_detections__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace neural_network_detector
{

namespace msg
{

inline void to_flow_style_yaml(
  const NeuralNetworkNumberOfDetections & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: data
  {
    out << "data: ";
    rosidl_generator_traits::value_to_yaml(msg.data, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NeuralNetworkNumberOfDetections & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "data: ";
    rosidl_generator_traits::value_to_yaml(msg.data, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NeuralNetworkNumberOfDetections & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace neural_network_detector

namespace rosidl_generator_traits
{

[[deprecated("use neural_network_detector::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const neural_network_detector::msg::NeuralNetworkNumberOfDetections & msg,
  std::ostream & out, size_t indentation = 0)
{
  neural_network_detector::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use neural_network_detector::msg::to_yaml() instead")]]
inline std::string to_yaml(const neural_network_detector::msg::NeuralNetworkNumberOfDetections & msg)
{
  return neural_network_detector::msg::to_yaml(msg);
}

template<>
inline const char * data_type<neural_network_detector::msg::NeuralNetworkNumberOfDetections>()
{
  return "neural_network_detector::msg::NeuralNetworkNumberOfDetections";
}

template<>
inline const char * name<neural_network_detector::msg::NeuralNetworkNumberOfDetections>()
{
  return "neural_network_detector/msg/NeuralNetworkNumberOfDetections";
}

template<>
struct has_fixed_size<neural_network_detector::msg::NeuralNetworkNumberOfDetections>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<neural_network_detector::msg::NeuralNetworkNumberOfDetections>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<neural_network_detector::msg::NeuralNetworkNumberOfDetections>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // NEURAL_NETWORK_DETECTOR__MSG__DETAIL__NEURAL_NETWORK_NUMBER_OF_DETECTIONS__TRAITS_HPP_
