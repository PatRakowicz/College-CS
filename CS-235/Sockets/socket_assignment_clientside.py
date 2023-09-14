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
clientsocket = socket(AF_INET, SOCK_STREAM)

hostaddress='localhost'
portnumber = 3333

clientsocket.connect((hostaddress, portnumber))

"""
TODO:
    1. Edit to use TCP
    HINT: you will need to establish a connection and change the sendto function
    2. Edit "message" to send a GET request for /index.html page
"""
message = "GET /help.html HTTP/1.1\r\nHost: {}\r\n\r\n".format(hostaddress)

"""
QUESTION:
    Give an example of a different HTTP request.
Answer: An example of a different HTTP request is a POST request 
        used to submit data to be processed to a specified resource.
"""

clientsocket.send(message.encode())

"""
TODO:
    Receive ALL data, decode message and print message to console
    HINT: you will need a while loop to receive all data;
    check whether the data being received is not empty and break when it is.
"""
full_data = []
while True:
    data = clientsocket.recv(1024)
    if not data:
        break
    full_data.append(data.decode())
received_message = ''.join(full_data)
print(received_message)

#close connection
clientsocket.close()


