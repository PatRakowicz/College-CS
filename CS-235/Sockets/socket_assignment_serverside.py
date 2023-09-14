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
Answer: We define a port number to identify a specific process to which data is to be sent once the 
        IP address has been reached. It allows multiple processes to listen and send data on the same 
        IP address without interfering with each other.
"""
# Prepare a server socket
hostaddress = 'localhost'
portnumber = 3333
serversocket.bind((hostaddress, portnumber))

"""
QUESTION:
    What does the parameter 1 in the listen function indicate?
Answer: The parameter '1' in the listen function indicates the maximum number of queued connections. 
        In this case, it means that if one connection is already being handled, the server will keep 
        one more connection request waiting in a queue. If a third connection request comes in while these 
        two are being handled, it would be refused.
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
    print('Server is running on port: ', portnumber)
    # Establish the connection
    connectionsocket, clientaddress = serversocket.accept()

    # receive the message
    message = connectionsocket.recv(1024).decode()

    print("Received from client:", message)

    try:
        filename = message.split(' ')[1]
        print(f"Loading page: {filename[1:]}")
        with open(filename[1:], 'r') as f:
            outputdata = f.read()
            connectionsocket.send("HTTP/1.0 200 OK\r\n\r\n".encode())
            for line in outputdata:
                connectionsocket.send(line.encode())

    except FileNotFoundError:
        print(f"Page {filename[1:]} not found, sending 404 error.")
        with open("404error.html", 'r') as f:
            error_page = f.read()
            connectionsocket.send("HTTP/1.0 404 Not Found\r\n\r\n".encode())
            connectionsocket.send(error_page.encode())

    # This sends the HTTP header and Hello World response into socket
    connectionsocket.close()
serversocket.close()
