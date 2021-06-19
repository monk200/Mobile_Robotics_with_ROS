#include "wallfollow.hpp"
#include <iostream>
#include "serial/serial.h"

int main(int argc,char ** argv){

  // initialize ros node
  ros::init(argc,argv,"lab2");
  ros::NodeHandle n;

  //ask user input for left/right wall following
  bool gotInput = false;
  int input = -1;
  while(!gotInput && ros::ok() ){
    std::cout <<"0: left wall follow"<< std::endl;
    std::cout <<"1: right wall follow"<<std::endl;
    std::cin >> input;
    //check if input is valid, change the condition if new input added.
    if( (input<0) || (input>1) )  std::cout<<"input "<<input<<" is invalid, please try again." <<std::endl;
    else gotInput = true;
  }

  lab2::WallFollow wf(n,input);
  // ros::spin() is a blocking functin that will continuously process callback functions
  ros::spin();
  return 0;
}
