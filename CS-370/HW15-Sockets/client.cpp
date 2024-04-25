//
// Created by Rako | 25/04/24
//
#include <iostream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <port>" << std::endl;
        return 1;
    }

    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    int port = std::stoi(argv[1]);

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cerr << "Socket creation error" << std::endl;
        return 1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        std::cerr << "Invalid address/ Address not supported" << std::endl;
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cerr << "Connection Failed" << std::endl;
        return 1;
    }

    std::cout << "Connected to the server on port " << port << "." << std::endl;
    std::string message;

    while (true) {
        std::cout << "Enter message: ";
        std::getline(std::cin, message);

        if (message.empty()) continue;

        send(sock, message.c_str(), message.size(), 0);
        if (message == "quit") {
            break;
        }

        char buffer[1024] = {0};
        valread = read(sock, buffer, 1023);
        buffer[valread] = '\0';

        std::cout << "Server response: " << buffer << std::endl;
    }

    close(sock);
    return 0;
}
