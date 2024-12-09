#include <iostream>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define DIM_BUF 1024

int main(int argc, char *argv[]) {
    std::cout << "Start\n";

    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        std::cerr << "Cannot create Socket.\n";
        return -1;
    }

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(PORT);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    if (inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr) <= 0) {
        std::cerr << "Invalid address: IP address not supported!\n";
        return -1;
    }

    auto res = bind(serverSocket, (sockaddr *)&serverAddress, sizeof(serverAddress));
    auto l = listen(serverSocket, 5);

    int clientSocket = accept(serverSocket, nullptr, nullptr);

    struct Data {
        int id = 0;
    };

    char buffer[DIM_BUF] = {};
    if (recv(clientSocket, buffer, sizeof(buffer), 0) == -1) {
        std::cerr << "Cannot write to the buffer.\n";
        return -1;
    }

    std::cout << "Message from client: " << ((Data*)buffer)->id << "\n";
    // std::cout << "Message from client: " << buffer << "\n";

    close(serverSocket);

    std::cout << "End\n";
    return 0;
}
