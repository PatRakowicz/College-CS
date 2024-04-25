//
// Created by Rako | 25/04/24
//
#include <iostream>
#include <string>
#include <thread>
#include <algorithm>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

void handleClient(int clientSocket) {
    while (true) {
        char buffer[1024] = {0};
        int bytes_read = read(clientSocket, buffer, 1023);
        if (bytes_read <= 0) {
            std::cerr << "Failed to read from client or connection closed." << std::endl;
            break;
        }

        buffer[bytes_read] = '\0';
        std::string data(buffer);

        if (data == "quit") {
            std::cout << "Server shutdown command received from client " << clientSocket << ". Stopping server." << std::endl;
            exit(0);
        }

        std::cout << "Message from client #" << clientSocket << " is: " << data << std::endl;

        std::transform(data.begin(), data.end(), data.begin(), ::toupper);
        send(clientSocket, data.c_str(), data.size(), 0);
    }

    close(clientSocket);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <port>" << std::endl;
        return 1;
    }

    int server_fd, new_socket;
    struct sockaddr_in address;
    int port = std::stoi(argv[1]);
    int opt = 1;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        std::cerr << "Socket failed" << std::endl;
        return 1;
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        std::cerr << "setsockopt(SO_REUSEADDR) failed: " << strerror(errno) << std::endl;
        return 1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        std::cerr << "Bind failed: " << strerror(errno) << std::endl;
        return 1;
    }

    if (listen(server_fd, 10) < 0) {
        std::cerr << "Listen failed: " << strerror(errno) << std::endl;
        return 1;
    }

    std::cout << "Server started. Listening on port " << port << std::endl;

    while (true) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            std::cerr << "Accept failed: " << strerror(errno) << std::endl;
            return 1;
        }

        std::thread clientThread([=](){ handleClient(new_socket); });
        clientThread.detach();
    }

    return 0;
}
