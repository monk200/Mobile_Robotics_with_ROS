#include "wallfollow.hpp"

namespace lab2 {

/*!
 * \brief WallFollow::WallFollow
 * WallFollow class constructor, it initializes subscriber and publisher
 * to communicate with the vehicles driver
 * \param nh
 */
WallFollow::WallFollow(ros::NodeHandle &nh, int input):wallFollowInput(input){
  //initialize subscriber for each sensor topic, callback functions are
  //class private functions, 'this' is the pointer to this specific instance
  //a class variable.

  swSub = nh.subscribe("/switches",10,&WallFollow::switchCallback,this);
  irSub = nh.subscribe("/infrared",10,&WallFollow::infraredCallback,this);
  imuSub = nh.subscribe("/imu",10,&WallFollow::imuCallback,this);
  encoderSub = nh.subscribe("/encoder",10,&WallFollow::encoderCallback,this);
  //control message is published as a twist geometry mesasge type
  // only linear.x  and angular.z are used
  cmdPub = nh.advertise<geometry_msgs::Twist>("/cartCtrl",1);

  //initialize timer, such that the callback function will be periodically called
  //! NOTE: the timerCallback is the function you need to modify for this lab.
  int timerRate = 20; // rate in which the timer callback function will be called
  timer = nh.createSteadyTimer(ros::WallDuration(ros::Rate(timerRate)),&WallFollow::timerCallback,this);
  //std::cout<<"Line: "<< __LINE__ << std::endl;

}
//************************* 1st assignment ************************
// find and uncomment #define TEST_SW in wallfollow.hpp and compile.
// run the compiled code and test the switches by triggering them individually.
// what is the switch's value when its not being triggered?
// what is the switch's value when its triggered?
/*!
 * \brief WallFollow::switchCallback
 * switch data is embedded in to an 8 bit data, where the 6 least
 * significant bits represents the 6 switches, the rest 2 are un-
 * used. When the switch is triggered the bit corresponding to
 * the switch will be set.
 * \param msg
 */
void WallFollow::switchCallback(const std_msgs::UInt8::ConstPtr &msg){

  switches[0] = msg->data & 0x01;
  switches[1] = msg->data & 0x02;
  switches[2] = msg->data & 0x04;
  switches[3] = msg->data & 0x08;
  switches[4] = msg->data & 0x10;
  switches[5] = msg->data & 0x20;

#ifdef TEST_SW
  for(uint8_t i = 0; i<6; ++i){
    if(!switches[i] )
      std::cout<<"switch \t"<< (int)i + 1<< "\t is triggered" << std::endl;
  }
#endif
}
//************************* 2nd assignment **************************
// find and uncomment #define TEST_IR in wallfollow.hpp and compile.
// run the compiled code and test the infrared sensors by putting
// a piece of obstacle (preferably white) and have a sense of its
// range of capability.
/*!
 * \brief WallFollow::infraredCallback
 * infrared topic callback, it updates infrared sensor data.
 * The data is mapped from 0-255.
 * If you do
 * rostopic echo /ti/infrared
 * you can test the actual range of the infrared,
 * which is 125 for the closest reading and 0 for the furthest reading.
 * \param msg
 */
void WallFollow::infraredCallback(const cardriver::infrared::ConstPtr &msg){

  infrared[0] = msg->left;
  infrared[1] = msg->middle;
  infrared[2] = msg->right;
  infrared[3] = msg->rearLeft;
  infrared[4] = msg->rearRight;

#ifdef TEST_IR
  std::cout<<"left infrared is \t"<< (int)infrared[0];
  std::cout<<"\t middle infrared is \t" << (int)infrared[1];
  std::cout<<"\t right infrared is \t" << (int)infrared[2] <<std::endl;
  std::cout<<"rear left infrared is \t" << (int)infrared[3];
  std::cout<<"\t rear right infrared is \t" << (int)infrared[4] <<std::endl;
#endif

}

//************************** IMU callback *****************************
// imu callback will not be used in this assignment, but feel free to uncomment
// #define TEST_IMU in wallfollow.hpp and test the compiled code.
/*!
 * \brief WallFollow::imuCallback
 * this callback function updates the roll, pitch, yaw of the imu sensor.
 * Try to test and find out their units
 * \param msg
 */
void WallFollow::imuCallback(const sensor_msgs::Imu::ConstPtr &msg){

  imuOrien[0] = msg->orientation.x;  // msg contain raw 16 bit signed interger data stored in float 64 format
  imuOrien[1] = msg->orientation.y;  // msg contain raw 16 bit signed interger data stored in float 64 format
  imuOrien[2] = msg->orientation.z;  // msg contain raw 16 bit signed interger data stored in float 64 format

#ifdef TEST_IMU
  std::cout<<"pitch: \t"<< (int)imuOrien[0] <<std::endl;
  std::cout<<"roll: \t" << (int)imuOrien[1] <<std::endl;
  std::cout<<"yaw: \t" << (int)imuOrien[2] <<std::endl;
#endif

}

//************************** ENCODER callback *****************************
// encoder callback will not be used in this assignment, but feel free to uncomment
// #define TEST_ENCODER in wallfollow.hpp and test the compiled code.
/*!
 * \brief WallFollow::encoderCallback
 * this callback function updates the velocity measured by the encoder.
 * Try to test and find out their units
 * \param msg
 */


void WallFollow::encoderCallback(const cardriver::encoder::ConstPtr &msg){

  encoder[0] = msg->left;
  encoder[1] = msg->right;
  encoder[2] = msg->leftPos;
  encoder[3] = msg->rightPos;

#ifdef TEST_ENCODER
  std::cout<<"left speed is \t"<< (int)encoder[0] <<std::endl;
  std::cout<<"right speed is \t" << (int)encoder[1] <<std::endl;
  std::cout<<"left position is \t" << (int)encoder[2] <<std::endl;
  std::cout<<"right position is \t" << (int)encoder[3] <<std::endl;
#endif

}

//*******************3rd assignment (Wall following) ***********************
// Mainly modify this function to control your vehicle
// you can modify other functions and files to suit your need if needed
// You will need to satisfy the following conditions:
// 1. follow left/right wall.
// 2. detect bumper switch hitting low profile obstable
// 3. drive around the low profile obstable
//***************************************************************************
/*!
 * \brief WallFollow::timerCallback
 * You want to modify here to check sensor variables and create your control loop
 * 1. The code should allow your vehicle to follow wall on the left or wall on the right.
 * 2. When a switch is triggered by obstacle, the vehicle should try drive around it.
 * You can ignore "e"
 * \param e
 */
void WallFollow::timerCallback(const ros::SteadyTimerEvent &e){
  //declare message to be published for control
  // all varaibles in cmdMsg are initialized to 0 by default
  geometry_msgs::Twist cmdMsg;
  int errorL = 0;
  int errorM = 0;
  int errorR = 0;
  int errorRL = 0;
  int errorRR = 0;
  double distToWall = 0;

  // adjust each constant so that error = 0 when sensor is desired distance from wall when parallel
  errorL = infrared[0] - 15; // error of left sensor to target ??
  errorM = infrared[1] - 15; // error of middle sensor to target ??
  errorR = infrared[2] - 15; // error of right sensor to target ??
  errorRL = infrared[3] - 15; // error of rear left sensor to target ??
  errorRR = infrared[4] - 15; // error of rear right sensor to target ??

  /*
   * state 0: no wall, turn towards where wall should be
   * state 1: wall on side, go straight
   * state 2: wall in front and side, turn away from wall
   */

  int prev_state = state;

  switch (wallFollowInput) {
  case 0: // left wall follow
    //@HERE replace code below with your own code for left wall follow
    switch (prev_state) {
      // no wall
      case 0:
        if (errorL < 0) state = 0;
        else if (errorM >= 0 && errorL >= 0) state = 2;
        else state = 1;
      // wall on left   NEEDS MORE TUNING
      case 1:
        distToWall = (errorL + errorRL)/2;
        if (distToWall >= 0 && abs(distToWall - errorL) < 3) state = 1;
        else if (errorL >= 0 && errorRL < 0) state = 2;
        else if (errorL >= 0 && errorM >= 0) state = 2;
        else state = 0;
      // wall in front and left
      case 2:
        if (errorM >= 0) state = 2;
        else if (errorL < 0) state = 0;
        else state = 1;
    }

    switch (state) {
      // turn left
      case 0:
        cmdMsg.angular.z = 500;
        cmdMsg.linear.x = 100;
      // go straight
      case 1:
        cmdMsg.angular.z = 0;
        cmdMsg.linear.x = 150;
      // turn right
      case 2:
        cmdMsg.angular.z = -500;
        cmdMsg.linear.x = 100;
    }

    //cmdMsg.angular.z = fmax(fmin(errorL * 100, 2000), -2000);
    //cmdMsg.linear.x = 0;

    cmdPub.publish(cmdMsg);
    break;

  case 1: // right wall follow
    //@ HERE replace code below with your own code for right wall follow
    switch (prev_state) {
      // no wall
      case 0:
        if (errorR < 0) state = 0;
        else if (errorM >= 0 && errorR >= 0) state = 2;
        else state = 1;
      // wall on right
      case 1:
        distToWall = (errorR + errorRR)/2;
        if (distToWall >= 0 && abs(distToWall - errorR) < 3) state = 1;
        else if (errorR >= 0 && errorRR < 0) state = 2;
        else if (errorR >= 0 && errorM >= 0) state = 2;
        else state = 0;
      // wall in front and right
      case 2:
        if (errorM >= 0) state = 2;
        else if (errorR < 0) state  = 0;
        else state = 1;
    }

    switch (state) {
      // turn right
      case 0:
        cmdMsg.angular.z = -500;
        cmdMsg.linear.x = 100;
      // go straight
      case 1:
        cmdMsg.angular.z = 0;
        cmdMsg.linear.x = 150;
      // turn left
      case 2:
        cmdMsg.angular.z = 500;
        cmdMsg.linear.x = 100;
    }

    //cmdMsg.angular.z = fmax(fmin(errorL * 100, 2000), -2000);
    //cmdMsg.linear.x = 0;

    cmdPub.publish(cmdMsg);
    break;

  default: // should not happen
    break;
  }

  // publish the control
  cmdPub.publish(cmdMsg);

}

} // end of namespace lab2
