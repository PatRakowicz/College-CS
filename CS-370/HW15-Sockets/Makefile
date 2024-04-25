all: server client

server: server.cpp
	g++ -std=c++17 -pthread server.cpp -o server

client: client.cpp
	g++ -std=c++17 client.cpp -o client

clean:
	rm -f server client
