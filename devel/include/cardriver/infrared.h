// Generated by gencpp from file cardriver/infrared.msg
// DO NOT EDIT!


#ifndef CARDRIVER_MESSAGE_INFRARED_H
#define CARDRIVER_MESSAGE_INFRARED_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace cardriver
{
template <class ContainerAllocator>
struct infrared_
{
  typedef infrared_<ContainerAllocator> Type;

  infrared_()
    : left(0)
    , middle(0)
    , right(0)
    , rearLeft(0)
    , rearRight(0)  {
    }
  infrared_(const ContainerAllocator& _alloc)
    : left(0)
    , middle(0)
    , right(0)
    , rearLeft(0)
    , rearRight(0)  {
  (void)_alloc;
    }



   typedef uint8_t _left_type;
  _left_type left;

   typedef uint8_t _middle_type;
  _middle_type middle;

   typedef uint8_t _right_type;
  _right_type right;

   typedef uint8_t _rearLeft_type;
  _rearLeft_type rearLeft;

   typedef uint8_t _rearRight_type;
  _rearRight_type rearRight;





  typedef boost::shared_ptr< ::cardriver::infrared_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::cardriver::infrared_<ContainerAllocator> const> ConstPtr;

}; // struct infrared_

typedef ::cardriver::infrared_<std::allocator<void> > infrared;

typedef boost::shared_ptr< ::cardriver::infrared > infraredPtr;
typedef boost::shared_ptr< ::cardriver::infrared const> infraredConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::cardriver::infrared_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::cardriver::infrared_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace cardriver

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'cardriver': ['/home/user/catkin_ws/src/ROS_Serial/cardriver/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::cardriver::infrared_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::cardriver::infrared_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cardriver::infrared_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cardriver::infrared_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cardriver::infrared_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cardriver::infrared_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::cardriver::infrared_<ContainerAllocator> >
{
  static const char* value()
  {
    return "8763b3893fce39888eb6c9b2ac70a0e5";
  }

  static const char* value(const ::cardriver::infrared_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x8763b3893fce3988ULL;
  static const uint64_t static_value2 = 0x8eb6c9b2ac70a0e5ULL;
};

template<class ContainerAllocator>
struct DataType< ::cardriver::infrared_<ContainerAllocator> >
{
  static const char* value()
  {
    return "cardriver/infrared";
  }

  static const char* value(const ::cardriver::infrared_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::cardriver::infrared_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint8 left\n\
uint8 middle\n\
uint8 right\n\
uint8 rearLeft\n\
uint8 rearRight\n\
\n\
";
  }

  static const char* value(const ::cardriver::infrared_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::cardriver::infrared_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.left);
      stream.next(m.middle);
      stream.next(m.right);
      stream.next(m.rearLeft);
      stream.next(m.rearRight);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct infrared_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::cardriver::infrared_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::cardriver::infrared_<ContainerAllocator>& v)
  {
    s << indent << "left: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.left);
    s << indent << "middle: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.middle);
    s << indent << "right: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.right);
    s << indent << "rearLeft: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.rearLeft);
    s << indent << "rearRight: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.rearRight);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CARDRIVER_MESSAGE_INFRARED_H
