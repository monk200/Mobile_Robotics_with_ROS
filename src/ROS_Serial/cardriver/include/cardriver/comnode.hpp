#ifndef COMNODE_H
#define COMNODE_H

#include <ros/ros.h>
#include <iostream>
#include <exception>
#include <cardriver/structs.h>
#include <string>
#include <memory>
#include <serial/serial.h>
#include <vector>
#include <geometry_msgs/Twist.h>
#include <std_msgs/UInt8.h>
#include <cardriver/infrared.h>
#include <cardriver/encoder.h>
#include <sensor_msgs/Imu.h>

// 115200 baud rate is 14400 bytes/s
// rate of transmission is 100hz
// number of byte can be transmitted per transmission is is 14400/100

class ComNode
{
private:
  /* function */
  void timerCallback(const ros::SteadyTimerEvent &e);
  void initParameter(ros::NodeHandle &nh);
  void initSerial();
  void initROS(ros::NodeHandle & nh);
  bool sendCMD(cmd& cmd_data);
  void twistCallback(const geometry_msgs::Twist::ConstPtr & msg);
  /* variable*/
  int timerRate, baudRate, transRate;
  std::string port;
  int inter_byte_timeout, read_timeout_constant, read_timeout_multiplier,
      write_timeout_constant, write_timeout_multiplier;
  float wheel_base_distance;
  std::unique_ptr<serial::Serial> serialPtr;
  ros::Subscriber twistSub;
  ros::Publisher irPub;
  ros::Publisher swPub;
  ros::Publisher imuPub;
  ros::Publisher encoderPub;

public:
  /* public function */
  ComNode(ros::NodeHandle & nh);
  ~ComNode();
  static void enumeratePorts();
  void testSendCMD();
  /* public variables */
  ros::SteadyTimer timer;
};

struct exceptionParameterInit : public std::exception {
   const char * what () const throw () {
      return "Cannot find required parameters in parameter server";
   } 
};

#endif // COMNODE_H
