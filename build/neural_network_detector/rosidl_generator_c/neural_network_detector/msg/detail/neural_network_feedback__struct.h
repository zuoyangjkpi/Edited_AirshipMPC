// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from neural_network_detector:msg/NeuralNetworkFeedback.idl
// generated code does not contain a copyright notice

#ifndef NEURAL_NETWORK_DETECTOR__MSG__DETAIL__NEURAL_NETWORK_FEEDBACK__STRUCT_H_
#define NEURAL_NETWORK_DETECTOR__MSG__DETAIL__NEURAL_NETWORK_FEEDBACK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/NeuralNetworkFeedback in the package neural_network_detector.
typedef struct neural_network_detector__msg__NeuralNetworkFeedback
{
  std_msgs__msg__Header header;
  int16_t ymin;
  int16_t ymax;
  int16_t xcenter;
  /// Debug stuff
  bool debug_included;
  int16_t head_raw;
  int16_t feet_raw;
  int16_t ycenter;
} neural_network_detector__msg__NeuralNetworkFeedback;

// Struct for a sequence of neural_network_detector__msg__NeuralNetworkFeedback.
typedef struct neural_network_detector__msg__NeuralNetworkFeedback__Sequence
{
  neural_network_detector__msg__NeuralNetworkFeedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} neural_network_detector__msg__NeuralNetworkFeedback__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NEURAL_NETWORK_DETECTOR__MSG__DETAIL__NEURAL_NETWORK_FEEDBACK__STRUCT_H_
