// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from neural_network_detector:msg/NeuralNetworkDetectionArray.idl
// generated code does not contain a copyright notice

#ifndef NEURAL_NETWORK_DETECTOR__MSG__DETAIL__NEURAL_NETWORK_DETECTION_ARRAY__BUILDER_HPP_
#define NEURAL_NETWORK_DETECTOR__MSG__DETAIL__NEURAL_NETWORK_DETECTION_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "neural_network_detector/msg/detail/neural_network_detection_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace neural_network_detector
{

namespace msg
{

namespace builder
{

class Init_NeuralNetworkDetectionArray_detections
{
public:
  explicit Init_NeuralNetworkDetectionArray_detections(::neural_network_detector::msg::NeuralNetworkDetectionArray & msg)
  : msg_(msg)
  {}
  ::neural_network_detector::msg::NeuralNetworkDetectionArray detections(::neural_network_detector::msg::NeuralNetworkDetectionArray::_detections_type arg)
  {
    msg_.detections = std::move(arg);
    return std::move(msg_);
  }

private:
  ::neural_network_detector::msg::NeuralNetworkDetectionArray msg_;
};

class Init_NeuralNetworkDetectionArray_header
{
public:
  Init_NeuralNetworkDetectionArray_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NeuralNetworkDetectionArray_detections header(::neural_network_detector::msg::NeuralNetworkDetectionArray::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_NeuralNetworkDetectionArray_detections(msg_);
  }

private:
  ::neural_network_detector::msg::NeuralNetworkDetectionArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::neural_network_detector::msg::NeuralNetworkDetectionArray>()
{
  return neural_network_detector::msg::builder::Init_NeuralNetworkDetectionArray_header();
}

}  // namespace neural_network_detector

#endif  // NEURAL_NETWORK_DETECTOR__MSG__DETAIL__NEURAL_NETWORK_DETECTION_ARRAY__BUILDER_HPP_
