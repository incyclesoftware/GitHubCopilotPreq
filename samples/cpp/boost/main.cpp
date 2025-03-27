#include <boost/asio.hpp>
#include <iostream>
#include <string>
#include <atomic>
#include <thread>
#include <memory>

using namespace boost::asio;
using ip::tcp;

class Session : public std::enable_shared_from_this<Session> {
public:
    explicit Session(tcp::socket socket)
        : socket_(std::move(socket)) {}

    void start() {
        this->socket_.async_send(buffer("Welcome to Echo server.\n"),
            [this](boost::system::error_code ec, std::size_t /*length*/) {
                if (!ec) {
                    do_read();
                } else {
                    std::cerr << "Send error: " << ec.message() << "\n";
                }
            });
        do_read();
    }

private:
    void do_read() {
        auto self(shared_from_this());
        socket_.async_read_some(buffer(data_),
            [this, self](boost::system::error_code ec, std::size_t length) {
                if (!ec) {
                    do_write(length);
                } else if (ec != boost::asio::error::eof) {
                    std::cerr << "Read error: " << ec.message() << "\n";
                }
            });
    }

    void do_write(std::size_t length) {
        auto self(shared_from_this());
        async_write(socket_, buffer(data_, length),
            [this, self](boost::system::error_code ec, std::size_t /*length*/) {
                if (!ec) {
                    do_read();
                } else {
                    std::cerr << "Write error: " << ec.message() << "\n";
                }
            });
    }

    tcp::socket socket_;
    char data_[1024];
};

class Server {
public:
    Server(io_context& io, std::atomic<bool>& running, short port)
        : acceptor_(io, tcp::endpoint(tcp::v4(), port)), running_(running) {
        do_accept();
    }

private:
    void do_accept() {
        acceptor_.async_accept(
            [this](boost::system::error_code ec, tcp::socket socket) {
                if (!ec && running_) {
                    std::cout << "Connection accepted.\n";
                    std::make_shared<Session>(std::move(socket))->start();
                } else if (ec && ec != boost::asio::error::operation_aborted) {
                    std::cerr << "Accept error: " << ec.message() << "\n";
                }

                if (running_) {
                    do_accept();
                }
            });
    }

    tcp::acceptor acceptor_;
    std::atomic<bool>& running_;
};

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
