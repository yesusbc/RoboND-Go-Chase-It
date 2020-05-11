# Where Am I & Go Chase It (Localization and ROS Essentials)
## Robotics Nanodegree

## Where Am I Feature
<img src= "https://github.com/yesusbc/RoboND-Go-Chase-It/blob/master/visualize/whereAmIPic.png" width="793" height="450">
This feature uses ROS AMCL package to accurately localize a mobile robot inside a map in the Gazebo simulation environments.

## Previous Installation
`sudo apt-get install ros-kinetic-navigation`
`sudo apt-get install ros-kinetic-map-server`
`sudo apt-get install ros-kinetic-move-base`
`sudo apt-get install ros-kinetic-amcl`

### Testing
#### Teleop Node
You could use teleop node to control your robot and observe it localize itself in the environment.

Open another terminal and launch the teleop script:

`rosrun teleop_twist_keyboard teleop_twist_keyboard.py`

#### 2D Navigation Goal
Click the `2D Nav Goal` button in the toolbar, then click and drag on the map to send the goal to the robot. It will start moving and localize itself in the process.


## Go Chase It Feature

<img src= "https://github.com/yesusbc/RoboND-Go-Chase-It/blob/master/visualize/gochaseit3.png" width="793" height="450">
This project involves designing and building a mobile robot that is capable of chasing and following white colored balls.

### Structure
There are two packages within this repository:

#### 1. my_robot
Defines mobile robot URDF as well as the world.

#### 2. ball_chaser
Contains 2 nodes, one responsible for locating the position of the white ball, and the second for sending the respective command to follow the white ball.


### Build and Run the Project:

1. `git clone` the repository inside your catkin workspace

1. Source the workspace
`source devel/setup.bash`

1. Launch world and robot
`roslaunch my_robot world.launch`

1. To make the robot chase the white ball, open another terminal, navigate to your catking worspace, source it, and then execute:
`roslaunch ball_chaser ball_chaser.launch`


### Notes
It's recommended to update and upgrade your environment before running the code.
`sudo apt-get update && sudo apt-get upgrade -y`
