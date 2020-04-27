# Go Chase It
## Robotics Nanodegree

<img src="https://github.com/yesusbc/RoboND-Go-Chase-It/blob/master/gochaseit1.png" width="793" height="450">
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


# Notes
It's recommended to update and upgrade your environment before running the code.
`sudo apt-get update && sudo apt-get upgrade -y`
