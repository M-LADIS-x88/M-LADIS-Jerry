# generated from rosidl_generator_py/resource/_idl.py.em
# with input from lidar_slam:msg/SlamCommand.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SlamCommand(type):
    """Metaclass of message 'SlamCommand'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'DISABLE_SLAM_MAP_UPDATE': 8,
        'ENABLE_SLAM_MAP_EXPANSION': 9,
        'ENABLE_SLAM_MAP_UPDATE': 10,
        'RESET_TRAJECTORY': 11,
        'RESET_SLAM': 12,
        'SWITCH_ON_OFF': 13,
        'SAVE_TRAJECTORY': 14,
        'SAVE_LIDAR_TRAJECTORY': 15,
        'SAVE_KEYPOINTS_MAPS': 16,
        'SAVE_FILTERED_KEYPOINTS_MAPS': 17,
        'LOAD_KEYPOINTS_MAPS': 18,
        'OPTIMIZE_GRAPH': 20,
        'LOAD_LOOP_INDICES': 23,
        'SWITCH_SENSOR': 25,
        'CALIBRATE_WITH_POSES': 30,
        'LOAD_POSES': 40,
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
                'lidar_slam.msg.SlamCommand')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__slam_command
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__slam_command
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__slam_command
            cls._TYPE_SUPPORT = module.type_support_msg__msg__slam_command
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__slam_command

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'DISABLE_SLAM_MAP_UPDATE': cls.__constants['DISABLE_SLAM_MAP_UPDATE'],
            'ENABLE_SLAM_MAP_EXPANSION': cls.__constants['ENABLE_SLAM_MAP_EXPANSION'],
            'ENABLE_SLAM_MAP_UPDATE': cls.__constants['ENABLE_SLAM_MAP_UPDATE'],
            'RESET_TRAJECTORY': cls.__constants['RESET_TRAJECTORY'],
            'RESET_SLAM': cls.__constants['RESET_SLAM'],
            'SWITCH_ON_OFF': cls.__constants['SWITCH_ON_OFF'],
            'SAVE_TRAJECTORY': cls.__constants['SAVE_TRAJECTORY'],
            'SAVE_LIDAR_TRAJECTORY': cls.__constants['SAVE_LIDAR_TRAJECTORY'],
            'SAVE_KEYPOINTS_MAPS': cls.__constants['SAVE_KEYPOINTS_MAPS'],
            'SAVE_FILTERED_KEYPOINTS_MAPS': cls.__constants['SAVE_FILTERED_KEYPOINTS_MAPS'],
            'LOAD_KEYPOINTS_MAPS': cls.__constants['LOAD_KEYPOINTS_MAPS'],
            'OPTIMIZE_GRAPH': cls.__constants['OPTIMIZE_GRAPH'],
            'LOAD_LOOP_INDICES': cls.__constants['LOAD_LOOP_INDICES'],
            'SWITCH_SENSOR': cls.__constants['SWITCH_SENSOR'],
            'CALIBRATE_WITH_POSES': cls.__constants['CALIBRATE_WITH_POSES'],
            'LOAD_POSES': cls.__constants['LOAD_POSES'],
        }

    @property
    def DISABLE_SLAM_MAP_UPDATE(self):
        """Message constant 'DISABLE_SLAM_MAP_UPDATE'."""
        return Metaclass_SlamCommand.__constants['DISABLE_SLAM_MAP_UPDATE']

    @property
    def ENABLE_SLAM_MAP_EXPANSION(self):
        """Message constant 'ENABLE_SLAM_MAP_EXPANSION'."""
        return Metaclass_SlamCommand.__constants['ENABLE_SLAM_MAP_EXPANSION']

    @property
    def ENABLE_SLAM_MAP_UPDATE(self):
        """Message constant 'ENABLE_SLAM_MAP_UPDATE'."""
        return Metaclass_SlamCommand.__constants['ENABLE_SLAM_MAP_UPDATE']

    @property
    def RESET_TRAJECTORY(self):
        """Message constant 'RESET_TRAJECTORY'."""
        return Metaclass_SlamCommand.__constants['RESET_TRAJECTORY']

    @property
    def RESET_SLAM(self):
        """Message constant 'RESET_SLAM'."""
        return Metaclass_SlamCommand.__constants['RESET_SLAM']

    @property
    def SWITCH_ON_OFF(self):
        """Message constant 'SWITCH_ON_OFF'."""
        return Metaclass_SlamCommand.__constants['SWITCH_ON_OFF']

    @property
    def SAVE_TRAJECTORY(self):
        """Message constant 'SAVE_TRAJECTORY'."""
        return Metaclass_SlamCommand.__constants['SAVE_TRAJECTORY']

    @property
    def SAVE_LIDAR_TRAJECTORY(self):
        """Message constant 'SAVE_LIDAR_TRAJECTORY'."""
        return Metaclass_SlamCommand.__constants['SAVE_LIDAR_TRAJECTORY']

    @property
    def SAVE_KEYPOINTS_MAPS(self):
        """Message constant 'SAVE_KEYPOINTS_MAPS'."""
        return Metaclass_SlamCommand.__constants['SAVE_KEYPOINTS_MAPS']

    @property
    def SAVE_FILTERED_KEYPOINTS_MAPS(self):
        """Message constant 'SAVE_FILTERED_KEYPOINTS_MAPS'."""
        return Metaclass_SlamCommand.__constants['SAVE_FILTERED_KEYPOINTS_MAPS']

    @property
    def LOAD_KEYPOINTS_MAPS(self):
        """Message constant 'LOAD_KEYPOINTS_MAPS'."""
        return Metaclass_SlamCommand.__constants['LOAD_KEYPOINTS_MAPS']

    @property
    def OPTIMIZE_GRAPH(self):
        """Message constant 'OPTIMIZE_GRAPH'."""
        return Metaclass_SlamCommand.__constants['OPTIMIZE_GRAPH']

    @property
    def LOAD_LOOP_INDICES(self):
        """Message constant 'LOAD_LOOP_INDICES'."""
        return Metaclass_SlamCommand.__constants['LOAD_LOOP_INDICES']

    @property
    def SWITCH_SENSOR(self):
        """Message constant 'SWITCH_SENSOR'."""
        return Metaclass_SlamCommand.__constants['SWITCH_SENSOR']

    @property
    def CALIBRATE_WITH_POSES(self):
        """Message constant 'CALIBRATE_WITH_POSES'."""
        return Metaclass_SlamCommand.__constants['CALIBRATE_WITH_POSES']

    @property
    def LOAD_POSES(self):
        """Message constant 'LOAD_POSES'."""
        return Metaclass_SlamCommand.__constants['LOAD_POSES']


class SlamCommand(metaclass=Metaclass_SlamCommand):
    """
    Message class 'SlamCommand'.

    Constants:
      DISABLE_SLAM_MAP_UPDATE
      ENABLE_SLAM_MAP_EXPANSION
      ENABLE_SLAM_MAP_UPDATE
      RESET_TRAJECTORY
      RESET_SLAM
      SWITCH_ON_OFF
      SAVE_TRAJECTORY
      SAVE_LIDAR_TRAJECTORY
      SAVE_KEYPOINTS_MAPS
      SAVE_FILTERED_KEYPOINTS_MAPS
      LOAD_KEYPOINTS_MAPS
      OPTIMIZE_GRAPH
      LOAD_LOOP_INDICES
      SWITCH_SENSOR
      CALIBRATE_WITH_POSES
      LOAD_POSES
    """

    __slots__ = [
        '_command',
        '_string_arg',
    ]

    _fields_and_field_types = {
        'command': 'uint8',
        'string_arg': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.command = kwargs.get('command', int())
        self.string_arg = kwargs.get('string_arg', str())

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
        if self.command != other.command:
            return False
        if self.string_arg != other.string_arg:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def command(self):
        """Message field 'command'."""
        return self._command

    @command.setter
    def command(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'command' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'command' field must be an unsigned integer in [0, 255]"
        self._command = value

    @builtins.property
    def string_arg(self):
        """Message field 'string_arg'."""
        return self._string_arg

    @string_arg.setter
    def string_arg(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'string_arg' field must be of type 'str'"
        self._string_arg = value
