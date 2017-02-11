#include <ros/ros.h>
#include <std_msgs/Int32.h>
#include <std_msgs/String.h>


int main(int argc, char **argv){
    ros::init(argc, argv, "taker");
    ros::NodeHandle nh;

    ros::Publisher int_pub = nh.advertise<std_msgs::Int32>("integers", 1000);
    ros::Publisher string_pub = nh.advertise<std_msgs::String>("strings", 1000);
