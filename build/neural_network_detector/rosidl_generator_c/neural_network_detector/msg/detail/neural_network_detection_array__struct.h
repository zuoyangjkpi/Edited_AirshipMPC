// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from neural_network_detector:msg/NeuralNetworkDetectionArray.idl
// generated code does not contain a copyright notice

#ifndef NEURAL_NETWORK_DETECTOR__MSG__DETAIL__NEURAL_NETWORK_DETECTION_ARRAY__STRUCT_H_
#define NEURAL_NETWORK_DETECTOR__MSG__DETAIL__NEURAL_NETWORK_DETECTION_ARRAY__STRUCT_H_

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
// Member 'detections'
#include "neural_network_detector/msg/detail/neural_network_detection__struct.h"

/// Struct defined in msg/NeuralNetworkDetectionArray in the package neural_network_detector.
typedef struct neural_network_detector__msg__NeuralNetworkDetectionArray
{
  std_msgs__msg__Header header;
  neural_network_detector__msg__NeuralNetworkDetection__Sequence detections;
} neural_network_detector__msg__NeuralNetworkDetectionArray;

// Struct for a sequence of neural_network_detector__msg__NeuralNetworkDetectionArray.
typedef struct neural_network_detector__msg__NeuralNetworkDetectionArray__Sequence
{
  neural_network_detector__msg__NeuralNetworkDetectionArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} neural_network_detector__msg__NeuralNetworkDetectionArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NEURAL_NETWORK_DETECTOR__MSG__DETAIL__NEURAL_NETWORK_DETECTION_ARRAY__STRUCT_H_
