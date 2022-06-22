#!/usr/bin/env python

import rospy
from std_msgs.msg import String 

def talker():
	#crear un publicador, donde especifiquemos el nombre del topico, despues el tipo de mensaje y el tamanio de la cola
	pub = rospy.Publisher('chatter', String, queue_size=10)
	#vamos a inicializar el nodo
	rospy.init_node('talker', anonymous = True)
	#Definir la frecuencia de publicacion 
	rate = rospy.Rate(1) #1 Hz
	
	i = 0
	while not rospy.is_shutdown():
		hello_str = "Motomami %s" %i
		rospy.loginfo(hello_str)
		pub.publish(hello_str)
		i = i + 1

if __name__ == '__main__':
	try:
		talker();
	except rospy.ROSInterruptionException:
		pass
