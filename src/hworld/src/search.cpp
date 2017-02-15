#include<ros/ros.h>
//#include<std_msgs/Int32.h>
#include<geometry_msgs/Twist.h>
#include<ros/console.h> // including level of current timestamp

ros::Publisher search_pub;
void Spiral(int x, int y);
int main(int argc, char **argv){
	ros::init(argc, argv, "search", ros::init_options::NoSigintHandler);
	ros::NodeHandle nh;

	search_pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000);

	while(ros::ok()){
		Spiral(15,15);  
	}
	return 0;
}
//geometry_msgs::Pose2D currentLocation;
//geometry_msgs::Pose2D goalLocation;
/***************************************************************
 *If the goalLocation is a clust we need to publish the location*
 *If not a clust we are not going to publish the location       *
 ****************************************************************/
void Spiral( int x, int y){
	ros::Rate rate(10); 
	geometry_msgs::Twist msg;
	int dx, dy;
	x = 0;  y = 0; dx =0;
	dy = -1;
	int X = 15; int Y = 15;
	int t = std::max(X,Y);
	int maxI = t*t;
	float incre = 0.00001 ;
	float a = 1.0;

	for(int i =0; i <10 ; i++){
		a += incre ;
		while((i%2)==0){
			msg.linear.x = a;
			msg.angular.z = M_PI_2;
			search_pub.publish(msg);
			ROS_INFO_STREAM("the vale of a:" << a );
			i = 1;
		}

		//	ROS_INFO_STREAM("the vale of modules: " << (i%2) );
		/*	if ((-X/2 <= x) && (x <= X/2) && (-Y/2 <= y) && (y <= Y/2)){

			}
			if((i%2) ==0){

			msg.angular.z = 1;
			}
			int count = 0;
			while(count == i){
			msg.linear.x = x;
			ROS_INFO_STREAM("the vale of x: " << x );
			ROS_INFO_STREAM("the vale of y: " << y );
			search_pub.publish(msg);
			count += 1;
			}
			if((x == y) || ((x < 0) && (x == -y)) || ((x > 0) && (x == 1-y))){
			t = dx;
			dx = -dy;
			dy = t;
			}
			x += dx;
			y += dy;*/
	}


	rate.sleep();
	ros::spinOnce();
}
