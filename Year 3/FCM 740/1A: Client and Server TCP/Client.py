
import socket
def main():
 server_ip = 'localhost'
 server_port = 12000
  
 # Creates a TCP socket
 client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
 
 # Connects to the server
 client_socket.connect((server_ip, server_port))
 
 # Reads a line of characters from the user
 data = input("Enter a line of characters: ")
 
 # Sends the data to the server
 client_socket.sendall(data.encode())
 
 # Receives the modified data from the server
 modified_data = client_socket.recv(1024)
 
 # Display the modified line
 print("Modified line from server:", modified_data.decode())
 
 # Closes the socket
 client_socket.close()
 
if __name__ == "__main__":
 main()
