// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from neural_network_detector:msg/NeuralNetworkDetection.idl
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
#include "neural_network_detector/msg/detail/neural_network_detection__struct.h"
#include "neural_network_detector/msg/detail/neural_network_detection__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool neural_network_detector__msg__neural_network_detection__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[77];
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
    assert(strncmp("neural_network_detector.msg._neural_network_detection.NeuralNetworkDetection", full_classname_dest, 76) == 0);
  }
  neural_network_detector__msg__NeuralNetworkDetection * ros_message = _ros_message;
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
  {  // object_class
    PyObject * field = PyObject_GetAttrString(_pymsg, "object_class");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->object_class = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // detection_score
    PyObject * field = PyObject_GetAttrString(_pymsg, "detection_score");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->detection_score = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // xmin
    PyObject * field = PyObject_GetAttrString(_pymsg, "xmin");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->xmin = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // xmax
    PyObject * field = PyObject_GetAttrString(_pymsg, "xmax");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->xmax = (int16_t)PyLong_AsLong(field);
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
  {  // variance_xmin
    PyObject * field = PyObject_GetAttrString(_pymsg, "variance_xmin");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->variance_xmin = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // variance_xmax
    PyObject * field = PyObject_GetAttrString(_pymsg, "variance_xmax");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->variance_xmax = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // variance_ymin
    PyObject * field = PyObject_GetAttrString(_pymsg, "variance_ymin");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->variance_ymin = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // variance_ymax
    PyObject * field = PyObject_GetAttrString(_pymsg, "variance_ymax");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->variance_ymax = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * neural_network_detector__msg__neural_network_detection__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of NeuralNetworkDetection */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("neural_network_detector.msg._neural_network_detection");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "NeuralNetworkDetection");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  neural_network_detector__msg__NeuralNetworkDetection * ros_message = (neural_network_detector__msg__NeuralNetworkDetection *)raw_ros_message;
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
  {  // object_class
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->object_class);
    {
      int rc = PyObject_SetAttrString(_pymessage, "object_class", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // detection_score
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->detection_score);
    {
      int rc = PyObject_SetAttrString(_pymessage, "detection_score", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // xmin
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->xmin);
    {
      int rc = PyObject_SetAttrString(_pymessage, "xmin", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // xmax
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->xmax);
    {
      int rc = PyObject_SetAttrString(_pymessage, "xmax", field);
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
  {  // variance_xmin
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->variance_xmin);
    {
      int rc = PyObject_SetAttrString(_pymessage, "variance_xmin", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // variance_xmax
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->variance_xmax);
    {
      int rc = PyObject_SetAttrString(_pymessage, "variance_xmax", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // variance_ymin
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->variance_ymin);
    {
      int rc = PyObject_SetAttrString(_pymessage, "variance_ymin", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // variance_ymax
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->variance_ymax);
    {
      int rc = PyObject_SetAttrString(_pymessage, "variance_ymax", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
