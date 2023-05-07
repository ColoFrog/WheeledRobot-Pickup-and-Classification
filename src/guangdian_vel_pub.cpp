/*
	节点guangdian_vel_pub创建发布者gd_vel_pub发布速度话题gd/cmd_vel，消息类型geometry_msgs::Twist
*/
#include<ros/ros.h>
#include<geometry_msgs/Twist.h>

int main(int argc,char **argv)
{
	//节点初始化,命名节点
	ros::init(argc,argv,"guangdian_vel_pub");

	//节点句柄
	ros::NodeHandle n;

	//创建Publisher gd_vel_pub发布小车定义的消息类型为geometry_msgs::Twist的消息gd/cmd_vel,队列10
	ros::Publisher gd_vel_pub=n.advertise<geometry_msgs::Twist>("/gd/cmd_vel",10);

	//循环频率
	ros::Rate loop_rate(10);

	int count=0;
	//开始循环
	while(ros::ok())
	{
		//初始化消息
		geometry_msgs::Twist vel_msg;
		vel_msg.linear.x=0.5;
		vel_msg.angular.z=0.2;

		//发布消息
		gd_vel_pub.publish(vel_msg);
		ROS_INFO("gd_vel_pub[%0.2fm/s , %0.2frad/s]",vel_msg.linear.x,vel_msg.angular.z);

		//按照频率循环
		loop_rate.sleep();
	}
	return 0;
}