// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from neural_network_detector:msg/NeuralNetworkDetection.idl
// generated code does not contain a copyright notice

#ifndef NEURAL_NETWORK_DETECTOR__MSG__DETAIL__NEURAL_NETWORK_DETECTION__STRUCT_H_
#define NEURAL_NETWORK_DETECTOR__MSG__DETAIL__NEURAL_NETWORK_DETECTION__STRUCT_H_

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

/// Struct defined in msg/NeuralNetworkDetection in the package neural_network_detector.
typedef struct neural_network_detector__msg__NeuralNetworkDetection
{
  std_msgs__msg__Header header;
  int16_t object_class;
  float detection_score;
  int16_t xmin;
  int16_t xmax;
  int16_t ymin;
  int16_t ymax;
  float variance_xmin;
  float variance_xmax;
  float variance_ymin;
  float variance_ymax;
} neural_network_detector__msg__NeuralNetworkDetection;

// Struct for a sequence of neural_network_detector__msg__NeuralNetworkDetection.
typedef struct neural_network_detector__msg__NeuralNetworkDetection__Sequence
{
  neural_network_detector__msg__NeuralNetworkDetection * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} neural_network_detector__msg__NeuralNetworkDetection__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NEURAL_NETWORK_DETECTOR__MSG__DETAIL__NEURAL_NETWORK_DETECTION__STRUCT_H_
