#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

void fooCallback(const std_msgs::String::ConstPtr& msg) {
 ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv) {
 ros::init(argc, argv, "tutorial");
 ros::NodeHandle n;
 ros::Publisher bar_pub = n.advertise<std_msgs::String>("foo_topic", 1000);
 ros::Subscriber sub = n.subscribe("foo_topic", 1000, fooCallback);
 ros::Rate loop_rate(10);

 while (ros::ok()) {
  std_msgs::String msg;
  std::stringstream ss;
  ss << "Hello ROS!";
  msg.data = ss.str();
  bar_pub.publish(msg);
  ros::spinOnce();
  loop_rate.sleep();
 }

 return 0;
}
