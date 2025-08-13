// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from neural_network_detector:msg/NeuralNetworkFeedback.idl
// generated code does not contain a copyright notice

#ifndef NEURAL_NETWORK_DETECTOR__MSG__DETAIL__NEURAL_NETWORK_FEEDBACK__STRUCT_HPP_
#define NEURAL_NETWORK_DETECTOR__MSG__DETAIL__NEURAL_NETWORK_FEEDBACK__STRUCT_HPP_

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
# define DEPRECATED__neural_network_detector__msg__NeuralNetworkFeedback __attribute__((deprecated))
#else
# define DEPRECATED__neural_network_detector__msg__NeuralNetworkFeedback __declspec(deprecated)
#endif

namespace neural_network_detector
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NeuralNetworkFeedback_
{
  using Type = NeuralNetworkFeedback_<ContainerAllocator>;

  explicit NeuralNetworkFeedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ymin = 0;
      this->ymax = 0;
      this->xcenter = 0;
      this->debug_included = false;
      this->head_raw = 0;
      this->feet_raw = 0;
      this->ycenter = 0;
    }
  }

  explicit NeuralNetworkFeedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ymin = 0;
      this->ymax = 0;
      this->xcenter = 0;
      this->debug_included = false;
      this->head_raw = 0;
      this->feet_raw = 0;
      this->ycenter = 0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _ymin_type =
    int16_t;
  _ymin_type ymin;
  using _ymax_type =
    int16_t;
  _ymax_type ymax;
  using _xcenter_type =
    int16_t;
  _xcenter_type xcenter;
  using _debug_included_type =
    bool;
  _debug_included_type debug_included;
  using _head_raw_type =
    int16_t;
  _head_raw_type head_raw;
  using _feet_raw_type =
    int16_t;
  _feet_raw_type feet_raw;
  using _ycenter_type =
    int16_t;
  _ycenter_type ycenter;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__ymin(
    const int16_t & _arg)
  {
    this->ymin = _arg;
    return *this;
  }
  Type & set__ymax(
    const int16_t & _arg)
  {
    this->ymax = _arg;
    return *this;
  }
  Type & set__xcenter(
    const int16_t & _arg)
  {
    this->xcenter = _arg;
    return *this;
  }
  Type & set__debug_included(
    const bool & _arg)
  {
    this->debug_included = _arg;
    return *this;
  }
  Type & set__head_raw(
    const int16_t & _arg)
  {
    this->head_raw = _arg;
    return *this;
  }
  Type & set__feet_raw(
    const int16_t & _arg)
  {
    this->feet_raw = _arg;
    return *this;
  }
  Type & set__ycenter(
    const int16_t & _arg)
  {
    this->ycenter = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    neural_network_detector::msg::NeuralNetworkFeedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const neural_network_detector::msg::NeuralNetworkFeedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<neural_network_detector::msg::NeuralNetworkFeedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<neural_network_detector::msg::NeuralNetworkFeedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      neural_network_detector::msg::NeuralNetworkFeedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<neural_network_detector::msg::NeuralNetworkFeedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      neural_network_detector::msg::NeuralNetworkFeedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<neural_network_detector::msg::NeuralNetworkFeedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<neural_network_detector::msg::NeuralNetworkFeedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<neural_network_detector::msg::NeuralNetworkFeedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__neural_network_detector__msg__NeuralNetworkFeedback
    std::shared_ptr<neural_network_detector::msg::NeuralNetworkFeedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__neural_network_detector__msg__NeuralNetworkFeedback
    std::shared_ptr<neural_network_detector::msg::NeuralNetworkFeedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NeuralNetworkFeedback_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->ymin != other.ymin) {
      return false;
    }
    if (this->ymax != other.ymax) {
      return false;
    }
    if (this->xcenter != other.xcenter) {
      return false;
    }
    if (this->debug_included != other.debug_included) {
      return false;
    }
    if (this->head_raw != other.head_raw) {
      return false;
    }
    if (this->feet_raw != other.feet_raw) {
      return false;
    }
    if (this->ycenter != other.ycenter) {
      return false;
    }
    return true;
  }
  bool operator!=(const NeuralNetworkFeedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NeuralNetworkFeedback_

// alias to use template instance with default allocator
using NeuralNetworkFeedback =
  neural_network_detector::msg::NeuralNetworkFeedback_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace neural_network_detector

#endif  // NEURAL_NETWORK_DETECTOR__MSG__DETAIL__NEURAL_NETWORK_FEEDBACK__STRUCT_HPP_
