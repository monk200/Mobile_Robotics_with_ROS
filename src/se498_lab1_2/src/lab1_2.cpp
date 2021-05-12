#include <iostream>
#include <stdlib.h> 
#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "geometry_msgs/Twist.h"

ros::Publisher velocity_publisher;
ros::Subscriber pose_subscriber;
turtlesim::Pose turtlesim_pose;

const double x_min = 0.0;
const double y_min = 0.0;
const double x_max = 11.0;
const double y_max = 11.0;
const double PI = 3.1415926535;

double degree2radian(double value){
	return value*PI/180.0;
}

void move(double speed, double distance, bool isForward);

/********************************** Exercise 2 **********************************/
void rotate(double angular_speed, double angle, bool clockwise);

/********************************** Exercise 3 **********************************/
double getDistance(double x1, double y1, double x2, double y2);
void moveGoal(turtlesim::Pose goal_pose, double distance_tolerance);
void poseCallback(const turtlesim::Pose::ConstPtr& pose_message);


int main(int argc, char **argv){

	ros::init(argc, argv, "turtlesim_robot");

	ros::NodeHandle nh;

	double speed, angular_speed;
	double distance, angle;
	bool isForward, clockwise;

	velocity_publisher = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 100);
	pose_subscriber = nh.subscribe("/turtle1/pose", 100, poseCallback);


	ROS_INFO("\n\n\n*************** Start Program ***************\n");

	/** Test your move function here **/
	std::cout << "Enter speed: ";
	std::cin >> speed;
	std::cout << "Enter distance: ";
	std::cin >> distance;
	std::cout << "Move forward? (1 or 0): ";
	std::cin >> isForward;
	move(speed, distance, isForward);


	/* Uncomment this for tesing rotate function
	ROS_INFO("\n\n");
	std::cout << "Enter angular_speed (degree/s): ";
	std::cin >> angular_speed;
	std::cout << "Enter angle (degrees): ";
	std::cin >> angle;
	std::cout << "Clockwise? (1 or 0): ";
	std::cin >> clockwise;
	rotate(degree2radian(angular_speed), degree2radian(angle), clockwise);

	*/


    /* Uncomment this for tesing Exercise 3 program
	turtlesim::Pose pose;
	pose.x = 1;
	pose.y = 1;
	pose.theta = 0;
	moveGoal(pose, 0.05); // Move turtlesim robot to (2, 2) with 0 orientation
	*/

	ros::spin();

	return 0;

}


/*
* Move forward - x-axis of turtlesim body frame
*/ 
void move(double speed, double distance, bool isForward){

	geometry_msgs::Twist vel_msg;

	if(isForward){
		vel_msg.linear.x = abs(speed);
	}
	else{
		vel_msg.linear.x = -abs(speed);
	}

	vel_msg.linear.y = 0;
	vel_msg.linear.z = 0;

	vel_msg.angular.x = 0;
	vel_msg.angular.y = 0;
	vel_msg.angular.z = 0;

	double current_distance = 0.0;
	double t0 = ros::Time::now().toSec();
	ros::Rate loop_rate(10);

	while(current_distance < distance){

		velocity_publisher.publish(vel_msg);
		double t1 = ros::Time::now().toSec();
		current_distance = speed * (t1-t0);
		ros::spinOnce();
		loop_rate.sleep();
	}

	vel_msg.linear.x = 0;
	velocity_publisher.publish(vel_msg);
}



/********************************** Exercise 2 **********************************/

/*
* Exercise 2: finish rotate function so that turtlesim robot can rotate to a 
* given angle, input angle is in radians
*/
void rotate(double angular_speed, double angle, bool clockwise){

	geometry_msgs::Twist vel_msg;

	/*********** Your code ***************/

}

/********************************** Exercise 3 **********************************/

void poseCallback(const turtlesim::Pose::ConstPtr & pose_message){
	turtlesim_pose.x = pose_message->x;
	// turtlesim_pose.y = ??;
	// turtlesim_pose.theta = ??;
}

double getDistance(double x1, double y1, double x2, double y2){
	return sqrt(pow((x1-x2),2) + pow((y1-y2),2));
}

void moveGoal(turtlesim::Pose goal_pose, double distance_tolerance){

	geometry_msgs::Twist vel_msg;

	ros::Rate loop_rate(100);

	double relative_distance = getDistance(turtlesim_pose.x, turtlesim_pose.y, goal_pose.x, goal_pose.y);
	
	while(relative_distance > distance_tolerance){

		/****** Proportional Controller ******/

		// linear velocity in the x-axis
		double Kp = 1.0;
		// double error = ??

		// vel_msg.linear.x = ??;
		vel_msg.linear.y = 0;
		vel_msg.linear.z = 0;

		// angular velocity in the z-axis
		vel_msg.angular.x = 0;
		vel_msg.angular.y = 0;
		vel_msg.angular.z = 4*(atan2(goal_pose.y-turtlesim_pose.y, goal_pose.x-turtlesim_pose.x)-turtlesim_pose.theta);

		velocity_publisher.publish(vel_msg);
		ros::spinOnce();
		loop_rate.sleep();

		relative_distance = getDistance(turtlesim_pose.x, turtlesim_pose.y, goal_pose.x, goal_pose.y);

	}

    // Log info and stop turtlesim robot
	ROS_INFO("Arrived move goal");
	vel_msg.linear.x = 0;
	vel_msg.angular.z = 0;
	velocity_publisher.publish(vel_msg);

}