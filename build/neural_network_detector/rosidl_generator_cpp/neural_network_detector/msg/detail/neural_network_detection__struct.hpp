// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from neural_network_detector:msg/NeuralNetworkDetection.idl
// generated code does not contain a copyright notice

#ifndef NEURAL_NETWORK_DETECTOR__MSG__DETAIL__NEURAL_NETWORK_DETECTION__STRUCT_HPP_
#define NEURAL_NETWORK_DETECTOR__MSG__DETAIL__NEURAL_NETWORK_DETECTION__STRUCT_HPP_

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
# define DEPRECATED__neural_network_detector__msg__NeuralNetworkDetection __attribute__((deprecated))
#else
# define DEPRECATED__neural_network_detector__msg__NeuralNetworkDetection __declspec(deprecated)
#endif

namespace neural_network_detector
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NeuralNetworkDetection_
{
  using Type = NeuralNetworkDetection_<ContainerAllocator>;

  explicit NeuralNetworkDetection_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->object_class = 0;
      this->detection_score = 0.0f;
      this->xmin = 0;
      this->xmax = 0;
      this->ymin = 0;
      this->ymax = 0;
      this->variance_xmin = 0.0f;
      this->variance_xmax = 0.0f;
      this->variance_ymin = 0.0f;
      this->variance_ymax = 0.0f;
    }
  }

  explicit NeuralNetworkDetection_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->object_class = 0;
      this->detection_score = 0.0f;
      this->xmin = 0;
      this->xmax = 0;
      this->ymin = 0;
      this->ymax = 0;
      this->variance_xmin = 0.0f;
      this->variance_xmax = 0.0f;
      this->variance_ymin = 0.0f;
      this->variance_ymax = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _object_class_type =
    int16_t;
  _object_class_type object_class;
  using _detection_score_type =
    float;
  _detection_score_type detection_score;
  using _xmin_type =
    int16_t;
  _xmin_type xmin;
  using _xmax_type =
    int16_t;
  _xmax_type xmax;
  using _ymin_type =
    int16_t;
  _ymin_type ymin;
  using _ymax_type =
    int16_t;
  _ymax_type ymax;
  using _variance_xmin_type =
    float;
  _variance_xmin_type variance_xmin;
  using _variance_xmax_type =
    float;
  _variance_xmax_type variance_xmax;
  using _variance_ymin_type =
    float;
  _variance_ymin_type variance_ymin;
  using _variance_ymax_type =
    float;
  _variance_ymax_type variance_ymax;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__object_class(
    const int16_t & _arg)
  {
    this->object_class = _arg;
    return *this;
  }
  Type & set__detection_score(
    const float & _arg)
  {
    this->detection_score = _arg;
    return *this;
  }
  Type & set__xmin(
    const int16_t & _arg)
  {
    this->xmin = _arg;
    return *this;
  }
  Type & set__xmax(
    const int16_t & _arg)
  {
    this->xmax = _arg;
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
  Type & set__variance_xmin(
    const float & _arg)
  {
    this->variance_xmin = _arg;
    return *this;
  }
  Type & set__variance_xmax(
    const float & _arg)
  {
    this->variance_xmax = _arg;
    return *this;
  }
  Type & set__variance_ymin(
    const float & _arg)
  {
    this->variance_ymin = _arg;
    return *this;
  }
  Type & set__variance_ymax(
    const float & _arg)
  {
    this->variance_ymax = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    neural_network_detector::msg::NeuralNetworkDetection_<ContainerAllocator> *;
  using ConstRawPtr =
    const neural_network_detector::msg::NeuralNetworkDetection_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<neural_network_detector::msg::NeuralNetworkDetection_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<neural_network_detector::msg::NeuralNetworkDetection_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      neural_network_detector::msg::NeuralNetworkDetection_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<neural_network_detector::msg::NeuralNetworkDetection_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      neural_network_detector::msg::NeuralNetworkDetection_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<neural_network_detector::msg::NeuralNetworkDetection_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<neural_network_detector::msg::NeuralNetworkDetection_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<neural_network_detector::msg::NeuralNetworkDetection_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__neural_network_detector__msg__NeuralNetworkDetection
    std::shared_ptr<neural_network_detector::msg::NeuralNetworkDetection_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__neural_network_detector__msg__NeuralNetworkDetection
    std::shared_ptr<neural_network_detector::msg::NeuralNetworkDetection_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NeuralNetworkDetection_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->object_class != other.object_class) {
      return false;
    }
    if (this->detection_score != other.detection_score) {
      return false;
    }
    if (this->xmin != other.xmin) {
      return false;
    }
    if (this->xmax != other.xmax) {
      return false;
    }
    if (this->ymin != other.ymin) {
      return false;
    }
    if (this->ymax != other.ymax) {
      return false;
    }
    if (this->variance_xmin != other.variance_xmin) {
      return false;
    }
    if (this->variance_xmax != other.variance_xmax) {
      return false;
    }
    if (this->variance_ymin != other.variance_ymin) {
      return false;
    }
    if (this->variance_ymax != other.variance_ymax) {
      return false;
    }
    return true;
  }
  bool operator!=(const NeuralNetworkDetection_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NeuralNetworkDetection_

// alias to use template instance with default allocator
using NeuralNetworkDetection =
  neural_network_detector::msg::NeuralNetworkDetection_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace neural_network_detector

#endif  // NEURAL_NETWORK_DETECTOR__MSG__DETAIL__NEURAL_NETWORK_DETECTION__STRUCT_HPP_
