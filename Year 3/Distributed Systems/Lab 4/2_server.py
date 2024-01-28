# Import socket module
import socket

# Define the host and port for the server and the client
host = "127.0.0.1"
port = 12345

# Create a TCP socket object
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Bind the socket to the host and port
server.bind((host, port))

# Listen for incoming connections
server.listen()

# Print a message to indicate the server is ready
print("Server is ready to accept connections")

# Accept a connection from a client
client, address = server.accept()

# Print the address of the client
print(f"Connected to {address}")

# Define a function to handle communication with the client
def communicate(client):
    # Use a loop to keep exchanging messages
    while True:
        # Receive a message from the client
        message = client.recv(1024)

        # Decode the message from bytes to string
        message = message.decode()

        # Print the message from the client
        print(f"Received from client: {message}")

        # Check if the message is "bye" to end the communication
        if message == "bye":
            # Send a farewell message to the client
            client.send(b"Goodbye")

            # Close the connection with the client
            client.close()

            # Break the loop
            break

        # Input a message to send to the client
        message = input("Enter a message to send to client: ")

        # Encode the message from string to bytes
        message = message.encode()

        # Send the message to the client
        client.send(message)

# Call the communicate function with the client socket
communicate(client)
