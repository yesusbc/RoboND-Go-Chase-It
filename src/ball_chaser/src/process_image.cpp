#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>

// Define a global client that can request services
ros::ServiceClient client;

// This function calls the command_robot service to drive the robot in the specified direction
void drive_robot(float lin_x, float ang_z)
{
    // TODO: Request a service and pass the velocities to it to drive the robot
	ROS_INFO_STREAM("Driving the robot into specified direction");

    // Request linear x and angular z
    ball_chaser::DriveToTarget srv;
    srv.request.linear_x = lin_x;
    srv.request.angular_z = ang_z;

    // Call the drive to target service and pass the requested direction
    if (!client.call(srv))
        ROS_ERROR("Failed to call service safe_move");

}

// This callback function continuously executes and reads the image data
void process_image_callback(const sensor_msgs::Image img)
{

    const int white_pixel = 255;
	const int max_left = img.width /3;
	const int max_right = 2 * img.width /3;

	int white_left = 0;
	int white_right = 0;
	int white_forward = 0;
	int x_position = 0;

    // TODO: Loop through each pixel in the image and check if there's a bright white one
    // Then, identify if this pixel falls in the left, mid, or right side of the image
    // Depending on the white ball position, call the drive_bot function and pass velocities to it
    // Request a stop when there's no white ball seen by the camera

	for(int i = 0; i < img.height * img.step; i+=3) {
		if(white_pixel == img.data[i] && 
			white_pixel == img.data[i+1] &&
			white_pixel == img.data[i+2]) {

			x_position = (i % img.step) / 3;

			if (x_position < max_left)
			{
			   white_left += 1;
			} else if (x_position > max_right)
			{
				white_right += 1;
			} else
			{
				white_forward += 1;
			}
		}
	}

	if(white_left > white_right && white_left > white_forward) 
	{
		drive_robot(0, 1);    // Move to the left
	} else if (white_right > white_left && white_right > white_forward)
	{
		drive_robot(0, -1);    // Move to the right
	} else if (white_forward > white_left && white_forward > white_right)
	{
		drive_robot(0.8, 0.0);    // Move forward
	} else{
		drive_robot(0.0, 0.0); // stop
	}

}


int main(int argc, char** argv)
{
    // Initialize the process_image node and create a handle to it
    ros::init(argc, argv, "process_image");
    ros::NodeHandle n;

    // Define a client service capable of requesting services from command_robot
    client = n.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");

    // Subscribe to /camera/rgb/image_raw topic to read the image data inside the process_image_callback function
    ros::Subscriber sub1 = n.subscribe("/camera/rgb/image_raw", 10, process_image_callback);

    // Handle ROS communication events
    ros::spin();

    return 0;
}
