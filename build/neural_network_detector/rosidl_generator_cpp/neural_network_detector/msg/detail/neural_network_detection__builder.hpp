// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from neural_network_detector:msg/NeuralNetworkDetection.idl
// generated code does not contain a copyright notice

#ifndef NEURAL_NETWORK_DETECTOR__MSG__DETAIL__NEURAL_NETWORK_DETECTION__BUILDER_HPP_
#define NEURAL_NETWORK_DETECTOR__MSG__DETAIL__NEURAL_NETWORK_DETECTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "neural_network_detector/msg/detail/neural_network_detection__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace neural_network_detector
{

namespace msg
{

namespace builder
{

class Init_NeuralNetworkDetection_variance_ymax
{
public:
  explicit Init_NeuralNetworkDetection_variance_ymax(::neural_network_detector::msg::NeuralNetworkDetection & msg)
  : msg_(msg)
  {}
  ::neural_network_detector::msg::NeuralNetworkDetection variance_ymax(::neural_network_detector::msg::NeuralNetworkDetection::_variance_ymax_type arg)
  {
    msg_.variance_ymax = std::move(arg);
    return std::move(msg_);
  }

private:
  ::neural_network_detector::msg::NeuralNetworkDetection msg_;
};

class Init_NeuralNetworkDetection_variance_ymin
{
public:
  explicit Init_NeuralNetworkDetection_variance_ymin(::neural_network_detector::msg::NeuralNetworkDetection & msg)
  : msg_(msg)
  {}
  Init_NeuralNetworkDetection_variance_ymax variance_ymin(::neural_network_detector::msg::NeuralNetworkDetection::_variance_ymin_type arg)
  {
    msg_.variance_ymin = std::move(arg);
    return Init_NeuralNetworkDetection_variance_ymax(msg_);
  }

private:
  ::neural_network_detector::msg::NeuralNetworkDetection msg_;
};

class Init_NeuralNetworkDetection_variance_xmax
{
public:
  explicit Init_NeuralNetworkDetection_variance_xmax(::neural_network_detector::msg::NeuralNetworkDetection & msg)
  : msg_(msg)
  {}
  Init_NeuralNetworkDetection_variance_ymin variance_xmax(::neural_network_detector::msg::NeuralNetworkDetection::_variance_xmax_type arg)
  {
    msg_.variance_xmax = std::move(arg);
    return Init_NeuralNetworkDetection_variance_ymin(msg_);
  }

private:
  ::neural_network_detector::msg::NeuralNetworkDetection msg_;
};

class Init_NeuralNetworkDetection_variance_xmin
{
public:
  explicit Init_NeuralNetworkDetection_variance_xmin(::neural_network_detector::msg::NeuralNetworkDetection & msg)
  : msg_(msg)
  {}
  Init_NeuralNetworkDetection_variance_xmax variance_xmin(::neural_network_detector::msg::NeuralNetworkDetection::_variance_xmin_type arg)
  {
    msg_.variance_xmin = std::move(arg);
    return Init_NeuralNetworkDetection_variance_xmax(msg_);
  }

private:
  ::neural_network_detector::msg::NeuralNetworkDetection msg_;
};

class Init_NeuralNetworkDetection_ymax
{
public:
  explicit Init_NeuralNetworkDetection_ymax(::neural_network_detector::msg::NeuralNetworkDetection & msg)
  : msg_(msg)
  {}
  Init_NeuralNetworkDetection_variance_xmin ymax(::neural_network_detector::msg::NeuralNetworkDetection::_ymax_type arg)
  {
    msg_.ymax = std::move(arg);
    return Init_NeuralNetworkDetection_variance_xmin(msg_);
  }

private:
  ::neural_network_detector::msg::NeuralNetworkDetection msg_;
};

class Init_NeuralNetworkDetection_ymin
{
public:
  explicit Init_NeuralNetworkDetection_ymin(::neural_network_detector::msg::NeuralNetworkDetection & msg)
  : msg_(msg)
  {}
  Init_NeuralNetworkDetection_ymax ymin(::neural_network_detector::msg::NeuralNetworkDetection::_ymin_type arg)
  {
    msg_.ymin = std::move(arg);
    return Init_NeuralNetworkDetection_ymax(msg_);
  }

private:
  ::neural_network_detector::msg::NeuralNetworkDetection msg_;
};

class Init_NeuralNetworkDetection_xmax
{
public:
  explicit Init_NeuralNetworkDetection_xmax(::neural_network_detector::msg::NeuralNetworkDetection & msg)
  : msg_(msg)
  {}
  Init_NeuralNetworkDetection_ymin xmax(::neural_network_detector::msg::NeuralNetworkDetection::_xmax_type arg)
  {
    msg_.xmax = std::move(arg);
    return Init_NeuralNetworkDetection_ymin(msg_);
  }

private:
  ::neural_network_detector::msg::NeuralNetworkDetection msg_;
};

class Init_NeuralNetworkDetection_xmin
{
public:
  explicit Init_NeuralNetworkDetection_xmin(::neural_network_detector::msg::NeuralNetworkDetection & msg)
  : msg_(msg)
  {}
  Init_NeuralNetworkDetection_xmax xmin(::neural_network_detector::msg::NeuralNetworkDetection::_xmin_type arg)
  {
    msg_.xmin = std::move(arg);
    return Init_NeuralNetworkDetection_xmax(msg_);
  }

private:
  ::neural_network_detector::msg::NeuralNetworkDetection msg_;
};

class Init_NeuralNetworkDetection_detection_score
{
public:
  explicit Init_NeuralNetworkDetection_detection_score(::neural_network_detector::msg::NeuralNetworkDetection & msg)
  : msg_(msg)
  {}
  Init_NeuralNetworkDetection_xmin detection_score(::neural_network_detector::msg::NeuralNetworkDetection::_detection_score_type arg)
  {
    msg_.detection_score = std::move(arg);
    return Init_NeuralNetworkDetection_xmin(msg_);
  }

private:
  ::neural_network_detector::msg::NeuralNetworkDetection msg_;
};

class Init_NeuralNetworkDetection_object_class
{
public:
  explicit Init_NeuralNetworkDetection_object_class(::neural_network_detector::msg::NeuralNetworkDetection & msg)
  : msg_(msg)
  {}
  Init_NeuralNetworkDetection_detection_score object_class(::neural_network_detector::msg::NeuralNetworkDetection::_object_class_type arg)
  {
    msg_.object_class = std::move(arg);
    return Init_NeuralNetworkDetection_detection_score(msg_);
  }

private:
  ::neural_network_detector::msg::NeuralNetworkDetection msg_;
};

class Init_NeuralNetworkDetection_header
{
public:
  Init_NeuralNetworkDetection_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NeuralNetworkDetection_object_class header(::neural_network_detector::msg::NeuralNetworkDetection::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_NeuralNetworkDetection_object_class(msg_);
  }

private:
  ::neural_network_detector::msg::NeuralNetworkDetection msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::neural_network_detector::msg::NeuralNetworkDetection>()
{
  return neural_network_detector::msg::builder::Init_NeuralNetworkDetection_header();
}

}  // namespace neural_network_detector

#endif  // NEURAL_NETWORK_DETECTOR__MSG__DETAIL__NEURAL_NETWORK_DETECTION__BUILDER_HPP_
