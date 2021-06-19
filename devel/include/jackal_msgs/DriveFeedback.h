// Generated by gencpp from file jackal_msgs/DriveFeedback.msg
// DO NOT EDIT!


#ifndef JACKAL_MSGS_MESSAGE_DRIVEFEEDBACK_H
#define JACKAL_MSGS_MESSAGE_DRIVEFEEDBACK_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace jackal_msgs
{
template <class ContainerAllocator>
struct DriveFeedback_
{
  typedef DriveFeedback_<ContainerAllocator> Type;

  DriveFeedback_()
    : current(0.0)
    , duty_cycle(0.0)
    , bridge_temperature(0.0)
    , motor_temperature(0.0)
    , measured_velocity(0.0)
    , measured_travel(0.0)
    , driver_fault(false)  {
    }
  DriveFeedback_(const ContainerAllocator& _alloc)
    : current(0.0)
    , duty_cycle(0.0)
    , bridge_temperature(0.0)
    , motor_temperature(0.0)
    , measured_velocity(0.0)
    , measured_travel(0.0)
    , driver_fault(false)  {
  (void)_alloc;
    }



   typedef float _current_type;
  _current_type current;

   typedef float _duty_cycle_type;
  _duty_cycle_type duty_cycle;

   typedef float _bridge_temperature_type;
  _bridge_temperature_type bridge_temperature;

   typedef float _motor_temperature_type;
  _motor_temperature_type motor_temperature;

   typedef float _measured_velocity_type;
  _measured_velocity_type measured_velocity;

   typedef float _measured_travel_type;
  _measured_travel_type measured_travel;

   typedef uint8_t _driver_fault_type;
  _driver_fault_type driver_fault;





  typedef boost::shared_ptr< ::jackal_msgs::DriveFeedback_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::jackal_msgs::DriveFeedback_<ContainerAllocator> const> ConstPtr;

}; // struct DriveFeedback_

typedef ::jackal_msgs::DriveFeedback_<std::allocator<void> > DriveFeedback;

typedef boost::shared_ptr< ::jackal_msgs::DriveFeedback > DriveFeedbackPtr;
typedef boost::shared_ptr< ::jackal_msgs::DriveFeedback const> DriveFeedbackConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::jackal_msgs::DriveFeedback_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::jackal_msgs::DriveFeedback_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace jackal_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'jackal_msgs': ['/home/user/catkin_ws/src/se498_lab5/jackal_simulator/jackal_pkgs/jackal_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::jackal_msgs::DriveFeedback_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::jackal_msgs::DriveFeedback_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::jackal_msgs::DriveFeedback_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::jackal_msgs::DriveFeedback_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::jackal_msgs::DriveFeedback_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::jackal_msgs::DriveFeedback_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::jackal_msgs::DriveFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "8dd0b7a3cfa20cfc5c054ddd9763609b";
  }

  static const char* value(const ::jackal_msgs::DriveFeedback_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x8dd0b7a3cfa20cfcULL;
  static const uint64_t static_value2 = 0x5c054ddd9763609bULL;
};

template<class ContainerAllocator>
struct DataType< ::jackal_msgs::DriveFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "jackal_msgs/DriveFeedback";
  }

  static const char* value(const ::jackal_msgs::DriveFeedback_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::jackal_msgs::DriveFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# This message represents feedback data from a single drive unit (driver + motor).\n\
\n\
# Current flowing from battery into the MOSFET bridge.\n\
float32 current\n\
\n\
# Instantaneous duty cycle of MOSFET bridge.\n\
float32 duty_cycle\n\
\n\
# Temperatures measured in the MOSFET bridge and on the motor casing, in deg C.\n\
float32 bridge_temperature\n\
float32 motor_temperature\n\
\n\
# Encoder data\n\
float32 measured_velocity   # rad/s\n\
float32 measured_travel     # rad\n\
\n\
# True if the underlying driver chip reports a fault condition.\n\
bool driver_fault\n\
";
  }

  static const char* value(const ::jackal_msgs::DriveFeedback_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::jackal_msgs::DriveFeedback_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.current);
      stream.next(m.duty_cycle);
      stream.next(m.bridge_temperature);
      stream.next(m.motor_temperature);
      stream.next(m.measured_velocity);
      stream.next(m.measured_travel);
      stream.next(m.driver_fault);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct DriveFeedback_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::jackal_msgs::DriveFeedback_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::jackal_msgs::DriveFeedback_<ContainerAllocator>& v)
  {
    s << indent << "current: ";
    Printer<float>::stream(s, indent + "  ", v.current);
    s << indent << "duty_cycle: ";
    Printer<float>::stream(s, indent + "  ", v.duty_cycle);
    s << indent << "bridge_temperature: ";
    Printer<float>::stream(s, indent + "  ", v.bridge_temperature);
    s << indent << "motor_temperature: ";
    Printer<float>::stream(s, indent + "  ", v.motor_temperature);
    s << indent << "measured_velocity: ";
    Printer<float>::stream(s, indent + "  ", v.measured_velocity);
    s << indent << "measured_travel: ";
    Printer<float>::stream(s, indent + "  ", v.measured_travel);
    s << indent << "driver_fault: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.driver_fault);
  }
};

} // namespace message_operations
} // namespace ros

#endif // JACKAL_MSGS_MESSAGE_DRIVEFEEDBACK_H
