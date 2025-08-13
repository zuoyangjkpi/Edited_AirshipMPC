// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from neural_network_detector:msg/NeuralNetworkDetectionArray.idl
// generated code does not contain a copyright notice

#ifndef NEURAL_NETWORK_DETECTOR__MSG__DETAIL__NEURAL_NETWORK_DETECTION_ARRAY__FUNCTIONS_H_
#define NEURAL_NETWORK_DETECTOR__MSG__DETAIL__NEURAL_NETWORK_DETECTION_ARRAY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "neural_network_detector/msg/rosidl_generator_c__visibility_control.h"

#include "neural_network_detector/msg/detail/neural_network_detection_array__struct.h"

/// Initialize msg/NeuralNetworkDetectionArray message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * neural_network_detector__msg__NeuralNetworkDetectionArray
 * )) before or use
 * neural_network_detector__msg__NeuralNetworkDetectionArray__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_neural_network_detector
bool
neural_network_detector__msg__NeuralNetworkDetectionArray__init(neural_network_detector__msg__NeuralNetworkDetectionArray * msg);

/// Finalize msg/NeuralNetworkDetectionArray message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_neural_network_detector
void
neural_network_detector__msg__NeuralNetworkDetectionArray__fini(neural_network_detector__msg__NeuralNetworkDetectionArray * msg);

/// Create msg/NeuralNetworkDetectionArray message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * neural_network_detector__msg__NeuralNetworkDetectionArray__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_neural_network_detector
neural_network_detector__msg__NeuralNetworkDetectionArray *
neural_network_detector__msg__NeuralNetworkDetectionArray__create();

/// Destroy msg/NeuralNetworkDetectionArray message.
/**
 * It calls
 * neural_network_detector__msg__NeuralNetworkDetectionArray__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_neural_network_detector
void
neural_network_detector__msg__NeuralNetworkDetectionArray__destroy(neural_network_detector__msg__NeuralNetworkDetectionArray * msg);

/// Check for msg/NeuralNetworkDetectionArray message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_neural_network_detector
bool
neural_network_detector__msg__NeuralNetworkDetectionArray__are_equal(const neural_network_detector__msg__NeuralNetworkDetectionArray * lhs, const neural_network_detector__msg__NeuralNetworkDetectionArray * rhs);

/// Copy a msg/NeuralNetworkDetectionArray message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_neural_network_detector
bool
neural_network_detector__msg__NeuralNetworkDetectionArray__copy(
  const neural_network_detector__msg__NeuralNetworkDetectionArray * input,
  neural_network_detector__msg__NeuralNetworkDetectionArray * output);

/// Initialize array of msg/NeuralNetworkDetectionArray messages.
/**
 * It allocates the memory for the number of elements and calls
 * neural_network_detector__msg__NeuralNetworkDetectionArray__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_neural_network_detector
bool
neural_network_detector__msg__NeuralNetworkDetectionArray__Sequence__init(neural_network_detector__msg__NeuralNetworkDetectionArray__Sequence * array, size_t size);

/// Finalize array of msg/NeuralNetworkDetectionArray messages.
/**
 * It calls
 * neural_network_detector__msg__NeuralNetworkDetectionArray__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_neural_network_detector
void
neural_network_detector__msg__NeuralNetworkDetectionArray__Sequence__fini(neural_network_detector__msg__NeuralNetworkDetectionArray__Sequence * array);

/// Create array of msg/NeuralNetworkDetectionArray messages.
/**
 * It allocates the memory for the array and calls
 * neural_network_detector__msg__NeuralNetworkDetectionArray__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_neural_network_detector
neural_network_detector__msg__NeuralNetworkDetectionArray__Sequence *
neural_network_detector__msg__NeuralNetworkDetectionArray__Sequence__create(size_t size);

/// Destroy array of msg/NeuralNetworkDetectionArray messages.
/**
 * It calls
 * neural_network_detector__msg__NeuralNetworkDetectionArray__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_neural_network_detector
void
neural_network_detector__msg__NeuralNetworkDetectionArray__Sequence__destroy(neural_network_detector__msg__NeuralNetworkDetectionArray__Sequence * array);

/// Check for msg/NeuralNetworkDetectionArray message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_neural_network_detector
bool
neural_network_detector__msg__NeuralNetworkDetectionArray__Sequence__are_equal(const neural_network_detector__msg__NeuralNetworkDetectionArray__Sequence * lhs, const neural_network_detector__msg__NeuralNetworkDetectionArray__Sequence * rhs);

/// Copy an array of msg/NeuralNetworkDetectionArray messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_neural_network_detector
bool
neural_network_detector__msg__NeuralNetworkDetectionArray__Sequence__copy(
  const neural_network_detector__msg__NeuralNetworkDetectionArray__Sequence * input,
  neural_network_detector__msg__NeuralNetworkDetectionArray__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // NEURAL_NETWORK_DETECTOR__MSG__DETAIL__NEURAL_NETWORK_DETECTION_ARRAY__FUNCTIONS_H_
