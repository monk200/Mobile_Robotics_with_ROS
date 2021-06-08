#pragma once
#include <ros/ros.h>
#include <std_msgs/UInt8.h> // include for switch
#include <cardriver/infrared.h>
#include <cardriver/encoder.h>
#include <sensor_msgs/Imu.h>
#include <geometry_msgs/Twist.h>  //command publish message type
#include <iostream>
#include <math.h>

//#define TEST_SW //uncomment this line to test switches callback
//#define TEST_IR //uncomment this line to test infrared callback
//#define TEST_IMU//uncomment this line to test imu callback
//#define TEST_ENCODER//uncomment this line to test encoder callback

namespace lab2 { //namespance lab2

class WallFollow
{
private:
  //callback functions:
  void switchCallback(const std_msgs::UInt8::ConstPtr& msg);
  void infraredCallback(const cardriver::infrared::ConstPtr& msg);
  void imuCallback(const sensor_msgs::Imu::ConstPtr& msg);
  void encoderCallback(const cardriver::encoder::ConstPtr& msg);
  void timerCallback(const ros::SteadyTimerEvent& e);
  //private variables:
  bool switches[6] = {0,0,0,0,0,0};
  uint8_t state = 0;
  uint8_t infrared[5] = {0,0,0,0,0};
  int16_t imuOrien[3] = {0,0,0};
  int16_t encoder[4] = {0,0,0,0};
  int wallFollowInput;
public:
  //functions
  WallFollow(ros::NodeHandle& nh,int input);
  //public variables
  ros::Publisher cmdPub;  // command publisher
  ros::Subscriber swSub, irSub, imuSub, encoderSub; // subscribers
  ros::SteadyTimer timer;

};

} // end of namespace lab2


