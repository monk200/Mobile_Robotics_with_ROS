#include "cardriver/comnode.hpp"

int main(int argc, char **argv)
{
  ros::init(argc,argv,"cardriver");
  ros::NodeHandle nh;
  if(std::string(argv[1]) == "-e"){
    std::cout<<"enumerating ports"<<std::endl;
    ComNode::enumeratePorts();
    return 0;
  }
  ComNode node(nh); // parameters are setup in yaml file.

  ros::AsyncSpinner spinner(2); // Use 4 threads
  spinner.start();

  //ros::Rate r(10);
  //while(ros::ok())
  //{
  //  node.testSendCMD();
  //  r.sleep();
  //}
  //std::cout<<"Can I get here: "<< __LINE__ << std::endl;
  ros::waitForShutdown();
  //ros::spin();
//  ros::MultiThreadedSpinner spinner(2);
//  spinner.spin();
  return 0;
}
