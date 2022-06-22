#!/usr/bin/env python
import rospy
import math
from geometry_msgs.msg import Twist
import sys


def turtle_rec(b, a):
	rospy.init_node('turtlesim', anonymous=True)
	pub = rospy.Publisher('/turtle1/cmd_vel',
						Twist, queue_size=10)
	rate = rospy.Rate(1)
	vel = Twist()
	while not rospy.is_shutdown():
		rate.sleep()
		vel.linear.x = b
		vel.linear.y = 0
		vel.linear.z = 0
		vel.angular.x = 0
		vel.angular.y = 0
		vel.angular.z = 0
		pub.publish(vel)
		rate.sleep()
		vel.linear.x = 0
		vel.linear.y = 0
		vel.linear.z = 0
		vel.angular.x = 0
		vel.angular.y = 0
		vel.angular.z = 1.56200
		pub.publish(vel)
		rate.sleep()
		vel.linear.x = a
		vel.linear.y = 0
		vel.linear.z = 0
		vel.angular.x = 0
		vel.angular.y = 0
		vel.angular.z = 0
		pub.publish(vel)
		rate.sleep()
		vel.linear.x = 0
		vel.linear.y = 0
		vel.linear.z = 0
		vel.angular.x = 0
		vel.angular.y = 0
		vel.angular.z = 1.56200
		pub.publish(vel)



if __name__ == '__main__':
	try:
		turtle_rec(float(sys.argv[1]), float(sys.argv[2]))
	except rospy.ROSInterruptException:
		pass
