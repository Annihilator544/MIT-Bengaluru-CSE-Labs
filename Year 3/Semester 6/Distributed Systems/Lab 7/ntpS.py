#					NTP ( Cristian's Algorithm) 

# Python3 program imitating a clock server

import socket			# for network communication
import datetime			#for working with dates and times

# function used to initiate the Clock Server
def initiateClockServer():   #to handle the logic of the clock server.

	s = socket.socket()   # A socket object 's' is created using socket.socket()
	print("Socket successfully created")
	
	# Server port
	port = 9000		#for the server to listen on client

	s.bind(('', port))	# socket is bound to the specified port
	
	# Start listening to requests
	s.listen(5)	 		# number of connections the system will allow before refusing new 							connections.
	print("Socket is listening...")
	
	# Clock Server Running forever
	while True: 
		connection, address = s.accept() 
		print('Server connected to', address)
		connection.send(str(datetime.datetime.now()).encode())	#The current server time is converted to 									a string, encoded into bytes, and sent to 									the client 
	    
	    # Close the connection with the client process 
		connection.close()


# Driver function
if __name__ == '__main__':			#checks if the script is being run directly, in which case it 							triggers the clock server by calling initiateClockServer().

	# Trigger the Clock Server 
	initiateClockServer()

