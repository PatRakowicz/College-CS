"""
This the Server-side socket connection.
This socket connection is using the TCP protocol to transport the data.
"""

from socket import *

# A pair (host, port) is used for the AF_INET address
serversocket = socket(AF_INET, SOCK_STREAM)

"""
QUESTION:
Why do we define a portnumber?
Answer: 
"""
#Prepare a server socket
hostaddress='localhost'
portnumber = 3333
serversocket.bind((hostaddress, portnumber))

"""
QUESTION:
What does the parameter 1 in the listen function indicate?
Answer: 
"""
serversocket.listen(1)

while True:
    """
    TODO:
    1. Replace hello world with the html page being requested (this will be the index.html page on the client side).
    HINT: Use the split() function on the receiving message, and don't forget to enter the current directory.
    HINT: Encode and send every line in the file.
    2. Add a try/catch to catch page not found error and return the 404error.html page
    HINT: check message being received for what page is being requested
    """
    print('server is running on port ', portnumber)
    #Establish the connection
    connectionsocket, clientaddress = serversocket.accept()
    
    #receive the message
    message = connectionsocket.recv(1024).decode()

    #This sends the HTTP header and Hello World response into socket
    connectionsocket.send("HTTP/1.0 200 OK\r\nHello World\r\n".encode())

    connectionsocket.close()

         
serversocket.close()

