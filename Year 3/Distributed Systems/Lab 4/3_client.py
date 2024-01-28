# Import socket module
import socket

# Define the host and port of the server
host = "127.0.0.1"
port = 12345

# Create a TCP socket object for the client
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect to the server
client.connect((host, port))

# Print a message to indicate the connection is established
print("Connected to the server")

# Define a function to handle communication with the server
def communicate(server):
    # Use a loop to keep exchanging messages
    while True:
        # Input a message to send to the server
        message = input("Enter a message to send to server: ")

        # Encode the message from string to bytes
        message = message.encode()

        # Send the message to the server
        server.send(message)

        # Check if the message is "bye" to end the communication
        if message == b"bye":
            # Receive a farewell message from the server
            message = server.recv(1024)

            # Decode the message from bytes to string
            message = message.decode()

            # Print the message from the server
            print(f"Received from server: {message}")

            # Close the connection with the server
            server.close()

            # Break the loop
            break

        # Receive a message from the server
        message = server.recv(1024)

        # Decode the message from bytes to string
        message = message.decode()

        # Print the message from the server
        print(f"Received from server: {message}")

# Call the communicate function with the server socket
communicate(client)
