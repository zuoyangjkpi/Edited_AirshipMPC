// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from neural_network_detector:msg/NeuralNetworkDetection.idl
// generated code does not contain a copyright notice
#include "neural_network_detector/msg/detail/neural_network_detection__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
neural_network_detector__msg__NeuralNetworkDetection__init(neural_network_detector__msg__NeuralNetworkDetection * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    neural_network_detector__msg__NeuralNetworkDetection__fini(msg);
    return false;
  }
  // object_class
  // detection_score
  // xmin
  // xmax
  // ymin
  // ymax
  // variance_xmin
  // variance_xmax
  // variance_ymin
  // variance_ymax
  return true;
}

void
neural_network_detector__msg__NeuralNetworkDetection__fini(neural_network_detector__msg__NeuralNetworkDetection * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // object_class
  // detection_score
  // xmin
  // xmax
  // ymin
  // ymax
  // variance_xmin
  // variance_xmax
  // variance_ymin
  // variance_ymax
}

bool
neural_network_detector__msg__NeuralNetworkDetection__are_equal(const neural_network_detector__msg__NeuralNetworkDetection * lhs, const neural_network_detector__msg__NeuralNetworkDetection * rhs)
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
  // object_class
  if (lhs->object_class != rhs->object_class) {
    return false;
  }
  // detection_score
  if (lhs->detection_score != rhs->detection_score) {
    return false;
  }
  // xmin
  if (lhs->xmin != rhs->xmin) {
    return false;
  }
  // xmax
  if (lhs->xmax != rhs->xmax) {
    return false;
  }
  // ymin
  if (lhs->ymin != rhs->ymin) {
    return false;
  }
  // ymax
  if (lhs->ymax != rhs->ymax) {
    return false;
  }
  // variance_xmin
  if (lhs->variance_xmin != rhs->variance_xmin) {
    return false;
  }
  // variance_xmax
  if (lhs->variance_xmax != rhs->variance_xmax) {
    return false;
  }
  // variance_ymin
  if (lhs->variance_ymin != rhs->variance_ymin) {
    return false;
  }
  // variance_ymax
  if (lhs->variance_ymax != rhs->variance_ymax) {
    return false;
  }
  return true;
}

bool
neural_network_detector__msg__NeuralNetworkDetection__copy(
  const neural_network_detector__msg__NeuralNetworkDetection * input,
  neural_network_detector__msg__NeuralNetworkDetection * output)
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
  // object_class
  output->object_class = input->object_class;
  // detection_score
  output->detection_score = input->detection_score;
  // xmin
  output->xmin = input->xmin;
  // xmax
  output->xmax = input->xmax;
  // ymin
  output->ymin = input->ymin;
  // ymax
  output->ymax = input->ymax;
  // variance_xmin
  output->variance_xmin = input->variance_xmin;
  // variance_xmax
  output->variance_xmax = input->variance_xmax;
  // variance_ymin
  output->variance_ymin = input->variance_ymin;
  // variance_ymax
  output->variance_ymax = input->variance_ymax;
  return true;
}

neural_network_detector__msg__NeuralNetworkDetection *
neural_network_detector__msg__NeuralNetworkDetection__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  neural_network_detector__msg__NeuralNetworkDetection * msg = (neural_network_detector__msg__NeuralNetworkDetection *)allocator.allocate(sizeof(neural_network_detector__msg__NeuralNetworkDetection), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(neural_network_detector__msg__NeuralNetworkDetection));
  bool success = neural_network_detector__msg__NeuralNetworkDetection__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
neural_network_detector__msg__NeuralNetworkDetection__destroy(neural_network_detector__msg__NeuralNetworkDetection * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    neural_network_detector__msg__NeuralNetworkDetection__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
neural_network_detector__msg__NeuralNetworkDetection__Sequence__init(neural_network_detector__msg__NeuralNetworkDetection__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  neural_network_detector__msg__NeuralNetworkDetection * data = NULL;

  if (size) {
    data = (neural_network_detector__msg__NeuralNetworkDetection *)allocator.zero_allocate(size, sizeof(neural_network_detector__msg__NeuralNetworkDetection), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = neural_network_detector__msg__NeuralNetworkDetection__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        neural_network_detector__msg__NeuralNetworkDetection__fini(&data[i - 1]);
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
neural_network_detector__msg__NeuralNetworkDetection__Sequence__fini(neural_network_detector__msg__NeuralNetworkDetection__Sequence * array)
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
      neural_network_detector__msg__NeuralNetworkDetection__fini(&array->data[i]);
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

neural_network_detector__msg__NeuralNetworkDetection__Sequence *
neural_network_detector__msg__NeuralNetworkDetection__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  neural_network_detector__msg__NeuralNetworkDetection__Sequence * array = (neural_network_detector__msg__NeuralNetworkDetection__Sequence *)allocator.allocate(sizeof(neural_network_detector__msg__NeuralNetworkDetection__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = neural_network_detector__msg__NeuralNetworkDetection__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
neural_network_detector__msg__NeuralNetworkDetection__Sequence__destroy(neural_network_detector__msg__NeuralNetworkDetection__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    neural_network_detector__msg__NeuralNetworkDetection__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
neural_network_detector__msg__NeuralNetworkDetection__Sequence__are_equal(const neural_network_detector__msg__NeuralNetworkDetection__Sequence * lhs, const neural_network_detector__msg__NeuralNetworkDetection__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!neural_network_detector__msg__NeuralNetworkDetection__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
neural_network_detector__msg__NeuralNetworkDetection__Sequence__copy(
  const neural_network_detector__msg__NeuralNetworkDetection__Sequence * input,
  neural_network_detector__msg__NeuralNetworkDetection__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(neural_network_detector__msg__NeuralNetworkDetection);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    neural_network_detector__msg__NeuralNetworkDetection * data =
      (neural_network_detector__msg__NeuralNetworkDetection *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!neural_network_detector__msg__NeuralNetworkDetection__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          neural_network_detector__msg__NeuralNetworkDetection__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!neural_network_detector__msg__NeuralNetworkDetection__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
