#include "ros/ros.h"
#include <std_msgs/UInt16.h>
#include "iostream"

int main(int argc, char ** argv)
{
	ros::init(argc,argv, "publisher_node");
	ros::NodeHandle n;
	ros::Publisher pub = n.advertise<std_msgs::UInt16>("servo_pos",1000);

	ros::Rate r(0.05);
	
	std_msgs::UInt16 msg;

	

	while(ros::ok())
	{
		int x=0;
    for (x=0; x<=180; x+=1){

        msg.data=x;
        pub.publish(msg);
        ros::Duration(0.02).sleep();

    }
        for (x=180; x>=0; x-=1){

        msg.data=x;
        pub.publish(msg);
        ros::Duration(0.02).sleep();

    }
 
    
    ros::spinOnce();

	}
	return 0;
}
