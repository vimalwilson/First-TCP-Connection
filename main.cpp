
#include <iostream>
#include <cstring>

// Linux socket headers
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    // Target IP and port
    const char* target_ip = "127.0.0.1";
    int port = 80;

    // Create a TCP socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        std::cerr << "Failed to create socket\n";
        return 1;
    }

    // Prepare the target address
    sockaddr_in target;
    std::memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_port = htons(port);

    if (inet_pton(AF_INET, target_ip, &target.sin_addr) <= 0) {
        std::cerr << "Invalid IP address\n";
        close(sock);
        return 1;
    }

    // Try to connect
    std::cout << "Trying to connect to "
              << target_ip << ":" << port << "...\n";

    int result = connect(
        sock,
        (sockaddr*)&target,
        sizeof(target)
    );

    // Check result
    if (result == 0) {
        std::cout << "Port " << port << " is OPEN\n";
    } else {
        std::cout << "Port " << port << " is CLOSED or BLOCKED\n";
    }

    // Close socket
    close(sock);
    return 0;
}

