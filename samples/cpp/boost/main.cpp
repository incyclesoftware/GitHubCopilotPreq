#include <boost/asio.hpp>
#include <iostream>
#include <string>
#include <atomic>
#include <thread>

using namespace boost::asio;
using ip::tcp;

void session(tcp::socket sock) {
    try {
        char data[1024];
        while (true) {
            boost::system::error_code error;
            size_t length = sock.read_some(buffer(data), error);
            if (error == boost::asio::error::eof) {
                break;
            } else if (error) {
                throw boost::system::system_error(error);
            }
            write(sock, buffer(data, length));
        }
    } catch (std::exception& e) {
        std::cerr << "Exception in thread: " << e.what() << "\n";
    }
}

void run_server(io_context& io, std::atomic<bool>& running, tcp::acceptor& acceptor) {
    try {
        std::cout << "Echo server running on port 25252...\n";

        while (running) {
            tcp::socket socket(io);
            boost::system::error_code ec;

            // Use async_accept with a timeout to avoid blocking indefinitely
            acceptor.async_accept(socket, [&](const boost::system::error_code& error) {
                if (!error && running) {
                    std::cout << "Connection accepted.\n";
                    std::thread(session, std::move(socket)).detach();
                } else if (error && error != boost::asio::error::operation_aborted) {
                    std::cerr << "Error in accept: " << error.message() << "\n";
                }
            });

            // Run the io_context for a short duration to process async_accept
            io.run_one();
        }
    } catch (std::exception& e) {
        std::cerr << "Exception in server thread: " << e.what() << "\n";
    }
}

int main() {
    io_context io;
    std::atomic<bool> running{true};
    tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 25252));
    std::thread server_thread(run_server, std::ref(io), std::ref(running), std::ref(acceptor));

    std::string command;
    while (running) {
        std::getline(std::cin, command);
        command.erase(0, command.find_first_not_of(" \t\n\r"));
        command.erase(command.find_last_not_of(" \t\n\r") + 1);

        if (command == "quit") {
            std::cout << "Shutting down server...\n";
            running = false;
            acceptor.cancel();
            acceptor.close();
            io.stop();
            try {
                acceptor.cancel();
            } catch (...) {
            }
        } else {
            std::cout << "unknown command\n";
        }
    }

    std::cout << "Server shut down.\nwaiting for server thread to finish...\n";
    server_thread.join();

    return 0;
}
