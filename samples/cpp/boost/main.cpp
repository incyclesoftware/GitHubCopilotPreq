#include "Server.h"
#include <iostream>
#include <string>
#include <thread>
#include <atomic>

int main() {
    io_context io;
    std::atomic<bool> running{true};
    Server server(io, running, 25252);

    std::thread io_thread([&io]() { io.run(); });

    std::string command;
    std::cout << "Server started.\n";
    std::cout << "Type 'quit' to shut down server.\n";
    while (running) {
        std::getline(std::cin, command);
        command.erase(0, command.find_first_not_of(" \t\n\r"));
        command.erase(command.find_last_not_of(" \t\n\r") + 1);

        if (command == "quit") {
            std::cout << "Shutting down server...\n";
            running = false;
            io.stop();
        } else {
            std::cout << "unknown command\n";
        }
    }

    io_thread.join();
    std::cout << "Server shut down.\n";

    return 0;
}
