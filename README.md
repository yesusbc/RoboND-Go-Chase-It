# Robotics Nanodegree
This repo contains the related projects for the Udacity's Robotics Software Engineer Nanodegree.

The project was divided in 
* Part 1: `Build My World`: Designed a Gazebo World Environment for the upcoming parts.
* Part 2: `Go Chase It`: Designed and built a mobile robot, house it inside the world and then programed it with c++ Nodes in ROS to chase a white ball.
* Part 3: `Where Am I`: Used the Adaptive Monte Carlo Localization algorithm in ROS to localize the robot.
* Part 4: `Map My World`: Deployed RTAB-Mapping on the robot to simulate 2D and 3D maps of the environment.


## Go Chase It Feature (Part 1 & 2)

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



## Where Am I Feature (Part 3)
<img src= "https://github.com/yesusbc/RoboND-Go-Chase-It/blob/master/visualize/whereAmIPic.png" width="793" height="450">
This feature uses ROS AMCL package to accurately localize a mobile robot inside a map in the Gazebo simulation environments.

### Previous Installation
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

## Map My World Feature (Part 4)
To test the `rtabmap_ros` package, launch the world.

Then launch `mapping.launch`to start RTABMAP.
Then run the `teleop_key` package in order to start creating the map.

At the end you must result with something like this:
<img src= "https://github.com/yesusbc/Robotics-ND/blob/master/visualize/map3.png" width="793" height="450">

And the final map, should be something like this:
<img src= "https://github.com/yesusbc/Robotics-ND/blob/master/visualize/map2.png" width="793" height="450">

Database must be located at `~/.ros/rtabmap.db`

To analyze it, run
	`rtabmap-databaseViewer src/my_robot/db/rtabmap.db`


### Notes
It's recommended to update and upgrade your environment before running the code.
`sudo apt-get update && sudo apt-get upgrade -y`
