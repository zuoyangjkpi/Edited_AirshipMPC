// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from neural_network_detector:msg/NeuralNetworkNumberOfDetections.idl
// generated code does not contain a copyright notice

#ifndef NEURAL_NETWORK_DETECTOR__MSG__DETAIL__NEURAL_NETWORK_NUMBER_OF_DETECTIONS__STRUCT_HPP_
#define NEURAL_NETWORK_DETECTOR__MSG__DETAIL__NEURAL_NETWORK_NUMBER_OF_DETECTIONS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__neural_network_detector__msg__NeuralNetworkNumberOfDetections __attribute__((deprecated))
#else
# define DEPRECATED__neural_network_detector__msg__NeuralNetworkNumberOfDetections __declspec(deprecated)
#endif

namespace neural_network_detector
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NeuralNetworkNumberOfDetections_
{
  using Type = NeuralNetworkNumberOfDetections_<ContainerAllocator>;

  explicit NeuralNetworkNumberOfDetections_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->data = 0;
    }
  }

  explicit NeuralNetworkNumberOfDetections_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->data = 0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _data_type =
    uint16_t;
  _data_type data;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__data(
    const uint16_t & _arg)
  {
    this->data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    neural_network_detector::msg::NeuralNetworkNumberOfDetections_<ContainerAllocator> *;
  using ConstRawPtr =
    const neural_network_detector::msg::NeuralNetworkNumberOfDetections_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<neural_network_detector::msg::NeuralNetworkNumberOfDetections_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<neural_network_detector::msg::NeuralNetworkNumberOfDetections_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      neural_network_detector::msg::NeuralNetworkNumberOfDetections_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<neural_network_detector::msg::NeuralNetworkNumberOfDetections_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      neural_network_detector::msg::NeuralNetworkNumberOfDetections_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<neural_network_detector::msg::NeuralNetworkNumberOfDetections_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<neural_network_detector::msg::NeuralNetworkNumberOfDetections_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<neural_network_detector::msg::NeuralNetworkNumberOfDetections_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__neural_network_detector__msg__NeuralNetworkNumberOfDetections
    std::shared_ptr<neural_network_detector::msg::NeuralNetworkNumberOfDetections_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__neural_network_detector__msg__NeuralNetworkNumberOfDetections
    std::shared_ptr<neural_network_detector::msg::NeuralNetworkNumberOfDetections_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NeuralNetworkNumberOfDetections_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->data != other.data) {
      return false;
    }
    return true;
  }
  bool operator!=(const NeuralNetworkNumberOfDetections_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NeuralNetworkNumberOfDetections_

// alias to use template instance with default allocator
using NeuralNetworkNumberOfDetections =
  neural_network_detector::msg::NeuralNetworkNumberOfDetections_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace neural_network_detector

#endif  // NEURAL_NETWORK_DETECTOR__MSG__DETAIL__NEURAL_NETWORK_NUMBER_OF_DETECTIONS__STRUCT_HPP_
