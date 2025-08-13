// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from neural_network_detector:msg/NeuralNetworkFeedback.idl
// generated code does not contain a copyright notice
#include "neural_network_detector/msg/detail/neural_network_feedback__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
neural_network_detector__msg__NeuralNetworkFeedback__init(neural_network_detector__msg__NeuralNetworkFeedback * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    neural_network_detector__msg__NeuralNetworkFeedback__fini(msg);
    return false;
  }
  // ymin
  // ymax
  // xcenter
  // debug_included
  // head_raw
  // feet_raw
  // ycenter
  return true;
}

void
neural_network_detector__msg__NeuralNetworkFeedback__fini(neural_network_detector__msg__NeuralNetworkFeedback * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // ymin
  // ymax
  // xcenter
  // debug_included
  // head_raw
  // feet_raw
  // ycenter
}

bool
neural_network_detector__msg__NeuralNetworkFeedback__are_equal(const neural_network_detector__msg__NeuralNetworkFeedback * lhs, const neural_network_detector__msg__NeuralNetworkFeedback * rhs)
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
  // ymin
  if (lhs->ymin != rhs->ymin) {
    return false;
  }
  // ymax
  if (lhs->ymax != rhs->ymax) {
    return false;
  }
  // xcenter
  if (lhs->xcenter != rhs->xcenter) {
    return false;
  }
  // debug_included
  if (lhs->debug_included != rhs->debug_included) {
    return false;
  }
  // head_raw
  if (lhs->head_raw != rhs->head_raw) {
    return false;
  }
  // feet_raw
  if (lhs->feet_raw != rhs->feet_raw) {
    return false;
  }
  // ycenter
  if (lhs->ycenter != rhs->ycenter) {
    return false;
  }
  return true;
}

bool
neural_network_detector__msg__NeuralNetworkFeedback__copy(
  const neural_network_detector__msg__NeuralNetworkFeedback * input,
  neural_network_detector__msg__NeuralNetworkFeedback * output)
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
  // ymin
  output->ymin = input->ymin;
  // ymax
  output->ymax = input->ymax;
  // xcenter
  output->xcenter = input->xcenter;
  // debug_included
  output->debug_included = input->debug_included;
  // head_raw
  output->head_raw = input->head_raw;
  // feet_raw
  output->feet_raw = input->feet_raw;
  // ycenter
  output->ycenter = input->ycenter;
  return true;
}

neural_network_detector__msg__NeuralNetworkFeedback *
neural_network_detector__msg__NeuralNetworkFeedback__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  neural_network_detector__msg__NeuralNetworkFeedback * msg = (neural_network_detector__msg__NeuralNetworkFeedback *)allocator.allocate(sizeof(neural_network_detector__msg__NeuralNetworkFeedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(neural_network_detector__msg__NeuralNetworkFeedback));
  bool success = neural_network_detector__msg__NeuralNetworkFeedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
neural_network_detector__msg__NeuralNetworkFeedback__destroy(neural_network_detector__msg__NeuralNetworkFeedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    neural_network_detector__msg__NeuralNetworkFeedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
neural_network_detector__msg__NeuralNetworkFeedback__Sequence__init(neural_network_detector__msg__NeuralNetworkFeedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  neural_network_detector__msg__NeuralNetworkFeedback * data = NULL;

  if (size) {
    data = (neural_network_detector__msg__NeuralNetworkFeedback *)allocator.zero_allocate(size, sizeof(neural_network_detector__msg__NeuralNetworkFeedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = neural_network_detector__msg__NeuralNetworkFeedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        neural_network_detector__msg__NeuralNetworkFeedback__fini(&data[i - 1]);
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
neural_network_detector__msg__NeuralNetworkFeedback__Sequence__fini(neural_network_detector__msg__NeuralNetworkFeedback__Sequence * array)
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
      neural_network_detector__msg__NeuralNetworkFeedback__fini(&array->data[i]);
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

neural_network_detector__msg__NeuralNetworkFeedback__Sequence *
neural_network_detector__msg__NeuralNetworkFeedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  neural_network_detector__msg__NeuralNetworkFeedback__Sequence * array = (neural_network_detector__msg__NeuralNetworkFeedback__Sequence *)allocator.allocate(sizeof(neural_network_detector__msg__NeuralNetworkFeedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = neural_network_detector__msg__NeuralNetworkFeedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
neural_network_detector__msg__NeuralNetworkFeedback__Sequence__destroy(neural_network_detector__msg__NeuralNetworkFeedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    neural_network_detector__msg__NeuralNetworkFeedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
neural_network_detector__msg__NeuralNetworkFeedback__Sequence__are_equal(const neural_network_detector__msg__NeuralNetworkFeedback__Sequence * lhs, const neural_network_detector__msg__NeuralNetworkFeedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!neural_network_detector__msg__NeuralNetworkFeedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
neural_network_detector__msg__NeuralNetworkFeedback__Sequence__copy(
  const neural_network_detector__msg__NeuralNetworkFeedback__Sequence * input,
  neural_network_detector__msg__NeuralNetworkFeedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(neural_network_detector__msg__NeuralNetworkFeedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    neural_network_detector__msg__NeuralNetworkFeedback * data =
      (neural_network_detector__msg__NeuralNetworkFeedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!neural_network_detector__msg__NeuralNetworkFeedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          neural_network_detector__msg__NeuralNetworkFeedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!neural_network_detector__msg__NeuralNetworkFeedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
