# generated from rosidl_generator_py/resource/_idl.py.em
# with input from neural_network_detector:msg/NeuralNetworkDetection.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_NeuralNetworkDetection(type):
    """Metaclass of message 'NeuralNetworkDetection'."""

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
                'neural_network_detector.msg.NeuralNetworkDetection')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__neural_network_detection
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__neural_network_detection
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__neural_network_detection
            cls._TYPE_SUPPORT = module.type_support_msg__msg__neural_network_detection
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__neural_network_detection

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


class NeuralNetworkDetection(metaclass=Metaclass_NeuralNetworkDetection):
    """Message class 'NeuralNetworkDetection'."""

    __slots__ = [
        '_header',
        '_object_class',
        '_detection_score',
        '_xmin',
        '_xmax',
        '_ymin',
        '_ymax',
        '_variance_xmin',
        '_variance_xmax',
        '_variance_ymin',
        '_variance_ymax',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'object_class': 'int16',
        'detection_score': 'float',
        'xmin': 'int16',
        'xmax': 'int16',
        'ymin': 'int16',
        'ymax': 'int16',
        'variance_xmin': 'float',
        'variance_xmax': 'float',
        'variance_ymin': 'float',
        'variance_ymax': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.object_class = kwargs.get('object_class', int())
        self.detection_score = kwargs.get('detection_score', float())
        self.xmin = kwargs.get('xmin', int())
        self.xmax = kwargs.get('xmax', int())
        self.ymin = kwargs.get('ymin', int())
        self.ymax = kwargs.get('ymax', int())
        self.variance_xmin = kwargs.get('variance_xmin', float())
        self.variance_xmax = kwargs.get('variance_xmax', float())
        self.variance_ymin = kwargs.get('variance_ymin', float())
        self.variance_ymax = kwargs.get('variance_ymax', float())

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
        if self.object_class != other.object_class:
            return False
        if self.detection_score != other.detection_score:
            return False
        if self.xmin != other.xmin:
            return False
        if self.xmax != other.xmax:
            return False
        if self.ymin != other.ymin:
            return False
        if self.ymax != other.ymax:
            return False
        if self.variance_xmin != other.variance_xmin:
            return False
        if self.variance_xmax != other.variance_xmax:
            return False
        if self.variance_ymin != other.variance_ymin:
            return False
        if self.variance_ymax != other.variance_ymax:
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
    def object_class(self):
        """Message field 'object_class'."""
        return self._object_class

    @object_class.setter
    def object_class(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'object_class' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'object_class' field must be an integer in [-32768, 32767]"
        self._object_class = value

    @builtins.property
    def detection_score(self):
        """Message field 'detection_score'."""
        return self._detection_score

    @detection_score.setter
    def detection_score(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'detection_score' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'detection_score' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._detection_score = value

    @builtins.property
    def xmin(self):
        """Message field 'xmin'."""
        return self._xmin

    @xmin.setter
    def xmin(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'xmin' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'xmin' field must be an integer in [-32768, 32767]"
        self._xmin = value

    @builtins.property
    def xmax(self):
        """Message field 'xmax'."""
        return self._xmax

    @xmax.setter
    def xmax(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'xmax' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'xmax' field must be an integer in [-32768, 32767]"
        self._xmax = value

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
    def variance_xmin(self):
        """Message field 'variance_xmin'."""
        return self._variance_xmin

    @variance_xmin.setter
    def variance_xmin(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'variance_xmin' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'variance_xmin' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._variance_xmin = value

    @builtins.property
    def variance_xmax(self):
        """Message field 'variance_xmax'."""
        return self._variance_xmax

    @variance_xmax.setter
    def variance_xmax(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'variance_xmax' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'variance_xmax' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._variance_xmax = value

    @builtins.property
    def variance_ymin(self):
        """Message field 'variance_ymin'."""
        return self._variance_ymin

    @variance_ymin.setter
    def variance_ymin(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'variance_ymin' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'variance_ymin' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._variance_ymin = value

    @builtins.property
    def variance_ymax(self):
        """Message field 'variance_ymax'."""
        return self._variance_ymax

    @variance_ymax.setter
    def variance_ymax(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'variance_ymax' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'variance_ymax' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._variance_ymax = value
