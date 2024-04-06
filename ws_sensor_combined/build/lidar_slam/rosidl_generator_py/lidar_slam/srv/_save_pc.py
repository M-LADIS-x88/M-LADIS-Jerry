# generated from rosidl_generator_py/resource/_idl.py.em
# with input from lidar_slam:srv/SavePc.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SavePc_Request(type):
    """Metaclass of message 'SavePc_Request'."""

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
                'lidar_slam.srv.SavePc_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__save_pc__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__save_pc__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__save_pc__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__save_pc__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__save_pc__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SavePc_Request(metaclass=Metaclass_SavePc_Request):
    """Message class 'SavePc_Request'."""

    __slots__ = [
        '_output_prefix_path',
        '_format',
    ]

    _fields_and_field_types = {
        'output_prefix_path': 'string',
        'format': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.output_prefix_path = kwargs.get('output_prefix_path', str())
        self.format = kwargs.get('format', int())

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
        if self.output_prefix_path != other.output_prefix_path:
            return False
        if self.format != other.format:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def output_prefix_path(self):
        """Message field 'output_prefix_path'."""
        return self._output_prefix_path

    @output_prefix_path.setter
    def output_prefix_path(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'output_prefix_path' field must be of type 'str'"
        self._output_prefix_path = value

    @builtins.property  # noqa: A003
    def format(self):  # noqa: A003
        """Message field 'format'."""
        return self._format

    @format.setter  # noqa: A003
    def format(self, value):  # noqa: A003
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'format' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'format' field must be an integer in [-2147483648, 2147483647]"
        self._format = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_SavePc_Response(type):
    """Metaclass of message 'SavePc_Response'."""

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
                'lidar_slam.srv.SavePc_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__save_pc__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__save_pc__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__save_pc__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__save_pc__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__save_pc__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SavePc_Response(metaclass=Metaclass_SavePc_Response):
    """Message class 'SavePc_Response'."""

    __slots__ = [
        '_success',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())

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
        if self.success != other.success:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value


class Metaclass_SavePc(type):
    """Metaclass of service 'SavePc'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('lidar_slam')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'lidar_slam.srv.SavePc')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__save_pc

            from lidar_slam.srv import _save_pc
            if _save_pc.Metaclass_SavePc_Request._TYPE_SUPPORT is None:
                _save_pc.Metaclass_SavePc_Request.__import_type_support__()
            if _save_pc.Metaclass_SavePc_Response._TYPE_SUPPORT is None:
                _save_pc.Metaclass_SavePc_Response.__import_type_support__()


class SavePc(metaclass=Metaclass_SavePc):
    from lidar_slam.srv._save_pc import SavePc_Request as Request
    from lidar_slam.srv._save_pc import SavePc_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
