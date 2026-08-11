#include <iostream>
#include <cstring>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main() {
    // Initialize Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cout << "WSAStartup failed." << endl;
        return 1;
    }

    // 1. socket()
    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (serverSocket == INVALID_SOCKET) {
        cout << "Socket creation failed." << endl;
        WSACleanup();
        return 1;
    }

    // Server address
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(8080);

    // 2. bind()
    if (bind(serverSocket,
             (sockaddr*)&serverAddress,
             sizeof(serverAddress)) == SOCKET_ERROR) {

        cout << "Bind failed." << endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    // 3. listen()
    if (listen(serverSocket, 5) == SOCKET_ERROR) {
        cout << "Listen failed." << endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    cout << "Server started successfully." << endl;
    cout << "Waiting for a client..." << endl;

    // 4. accept()
    SOCKET clientSocket = accept(serverSocket, NULL, NULL);

    if (clientSocket == INVALID_SOCKET) {
        cout << "Accept failed." << endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    cout << "Client connected." << endl;

    // 5. recv()
    char buffer[1024] = {0};

    int bytesReceived = recv(
        clientSocket,
        buffer,
        sizeof(buffer) - 1,
        0
    );

    if (bytesReceived > 0) {
        buffer[bytesReceived] = '\0';

        cout << "Message received: "
             << buffer << endl;
    }

    // 6. send()
    const char* response = "Hello Client! Message received successfully.";

    send(
        clientSocket,
        response,
        strlen(response),
        0
    );

    cout << "Response sent to client." << endl;

    // 7. close()
    closesocket(clientSocket);
    closesocket(serverSocket);

    WSACleanup();

    cout << "Server connection closed." << endl;

    return 0;
}