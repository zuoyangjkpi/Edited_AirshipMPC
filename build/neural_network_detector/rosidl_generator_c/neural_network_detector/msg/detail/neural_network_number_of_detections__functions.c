// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from neural_network_detector:msg/NeuralNetworkNumberOfDetections.idl
// generated code does not contain a copyright notice
#include "neural_network_detector/msg/detail/neural_network_number_of_detections__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
neural_network_detector__msg__NeuralNetworkNumberOfDetections__init(neural_network_detector__msg__NeuralNetworkNumberOfDetections * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    neural_network_detector__msg__NeuralNetworkNumberOfDetections__fini(msg);
    return false;
  }
  // data
  return true;
}

void
neural_network_detector__msg__NeuralNetworkNumberOfDetections__fini(neural_network_detector__msg__NeuralNetworkNumberOfDetections * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // data
}

bool
neural_network_detector__msg__NeuralNetworkNumberOfDetections__are_equal(const neural_network_detector__msg__NeuralNetworkNumberOfDetections * lhs, const neural_network_detector__msg__NeuralNetworkNumberOfDetections * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // data
  if (lhs->data != rhs->data) {
    return false;
  }
  return true;
}

bool
neural_network_detector__msg__NeuralNetworkNumberOfDetections__copy(
  const neural_network_detector__msg__NeuralNetworkNumberOfDetections * input,
  neural_network_detector__msg__NeuralNetworkNumberOfDetections * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // data
  output->data = input->data;
  return true;
}

neural_network_detector__msg__NeuralNetworkNumberOfDetections *
neural_network_detector__msg__NeuralNetworkNumberOfDetections__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  neural_network_detector__msg__NeuralNetworkNumberOfDetections * msg = (neural_network_detector__msg__NeuralNetworkNumberOfDetections *)allocator.allocate(sizeof(neural_network_detector__msg__NeuralNetworkNumberOfDetections), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(neural_network_detector__msg__NeuralNetworkNumberOfDetections));
  bool success = neural_network_detector__msg__NeuralNetworkNumberOfDetections__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
neural_network_detector__msg__NeuralNetworkNumberOfDetections__destroy(neural_network_detector__msg__NeuralNetworkNumberOfDetections * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    neural_network_detector__msg__NeuralNetworkNumberOfDetections__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
neural_network_detector__msg__NeuralNetworkNumberOfDetections__Sequence__init(neural_network_detector__msg__NeuralNetworkNumberOfDetections__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  neural_network_detector__msg__NeuralNetworkNumberOfDetections * data = NULL;

  if (size) {
    data = (neural_network_detector__msg__NeuralNetworkNumberOfDetections *)allocator.zero_allocate(size, sizeof(neural_network_detector__msg__NeuralNetworkNumberOfDetections), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = neural_network_detector__msg__NeuralNetworkNumberOfDetections__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        neural_network_detector__msg__NeuralNetworkNumberOfDetections__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
neural_network_detector__msg__NeuralNetworkNumberOfDetections__Sequence__fini(neural_network_detector__msg__NeuralNetworkNumberOfDetections__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      neural_network_detector__msg__NeuralNetworkNumberOfDetections__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

neural_network_detector__msg__NeuralNetworkNumberOfDetections__Sequence *
neural_network_detector__msg__NeuralNetworkNumberOfDetections__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  neural_network_detector__msg__NeuralNetworkNumberOfDetections__Sequence * array = (neural_network_detector__msg__NeuralNetworkNumberOfDetections__Sequence *)allocator.allocate(sizeof(neural_network_detector__msg__NeuralNetworkNumberOfDetections__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = neural_network_detector__msg__NeuralNetworkNumberOfDetections__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
neural_network_detector__msg__NeuralNetworkNumberOfDetections__Sequence__destroy(neural_network_detector__msg__NeuralNetworkNumberOfDetections__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    neural_network_detector__msg__NeuralNetworkNumberOfDetections__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
neural_network_detector__msg__NeuralNetworkNumberOfDetections__Sequence__are_equal(const neural_network_detector__msg__NeuralNetworkNumberOfDetections__Sequence * lhs, const neural_network_detector__msg__NeuralNetworkNumberOfDetections__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!neural_network_detector__msg__NeuralNetworkNumberOfDetections__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
neural_network_detector__msg__NeuralNetworkNumberOfDetections__Sequence__copy(
  const neural_network_detector__msg__NeuralNetworkNumberOfDetections__Sequence * input,
  neural_network_detector__msg__NeuralNetworkNumberOfDetections__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(neural_network_detector__msg__NeuralNetworkNumberOfDetections);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    neural_network_detector__msg__NeuralNetworkNumberOfDetections * data =
      (neural_network_detector__msg__NeuralNetworkNumberOfDetections *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!neural_network_detector__msg__NeuralNetworkNumberOfDetections__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          neural_network_detector__msg__NeuralNetworkNumberOfDetections__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!neural_network_detector__msg__NeuralNetworkNumberOfDetections__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
