// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from lidar_slam:msg/Confidence.idl
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
#include "lidar_slam/msg/detail/confidence__struct.h"
#include "lidar_slam/msg/detail/confidence__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool lidar_slam__msg__confidence__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[38];
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
    assert(strncmp("lidar_slam.msg._confidence.Confidence", full_classname_dest, 37) == 0);
  }
  lidar_slam__msg__Confidence * ros_message = _ros_message;
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
  {  // covariance
    PyObject * field = PyObject_GetAttrString(_pymsg, "covariance");
    if (!field) {
      return false;
    }
    {
      // TODO(dirk-thomas) use a better way to check the type before casting
      assert(field->ob_type != NULL);
      assert(field->ob_type->tp_name != NULL);
      assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
      PyArrayObject * seq_field = (PyArrayObject *)field;
      Py_INCREF(seq_field);
      assert(PyArray_NDIM(seq_field) == 1);
      assert(PyArray_TYPE(seq_field) == NPY_FLOAT64);
      Py_ssize_t size = 36;
      double * dest = ros_message->covariance;
      for (Py_ssize_t i = 0; i < size; ++i) {
        double tmp = *(npy_float64 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(double));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // overlap
    PyObject * field = PyObject_GetAttrString(_pymsg, "overlap");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->overlap = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // nb_matches
    PyObject * field = PyObject_GetAttrString(_pymsg, "nb_matches");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->nb_matches = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // comply_motion_limits
    PyObject * field = PyObject_GetAttrString(_pymsg, "comply_motion_limits");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->comply_motion_limits = (Py_True == field);
    Py_DECREF(field);
  }
  {  // std_position_error
    PyObject * field = PyObject_GetAttrString(_pymsg, "std_position_error");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->std_position_error = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // failure
    PyObject * field = PyObject_GetAttrString(_pymsg, "failure");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->failure = (Py_True == field);
    Py_DECREF(field);
  }
  {  // computation_time
    PyObject * field = PyObject_GetAttrString(_pymsg, "computation_time");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->computation_time = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * lidar_slam__msg__confidence__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Confidence */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("lidar_slam.msg._confidence");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Confidence");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  lidar_slam__msg__Confidence * ros_message = (lidar_slam__msg__Confidence *)raw_ros_message;
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
  {  // covariance
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "covariance");
    if (!field) {
      return NULL;
    }
    assert(field->ob_type != NULL);
    assert(field->ob_type->tp_name != NULL);
    assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
    PyArrayObject * seq_field = (PyArrayObject *)field;
    assert(PyArray_NDIM(seq_field) == 1);
    assert(PyArray_TYPE(seq_field) == NPY_FLOAT64);
    assert(sizeof(npy_float64) == sizeof(double));
    npy_float64 * dst = (npy_float64 *)PyArray_GETPTR1(seq_field, 0);
    double * src = &(ros_message->covariance[0]);
    memcpy(dst, src, 36 * sizeof(double));
    Py_DECREF(field);
  }
  {  // overlap
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->overlap);
    {
      int rc = PyObject_SetAttrString(_pymessage, "overlap", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // nb_matches
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->nb_matches);
    {
      int rc = PyObject_SetAttrString(_pymessage, "nb_matches", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // comply_motion_limits
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->comply_motion_limits ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "comply_motion_limits", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // std_position_error
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->std_position_error);
    {
      int rc = PyObject_SetAttrString(_pymessage, "std_position_error", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // failure
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->failure ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "failure", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // computation_time
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->computation_time);
    {
      int rc = PyObject_SetAttrString(_pymessage, "computation_time", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
