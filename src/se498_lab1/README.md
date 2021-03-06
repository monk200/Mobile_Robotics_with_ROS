# Lab 1, pt. 1: Intro to ROS
The instructions to this lab can be found at [this link](http://coecsl.ece.illinois.edu/se498/SE498%20Lab1.pdf), where part 1 goes up until section 3 (page 7). A similar tutorial can be found on the [ROS Wiki](http://wiki.ros.org/turtlesim). At the end of the lab, students have created a program that prints a pre-set string to the terminal.   

## Edited Files
Most of the work for this portion of the lab is explicitly explained. The lab starts by creating a catkin workspace and then ensuring that it is setup properly by running turtlesim's turtle_telop_key. Later in the lab, students are guided through creating a new .cpp file, [<code>lab1.cpp</code>](https://github.com/monk200/Mobile_Robotics_with_ROS/blob/main/src/se498_lab1/src/lab1.cpp), using the terminal and writing a new ROS package which prints a set message to the terminal. Lastly, the generated [<code>CMakeLists.txt</code>](https://github.com/monk200/Mobile_Robotics_with_ROS/blob/main/src/se498_lab1/CMakeLists.txt) is edited to properly create an executable from the .cpp file.  

## Running and Testing
Start by navigating to the catkin workspace in the terminal. In the workspace, run the command <code>source devel/setup.bash</code>, followed by <code>catkin_make</code>. The first command needs to be run in every terminal before using it for ROS and the second builds the executable file. Initiate roscore by typing <code>roscore</code> in the terminal and then open a second terminal. In the second terminal, <code>source devel/setup.bash</code> needs to be run again. To run the actual executable, run <code>rosrun se498_lab1 lab1_node</code>.

## Output
![lab1_1 demo image.PNG](https://github.com/monk200/Mobile_Robotics_with_ROS/blob/main/src/se498_lab1/lab1_1%20demo%20image.PNG)
