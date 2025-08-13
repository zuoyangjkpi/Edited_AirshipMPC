// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from neural_network_detector:msg/NeuralNetworkDetection.idl
// generated code does not contain a copyright notice

#ifndef NEURAL_NETWORK_DETECTOR__MSG__DETAIL__NEURAL_NETWORK_DETECTION__TRAITS_HPP_
#define NEURAL_NETWORK_DETECTOR__MSG__DETAIL__NEURAL_NETWORK_DETECTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "neural_network_detector/msg/detail/neural_network_detection__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace neural_network_detector
{

namespace msg
{

inline void to_flow_style_yaml(
  const NeuralNetworkDetection & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: object_class
  {
    out << "object_class: ";
    rosidl_generator_traits::value_to_yaml(msg.object_class, out);
    out << ", ";
  }

  // member: detection_score
  {
    out << "detection_score: ";
    rosidl_generator_traits::value_to_yaml(msg.detection_score, out);
    out << ", ";
  }

  // member: xmin
  {
    out << "xmin: ";
    rosidl_generator_traits::value_to_yaml(msg.xmin, out);
    out << ", ";
  }

  // member: xmax
  {
    out << "xmax: ";
    rosidl_generator_traits::value_to_yaml(msg.xmax, out);
    out << ", ";
  }

  // member: ymin
  {
    out << "ymin: ";
    rosidl_generator_traits::value_to_yaml(msg.ymin, out);
    out << ", ";
  }

  // member: ymax
  {
    out << "ymax: ";
    rosidl_generator_traits::value_to_yaml(msg.ymax, out);
    out << ", ";
  }

  // member: variance_xmin
  {
    out << "variance_xmin: ";
    rosidl_generator_traits::value_to_yaml(msg.variance_xmin, out);
    out << ", ";
  }

  // member: variance_xmax
  {
    out << "variance_xmax: ";
    rosidl_generator_traits::value_to_yaml(msg.variance_xmax, out);
    out << ", ";
  }

  // member: variance_ymin
  {
    out << "variance_ymin: ";
    rosidl_generator_traits::value_to_yaml(msg.variance_ymin, out);
    out << ", ";
  }

  // member: variance_ymax
  {
    out << "variance_ymax: ";
    rosidl_generator_traits::value_to_yaml(msg.variance_ymax, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NeuralNetworkDetection & msg,
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

  // member: object_class
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "object_class: ";
    rosidl_generator_traits::value_to_yaml(msg.object_class, out);
    out << "\n";
  }

  // member: detection_score
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "detection_score: ";
    rosidl_generator_traits::value_to_yaml(msg.detection_score, out);
    out << "\n";
  }

  // member: xmin
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "xmin: ";
    rosidl_generator_traits::value_to_yaml(msg.xmin, out);
    out << "\n";
  }

  // member: xmax
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "xmax: ";
    rosidl_generator_traits::value_to_yaml(msg.xmax, out);
    out << "\n";
  }

  // member: ymin
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ymin: ";
    rosidl_generator_traits::value_to_yaml(msg.ymin, out);
    out << "\n";
  }

  // member: ymax
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ymax: ";
    rosidl_generator_traits::value_to_yaml(msg.ymax, out);
    out << "\n";
  }

  // member: variance_xmin
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "variance_xmin: ";
    rosidl_generator_traits::value_to_yaml(msg.variance_xmin, out);
    out << "\n";
  }

  // member: variance_xmax
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "variance_xmax: ";
    rosidl_generator_traits::value_to_yaml(msg.variance_xmax, out);
    out << "\n";
  }

  // member: variance_ymin
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "variance_ymin: ";
    rosidl_generator_traits::value_to_yaml(msg.variance_ymin, out);
    out << "\n";
  }

  // member: variance_ymax
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "variance_ymax: ";
    rosidl_generator_traits::value_to_yaml(msg.variance_ymax, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NeuralNetworkDetection & msg, bool use_flow_style = false)
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
  const neural_network_detector::msg::NeuralNetworkDetection & msg,
  std::ostream & out, size_t indentation = 0)
{
  neural_network_detector::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use neural_network_detector::msg::to_yaml() instead")]]
inline std::string to_yaml(const neural_network_detector::msg::NeuralNetworkDetection & msg)
{
  return neural_network_detector::msg::to_yaml(msg);
}

template<>
inline const char * data_type<neural_network_detector::msg::NeuralNetworkDetection>()
{
  return "neural_network_detector::msg::NeuralNetworkDetection";
}

template<>
inline const char * name<neural_network_detector::msg::NeuralNetworkDetection>()
{
  return "neural_network_detector/msg/NeuralNetworkDetection";
}

template<>
struct has_fixed_size<neural_network_detector::msg::NeuralNetworkDetection>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<neural_network_detector::msg::NeuralNetworkDetection>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<neural_network_detector::msg::NeuralNetworkDetection>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // NEURAL_NETWORK_DETECTOR__MSG__DETAIL__NEURAL_NETWORK_DETECTION__TRAITS_HPP_
