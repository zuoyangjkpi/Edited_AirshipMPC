// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from neural_network_detector:msg/NeuralNetworkNumberOfDetections.idl
// generated code does not contain a copyright notice

#ifndef NEURAL_NETWORK_DETECTOR__MSG__DETAIL__NEURAL_NETWORK_NUMBER_OF_DETECTIONS__BUILDER_HPP_
#define NEURAL_NETWORK_DETECTOR__MSG__DETAIL__NEURAL_NETWORK_NUMBER_OF_DETECTIONS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "neural_network_detector/msg/detail/neural_network_number_of_detections__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace neural_network_detector
{

namespace msg
{

namespace builder
{

class Init_NeuralNetworkNumberOfDetections_data
{
public:
  explicit Init_NeuralNetworkNumberOfDetections_data(::neural_network_detector::msg::NeuralNetworkNumberOfDetections & msg)
  : msg_(msg)
  {}
  ::neural_network_detector::msg::NeuralNetworkNumberOfDetections data(::neural_network_detector::msg::NeuralNetworkNumberOfDetections::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::neural_network_detector::msg::NeuralNetworkNumberOfDetections msg_;
};

class Init_NeuralNetworkNumberOfDetections_header
{
public:
  Init_NeuralNetworkNumberOfDetections_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NeuralNetworkNumberOfDetections_data header(::neural_network_detector::msg::NeuralNetworkNumberOfDetections::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_NeuralNetworkNumberOfDetections_data(msg_);
  }

private:
  ::neural_network_detector::msg::NeuralNetworkNumberOfDetections msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::neural_network_detector::msg::NeuralNetworkNumberOfDetections>()
{
  return neural_network_detector::msg::builder::Init_NeuralNetworkNumberOfDetections_header();
}

}  // namespace neural_network_detector

#endif  // NEURAL_NETWORK_DETECTOR__MSG__DETAIL__NEURAL_NETWORK_NUMBER_OF_DETECTIONS__BUILDER_HPP_
