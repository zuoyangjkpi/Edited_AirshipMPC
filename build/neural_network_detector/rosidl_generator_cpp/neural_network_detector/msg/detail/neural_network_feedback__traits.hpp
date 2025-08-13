// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from neural_network_detector:msg/NeuralNetworkFeedback.idl
// generated code does not contain a copyright notice

#ifndef NEURAL_NETWORK_DETECTOR__MSG__DETAIL__NEURAL_NETWORK_FEEDBACK__TRAITS_HPP_
#define NEURAL_NETWORK_DETECTOR__MSG__DETAIL__NEURAL_NETWORK_FEEDBACK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "neural_network_detector/msg/detail/neural_network_feedback__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace neural_network_detector
{

namespace msg
{

inline void to_flow_style_yaml(
  const NeuralNetworkFeedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
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

  // member: xcenter
  {
    out << "xcenter: ";
    rosidl_generator_traits::value_to_yaml(msg.xcenter, out);
    out << ", ";
  }

  // member: debug_included
  {
    out << "debug_included: ";
    rosidl_generator_traits::value_to_yaml(msg.debug_included, out);
    out << ", ";
  }

  // member: head_raw
  {
    out << "head_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.head_raw, out);
    out << ", ";
  }

  // member: feet_raw
  {
    out << "feet_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.feet_raw, out);
    out << ", ";
  }

  // member: ycenter
  {
    out << "ycenter: ";
    rosidl_generator_traits::value_to_yaml(msg.ycenter, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NeuralNetworkFeedback & msg,
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

  // member: xcenter
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "xcenter: ";
    rosidl_generator_traits::value_to_yaml(msg.xcenter, out);
    out << "\n";
  }

  // member: debug_included
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "debug_included: ";
    rosidl_generator_traits::value_to_yaml(msg.debug_included, out);
    out << "\n";
  }

  // member: head_raw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "head_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.head_raw, out);
    out << "\n";
  }

  // member: feet_raw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feet_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.feet_raw, out);
    out << "\n";
  }

  // member: ycenter
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ycenter: ";
    rosidl_generator_traits::value_to_yaml(msg.ycenter, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NeuralNetworkFeedback & msg, bool use_flow_style = false)
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
  const neural_network_detector::msg::NeuralNetworkFeedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  neural_network_detector::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use neural_network_detector::msg::to_yaml() instead")]]
inline std::string to_yaml(const neural_network_detector::msg::NeuralNetworkFeedback & msg)
{
  return neural_network_detector::msg::to_yaml(msg);
}

template<>
inline const char * data_type<neural_network_detector::msg::NeuralNetworkFeedback>()
{
  return "neural_network_detector::msg::NeuralNetworkFeedback";
}

template<>
inline const char * name<neural_network_detector::msg::NeuralNetworkFeedback>()
{
  return "neural_network_detector/msg/NeuralNetworkFeedback";
}

template<>
struct has_fixed_size<neural_network_detector::msg::NeuralNetworkFeedback>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<neural_network_detector::msg::NeuralNetworkFeedback>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<neural_network_detector::msg::NeuralNetworkFeedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // NEURAL_NETWORK_DETECTOR__MSG__DETAIL__NEURAL_NETWORK_FEEDBACK__TRAITS_HPP_
