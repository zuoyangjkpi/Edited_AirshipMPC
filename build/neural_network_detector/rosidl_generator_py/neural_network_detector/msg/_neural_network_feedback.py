# generated from rosidl_generator_py/resource/_idl.py.em
# with input from neural_network_detector:msg/NeuralNetworkFeedback.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_NeuralNetworkFeedback(type):
    """Metaclass of message 'NeuralNetworkFeedback'."""

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
            module = import_type_support('neural_network_detector')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'neural_network_detector.msg.NeuralNetworkFeedback')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__neural_network_feedback
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__neural_network_feedback
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__neural_network_feedback
            cls._TYPE_SUPPORT = module.type_support_msg__msg__neural_network_feedback
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__neural_network_feedback

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


class NeuralNetworkFeedback(metaclass=Metaclass_NeuralNetworkFeedback):
    """Message class 'NeuralNetworkFeedback'."""

    __slots__ = [
        '_header',
        '_ymin',
        '_ymax',
        '_xcenter',
        '_debug_included',
        '_head_raw',
        '_feet_raw',
        '_ycenter',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'ymin': 'int16',
        'ymax': 'int16',
        'xcenter': 'int16',
        'debug_included': 'boolean',
        'head_raw': 'int16',
        'feet_raw': 'int16',
        'ycenter': 'int16',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.ymin = kwargs.get('ymin', int())
        self.ymax = kwargs.get('ymax', int())
        self.xcenter = kwargs.get('xcenter', int())
        self.debug_included = kwargs.get('debug_included', bool())
        self.head_raw = kwargs.get('head_raw', int())
        self.feet_raw = kwargs.get('feet_raw', int())
        self.ycenter = kwargs.get('ycenter', int())

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
        if self.ymin != other.ymin:
            return False
        if self.ymax != other.ymax:
            return False
        if self.xcenter != other.xcenter:
            return False
        if self.debug_included != other.debug_included:
            return False
        if self.head_raw != other.head_raw:
            return False
        if self.feet_raw != other.feet_raw:
            return False
        if self.ycenter != other.ycenter:
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
    def ymin(self):
        """Message field 'ymin'."""
        return self._ymin

    @ymin.setter
    def ymin(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ymin' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'ymin' field must be an integer in [-32768, 32767]"
        self._ymin = value

    @builtins.property
    def ymax(self):
        """Message field 'ymax'."""
        return self._ymax

    @ymax.setter
    def ymax(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ymax' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'ymax' field must be an integer in [-32768, 32767]"
        self._ymax = value

    @builtins.property
    def xcenter(self):
        """Message field 'xcenter'."""
        return self._xcenter

    @xcenter.setter
    def xcenter(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'xcenter' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'xcenter' field must be an integer in [-32768, 32767]"
        self._xcenter = value

    @builtins.property
    def debug_included(self):
        """Message field 'debug_included'."""
        return self._debug_included

    @debug_included.setter
    def debug_included(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'debug_included' field must be of type 'bool'"
        self._debug_included = value

    @builtins.property
    def head_raw(self):
        """Message field 'head_raw'."""
        return self._head_raw

    @head_raw.setter
    def head_raw(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'head_raw' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'head_raw' field must be an integer in [-32768, 32767]"
        self._head_raw = value

    @builtins.property
    def feet_raw(self):
        """Message field 'feet_raw'."""
        return self._feet_raw

    @feet_raw.setter
    def feet_raw(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'feet_raw' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'feet_raw' field must be an integer in [-32768, 32767]"
        self._feet_raw = value

    @builtins.property
    def ycenter(self):
        """Message field 'ycenter'."""
        return self._ycenter

    @ycenter.setter
    def ycenter(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ycenter' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'ycenter' field must be an integer in [-32768, 32767]"
        self._ycenter = value
