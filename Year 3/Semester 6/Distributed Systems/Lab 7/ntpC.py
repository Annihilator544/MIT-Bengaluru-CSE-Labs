#NTP ( Cristian's Algorithm) 

# Python3 program imitating a client process

import socket 			# for network communication
import datetime			#for working with dates and times
from dateutil import parser    # for parsing date and time strings.
from timeit import default_timer as timer	#for measuring time intervals.

# function used to Synchronize client process time
def synchronizeTime(): 			#to synchronize the client process time with the server time.

	s = socket.socket()		 
	
	# Server port
	port = 9000	
	
	# connect to the clock server on local computer 
	s.connect(('10.19.15.52', port))       #The client connects to the clock server at the specified 								IP address and port 
	request_time = timer()			# The client records the time at which it sends the request

	# receive data from the server
	server_time = parser.parse(s.recv(1024).decode())	#It receives the server's time sent in response, 
	response_time = timer() 		#The client records the time at which it receives the response 						 using timer().
	actual_time = datetime.datetime.now()	#The client retrieves its actual local time using 								datetime.datetime.now()

	print("Time returned by server: " + str(server_time))

	process_delay_latency = response_time - request_time

	print("Process Delay latency: " \
		+ str(process_delay_latency) \
		+ " seconds")

	print("Actual clock time at client side: " \
		+ str(actual_time))

	# synchronize process client clock time
	client_time = server_time \
					+ datetime.timedelta(seconds = \
							(process_delay_latency) / 2)

	print("Synchronized process client time: " \
						+ str(client_time))

	# calculate synchronization error 
	error = actual_time - client_time
	print("Synchronization error : "
				+ str(error.total_seconds()) + " seconds")

	s.close()	 


# Driver function
if __name__ == '__main__':

	# synchronize time using clock server
	synchronizeTime()

