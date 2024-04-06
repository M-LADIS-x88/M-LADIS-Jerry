# generated from rosidl_generator_py/resource/_idl.py.em
# with input from lidar_slam:msg/Confidence.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

# Member 'covariance'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Confidence(type):
    """Metaclass of message 'Confidence'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('lidar_slam')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'lidar_slam.msg.Confidence')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__confidence
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__confidence
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__confidence
            cls._TYPE_SUPPORT = module.type_support_msg__msg__confidence
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__confidence

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Confidence(metaclass=Metaclass_Confidence):
    """Message class 'Confidence'."""

    __slots__ = [
        '_header',
        '_covariance',
        '_overlap',
        '_nb_matches',
        '_comply_motion_limits',
        '_std_position_error',
        '_failure',
        '_computation_time',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'covariance': 'double[36]',
        'overlap': 'float',
        'nb_matches': 'int16',
        'comply_motion_limits': 'boolean',
        'std_position_error': 'float',
        'failure': 'boolean',
        'computation_time': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 36),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        if 'covariance' not in kwargs:
            self.covariance = numpy.zeros(36, dtype=numpy.float64)
        else:
            self.covariance = numpy.array(kwargs.get('covariance'), dtype=numpy.float64)
            assert self.covariance.shape == (36, )
        self.overlap = kwargs.get('overlap', float())
        self.nb_matches = kwargs.get('nb_matches', int())
        self.comply_motion_limits = kwargs.get('comply_motion_limits', bool())
        self.std_position_error = kwargs.get('std_position_error', float())
        self.failure = kwargs.get('failure', bool())
        self.computation_time = kwargs.get('computation_time', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.header != other.header:
            return False
        if all(self.covariance != other.covariance):
            return False
        if self.overlap != other.overlap:
            return False
        if self.nb_matches != other.nb_matches:
            return False
        if self.comply_motion_limits != other.comply_motion_limits:
            return False
        if self.std_position_error != other.std_position_error:
            return False
        if self.failure != other.failure:
            return False
        if self.computation_time != other.computation_time:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def covariance(self):
        """Message field 'covariance'."""
        return self._covariance

    @covariance.setter
    def covariance(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'covariance' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 36, \
                "The 'covariance' numpy.ndarray() must have a size of 36"
            self._covariance = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 36 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'covariance' field must be a set or sequence with length 36 and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._covariance = numpy.array(value, dtype=numpy.float64)

    @builtins.property
    def overlap(self):
        """Message field 'overlap'."""
        return self._overlap

    @overlap.setter
    def overlap(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'overlap' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'overlap' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._overlap = value

    @builtins.property
    def nb_matches(self):
        """Message field 'nb_matches'."""
        return self._nb_matches

    @nb_matches.setter
    def nb_matches(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'nb_matches' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'nb_matches' field must be an integer in [-32768, 32767]"
        self._nb_matches = value

    @builtins.property
    def comply_motion_limits(self):
        """Message field 'comply_motion_limits'."""
        return self._comply_motion_limits

    @comply_motion_limits.setter
    def comply_motion_limits(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'comply_motion_limits' field must be of type 'bool'"
        self._comply_motion_limits = value

    @builtins.property
    def std_position_error(self):
        """Message field 'std_position_error'."""
        return self._std_position_error

    @std_position_error.setter
    def std_position_error(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'std_position_error' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'std_position_error' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._std_position_error = value

    @builtins.property
    def failure(self):
        """Message field 'failure'."""
        return self._failure

    @failure.setter
    def failure(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'failure' field must be of type 'bool'"
        self._failure = value

    @builtins.property
    def computation_time(self):
        """Message field 'computation_time'."""
        return self._computation_time

    @computation_time.setter
    def computation_time(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'computation_time' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'computation_time' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._computation_time = value
