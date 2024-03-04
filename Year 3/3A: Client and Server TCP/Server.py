
import socket
def main():
 server_ip = 'localhost'
 server_port = 12000
 
 # Creates a TCP socket
 server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
 
 # Binds the socket to the server address and port
 server_socket.bind((server_ip, server_port))
 
 # Listens for incoming connections
 server_socket.listen(1)
 
 print("The server is ready to receive")
 
 while True:
 # Accepts a client connection
 connection_socket, client_address = server_socket.accept()
 
 try:
 # Receives data from the client
 data = connection_socket.recv(1024)
 
 if data:
 print ("Received data from client: ", data.decode())
 
# Converts the received characters to uppercase
 modified_data = data.upper()
 
 # Sends the modified data back to the client
connection_socket.sendall(modified_data)

 finally:
 # Closes the connection socket
 connection_socket.close()
 
if __name__ == "__main__":
 main()
