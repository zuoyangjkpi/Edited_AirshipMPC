// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from neural_network_detector:msg/NeuralNetworkFeedback.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "neural_network_detector/msg/detail/neural_network_feedback__struct.h"
#include "neural_network_detector/msg/detail/neural_network_feedback__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool neural_network_detector__msg__neural_network_feedback__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[75];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("neural_network_detector.msg._neural_network_feedback.NeuralNetworkFeedback", full_classname_dest, 74) == 0);
  }
  neural_network_detector__msg__NeuralNetworkFeedback * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // ymin
    PyObject * field = PyObject_GetAttrString(_pymsg, "ymin");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->ymin = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // ymax
    PyObject * field = PyObject_GetAttrString(_pymsg, "ymax");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->ymax = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // xcenter
    PyObject * field = PyObject_GetAttrString(_pymsg, "xcenter");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->xcenter = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // debug_included
    PyObject * field = PyObject_GetAttrString(_pymsg, "debug_included");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->debug_included = (Py_True == field);
    Py_DECREF(field);
  }
  {  // head_raw
    PyObject * field = PyObject_GetAttrString(_pymsg, "head_raw");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->head_raw = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // feet_raw
    PyObject * field = PyObject_GetAttrString(_pymsg, "feet_raw");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->feet_raw = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // ycenter
    PyObject * field = PyObject_GetAttrString(_pymsg, "ycenter");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->ycenter = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * neural_network_detector__msg__neural_network_feedback__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of NeuralNetworkFeedback */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("neural_network_detector.msg._neural_network_feedback");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "NeuralNetworkFeedback");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  neural_network_detector__msg__NeuralNetworkFeedback * ros_message = (neural_network_detector__msg__NeuralNetworkFeedback *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ymin
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->ymin);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ymin", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ymax
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->ymax);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ymax", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // xcenter
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->xcenter);
    {
      int rc = PyObject_SetAttrString(_pymessage, "xcenter", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // debug_included
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->debug_included ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "debug_included", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // head_raw
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->head_raw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "head_raw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // feet_raw
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->feet_raw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "feet_raw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ycenter
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->ycenter);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ycenter", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
