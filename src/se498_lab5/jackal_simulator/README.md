# Lab 5: The Jackal Simulation with Gazebo and Rviz
The instructions to this lab can be found at [this link](http://coecsl.ece.illinois.edu/se498/SE498%20Lab5.pdf). The overall lab guides students through setting up Linux on their personal computer and then gets comfortable using Gazebo and Rviz to make and explore testing environments.  

## Edited Files
No given files were edited during this lab. I just made various randomly generated maps with Rviz and custom maps with Gazebo to get familiar with the tools for later labs.  

## Running
The base simulation can be run by typing <code>roslaunch jackal_gazebo jackal_world.launch config:front_laser</code> into the terminal. Rviz can be used to navigate the Jackal without a map by typing <code>roslaunch jackal_navigation odom_navigation_demo.launch</code> and <code>roslaunch jackal_viz view_robot.launch config:=navigation</code> into two terminals.  

Rviz can be used to generate a random map by typing <code>roslaunch jackal_navigation gmapping_demo.launch</code>, <code>roslaunch jackal_viz view_robot.launch config:=gmapping</code>, and <code>rosrun map_server map_saver -f mymap</code> into three terminals. This map can then be used to navigate by typing <code>roslaunch jackal_navigation amcl_demo.launch map_file:=/path/to/my/map.yaml</code> and <code>roslaunch jackal_viz view_robot.launch config:=localization</code> into two terminals. The "Set 2D Pose" tool in Rviz needs to be used to give the Jackal a goal position to navigate to. These steps can be repeated with the .world file made from creating a custom environment in Gazebo.
