// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from neural_network_detector:msg/NeuralNetworkFeedback.idl
// generated code does not contain a copyright notice

#ifndef NEURAL_NETWORK_DETECTOR__MSG__DETAIL__NEURAL_NETWORK_FEEDBACK__BUILDER_HPP_
#define NEURAL_NETWORK_DETECTOR__MSG__DETAIL__NEURAL_NETWORK_FEEDBACK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "neural_network_detector/msg/detail/neural_network_feedback__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace neural_network_detector
{

namespace msg
{

namespace builder
{

class Init_NeuralNetworkFeedback_ycenter
{
public:
  explicit Init_NeuralNetworkFeedback_ycenter(::neural_network_detector::msg::NeuralNetworkFeedback & msg)
  : msg_(msg)
  {}
  ::neural_network_detector::msg::NeuralNetworkFeedback ycenter(::neural_network_detector::msg::NeuralNetworkFeedback::_ycenter_type arg)
  {
    msg_.ycenter = std::move(arg);
    return std::move(msg_);
  }

private:
  ::neural_network_detector::msg::NeuralNetworkFeedback msg_;
};

class Init_NeuralNetworkFeedback_feet_raw
{
public:
  explicit Init_NeuralNetworkFeedback_feet_raw(::neural_network_detector::msg::NeuralNetworkFeedback & msg)
  : msg_(msg)
  {}
  Init_NeuralNetworkFeedback_ycenter feet_raw(::neural_network_detector::msg::NeuralNetworkFeedback::_feet_raw_type arg)
  {
    msg_.feet_raw = std::move(arg);
    return Init_NeuralNetworkFeedback_ycenter(msg_);
  }

private:
  ::neural_network_detector::msg::NeuralNetworkFeedback msg_;
};

class Init_NeuralNetworkFeedback_head_raw
{
public:
  explicit Init_NeuralNetworkFeedback_head_raw(::neural_network_detector::msg::NeuralNetworkFeedback & msg)
  : msg_(msg)
  {}
  Init_NeuralNetworkFeedback_feet_raw head_raw(::neural_network_detector::msg::NeuralNetworkFeedback::_head_raw_type arg)
  {
    msg_.head_raw = std::move(arg);
    return Init_NeuralNetworkFeedback_feet_raw(msg_);
  }

private:
  ::neural_network_detector::msg::NeuralNetworkFeedback msg_;
};

class Init_NeuralNetworkFeedback_debug_included
{
public:
  explicit Init_NeuralNetworkFeedback_debug_included(::neural_network_detector::msg::NeuralNetworkFeedback & msg)
  : msg_(msg)
  {}
  Init_NeuralNetworkFeedback_head_raw debug_included(::neural_network_detector::msg::NeuralNetworkFeedback::_debug_included_type arg)
  {
    msg_.debug_included = std::move(arg);
    return Init_NeuralNetworkFeedback_head_raw(msg_);
  }

private:
  ::neural_network_detector::msg::NeuralNetworkFeedback msg_;
};

class Init_NeuralNetworkFeedback_xcenter
{
public:
  explicit Init_NeuralNetworkFeedback_xcenter(::neural_network_detector::msg::NeuralNetworkFeedback & msg)
  : msg_(msg)
  {}
  Init_NeuralNetworkFeedback_debug_included xcenter(::neural_network_detector::msg::NeuralNetworkFeedback::_xcenter_type arg)
  {
    msg_.xcenter = std::move(arg);
    return Init_NeuralNetworkFeedback_debug_included(msg_);
  }

private:
  ::neural_network_detector::msg::NeuralNetworkFeedback msg_;
};

class Init_NeuralNetworkFeedback_ymax
{
public:
  explicit Init_NeuralNetworkFeedback_ymax(::neural_network_detector::msg::NeuralNetworkFeedback & msg)
  : msg_(msg)
  {}
  Init_NeuralNetworkFeedback_xcenter ymax(::neural_network_detector::msg::NeuralNetworkFeedback::_ymax_type arg)
  {
    msg_.ymax = std::move(arg);
    return Init_NeuralNetworkFeedback_xcenter(msg_);
  }

private:
  ::neural_network_detector::msg::NeuralNetworkFeedback msg_;
};

class Init_NeuralNetworkFeedback_ymin
{
public:
  explicit Init_NeuralNetworkFeedback_ymin(::neural_network_detector::msg::NeuralNetworkFeedback & msg)
  : msg_(msg)
  {}
  Init_NeuralNetworkFeedback_ymax ymin(::neural_network_detector::msg::NeuralNetworkFeedback::_ymin_type arg)
  {
    msg_.ymin = std::move(arg);
    return Init_NeuralNetworkFeedback_ymax(msg_);
  }

private:
  ::neural_network_detector::msg::NeuralNetworkFeedback msg_;
};

class Init_NeuralNetworkFeedback_header
{
public:
  Init_NeuralNetworkFeedback_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NeuralNetworkFeedback_ymin header(::neural_network_detector::msg::NeuralNetworkFeedback::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_NeuralNetworkFeedback_ymin(msg_);
  }

private:
  ::neural_network_detector::msg::NeuralNetworkFeedback msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::neural_network_detector::msg::NeuralNetworkFeedback>()
{
  return neural_network_detector::msg::builder::Init_NeuralNetworkFeedback_header();
}

}  // namespace neural_network_detector

#endif  // NEURAL_NETWORK_DETECTOR__MSG__DETAIL__NEURAL_NETWORK_FEEDBACK__BUILDER_HPP_
