
#节点guangdian_vel_pub创建发布者gd_vel_pub发布速度话题gd/cmd_vel，消息类型geometry_msgs::Twist

import rospy
from geometry_msgs.msg import Twist

def guangdian_vel_pub():

	#节点初始化,命名节点
	rospy.init_node('guangdian_vel_pub',anonymous=True)

	#创建Publisher gd_vel_pub发布小车定义的消息类型为geometry_msgs::Twist的消息gd/cmd_vel,队列10
	gd_vel_pub=rospy.Publisher('/gd/cmd_vel',Twist,queue_size=10)

	#循环频率
	rate=rospy.Rate(10)

	while not rospy.is_shutdown():

		#初始化消息
		vel_msg=Twist()
		vel_msg.linear.x=0.5
		vel_msg.angular.z=0.2

		#发布消息
		gd_vel_pub.publish(vel_msg)
		rospy.loginfo('gd_vel_pub[%0.2fm/s , %0.2frad/s]',vel_msg.linear.x,vel_msg.angular.z)

		#按照频率循环
		rate.sleep()

if __name__=='__main__':
	try:
		guangdian_vel_pub()
	except rospy.ROSInterruptException:
		pass