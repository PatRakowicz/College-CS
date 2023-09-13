"""
This is the Client-side socket connection.
Currently the code is using the UDP protocol.
In order to communicate with the server-side code, you need to adjust the code to use TCP.
"""
from socket import *

"""
TODO:
Change socket to use TCP
"""
#Create socket
clientsocket = socket(AF_INET, SOCK_DGRAM)

hostaddress='localhost'
portnumber = 3333

sendingaddress = (hostaddress, portnumber)

"""
TODO:
1. Edit to use TCP
HINT: you will need to establish a connection and change the sendto function
2. Edit "message" to send a GET request for /index.html page
"""
message = "I am sending data..."

"""
QUESTION:
Give an example of a different HTTP request.
Answer: 
"""

clientsocket.sendto(message.encode(), sendingaddress)

"""
TODO:
Receive ALL data, decode message and print message to console
HINT: you will need a while loop to receive all data;
check whether the data being received is not empty and break when it is.
"""
receivemessage = clientsocket.recv(1024).decode()

#close connection
clientsocket.close()


