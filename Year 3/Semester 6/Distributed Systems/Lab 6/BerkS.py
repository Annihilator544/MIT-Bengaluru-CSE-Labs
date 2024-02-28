#						Berkeley algorithm

# Python3 program imitating a clock server

from functools import reduce   	
from dateutil import parser  #This function is used to parse date and time strings into Python datetime objects.
import threading	   #This module provides high-level threading API for working with threads (Concurrent 				Execution) in Python.
import datetime		# provides classes for manipulating dates and times in Python.
import socket		# for network communication
import time		# This module provides various time-related functions, including sleep() for introducing 				delays in code execution.


# datastructure used to store client address and clock data
client_data = {}		# an assignment statement that creates an empty dictionary named client_data to 					store client addresses and their clock data.


''' nested thread function used to receive 
	clock time from a connected client '''
def startReceivingClockTime(connector, address):	#is defined to run as a thread, continuously receiving 							clock time from connected clients and updating 									client_data.

	while True:	#continuously receives clock time from the client and updates the client data.
		# receive clock time
		clock_time_string = connector.recv(1024).decode()
		clock_time = parser.parse(clock_time_string)
		clock_time_diff = datetime.datetime.now() - \
						clock_time

		client_data[address] = {
					"clock_time"	 : clock_time,
					"time_difference" : clock_time_diff,
					"connector"	 : connector
					}

		print("Client Data updated with: "+ str(address), end = "\n\n")
		time.sleep(5)			#This line causes the program to pause execution for 5 seconds 						before restarting the loop. This can help reduce CPU usage and 							prevent unnecessary processing if clock updates are not received 						frequently.


''' master thread function used to open portal for 
	accepting clients over given port '''
def startConnecting(master_server):   #This function is intended to continuously accept connections from clients 					(slaves) and initiate a thread to handle each connection.
	
	# fetch clock time at slaves / clients
	while True:
		# accepting a client / slave clock client
		master_slave_connector, addr = master_server.accept() #This line waits until a client connects to 									the master_server socket. When a client 									connects, it accepts the connection and 									returns a new socket object 											master_slave_connector representing the 									connection, and the address of the 									        client.

		slave_address = str(addr[0]) + ":" + str(addr[1])   #This line creates a string representation of 								      the client's address by concatenating the IP 									address and port number with a colon 										separator.

		print(slave_address + " got connected successfully")

		current_thread = threading.Thread(
						target = startReceivingClockTime,
						args = (master_slave_connector, slave_address, ))

		current_thread.start()    #This line starts the thread, which will execute the 							    startReceivingClockTime function concurrently with the main thread. 					    This allows the server to handle multiple client connections 						    simultaneously.


# subroutine function used to fetch average clock difference
def getAverageClockDiff():

	current_client_data = client_data.copy()  #This line creates a shallow copy of the client_data 							    dictionary. This copy ensures that the original client_data 						    dictionary remains unchanged during the computation of the 							    average clock difference.

	time_difference_list = list(client['time_difference'] 
				for client_addr, client in client_data.items()) #This line creates a list 											comprehension that iterates over 										the items of the client_data 											dictionary. For each client, it 										extracts the 'time_difference' 											value and adds it to the list 											time_difference_list. This list 										will contain all the time 											differences between the server and 										each client.
									

	sum_of_clock_difference = sum(time_difference_list, \
				datetime.timedelta(0, 0))	#This line calculates the sum of all time 									differences in time_difference_list. It uses the 								sum() function to sum up all the timedelta objects 								in the list. The initial value is 										datetime.timedelta(0, 0), ensuring that if 									time_difference_list is empty, the sum defaults to 								zero.

	average_clock_difference = sum_of_clock_difference \
					/ len(client_data)     # This line calculates the average clock 									difference by dividing the sum of all time 									differences by the number of clients 										This represents the average difference between the 								server's time and the clients' times.

	return average_clock_difference


''' master sync thread function used to generate 
	cycles of clock synchronization in the network '''
def synchronizeAllClocks():

	while True:

		print("New synchronization cycle started.")
		print("Number of clients to be synchronized: " + \
							str(len(client_data)))

	# Synchronization Process:```

		if len(client_data) > 0: 

			average_clock_difference = getAverageClockDiff()

			for client_addr, client in client_data.items():
				try:
					synchronized_time = \
						datetime.datetime.now() + \
									average_clock_difference

					client['connector'].send(str(
							synchronized_time).encode())


				except Exception as e:
					print("Something went wrong while " + \
						"sending synchronized time " + \
						"through " + str(client_addr))
# Handling No Clients:

		else :
			print("No client data." + \
						" Synchronization not applicable.")

		print("\n\n")

		time.sleep(5)


# function used to initiate the Clock Server / Master Node
def initiateClockServer(port = 8080):

	master_server = socket.socket()  #This line creates a new socket object master_server using the 						   socket.socket() function. This socket will be used to accept incoming 					   connections from clients.#

	master_server.setsockopt(socket.SOL_SOCKET,
					socket.SO_REUSEADDR, 1)

#Set Socket Options:

	master_server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1) 
	print("Socket at master node created successfully\n")
	
	master_server.bind(('', port))

#This line binds the socket to the specified port (port) on all available network interfaces. This prepares the server to accept incoming connections on the specified port.#

	# Start listening to requests
	master_server.listen(10)

#This line starts listening for incoming connections. It sets the maximum number of queued connections to 10, which means that if more than 10 clients try to connect simultaneously, additional connection attempts will be refused.#
	
	print("Clock server started...\n")

	# start making connections
	print("Starting to make connections...\n")
	master_thread = threading.Thread(
						target = startConnecting,
						args = (master_server, ))
	master_thread.start()

#master_thread = threading.Thread(target=startConnecting, args=(master_server,)): This line creates a new thread master_thread that will execute the startConnecting function with master_server as an argument. This function handles accepting connections from clients.

	# start synchronization
	print("Starting synchronization parallelly...\n")
	sync_thread = threading.Thread(
						target = synchronizeAllClocks,
						args = ())
	sync_thread.start()

# sync_thread = threading.Thread(target=synchronizeAllClocks, args=()): This line creates a new thread sync_thread that will execute the synchronizeAllClocks function. This function is responsible for synchronizing the clocks of connected clients with the server's clock.
	sync_thread.start()

# Driver function
if __name__ == '__main__':

	# Trigger the Clock Server
	initiateClockServer(port = 8080)


# When you run a Python script directly, the Python interpreter sets the special variable __name__ to '__main__' for that script.