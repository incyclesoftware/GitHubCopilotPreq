#include <boost/asio.hpp>
#include <iostream>
#include <string>

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

int main() {
    try {
        io_context io;
        tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 25252));
        std::cout << "Echo server running on port 25252...\n";

        while (true) {
            tcp::socket socket(io);
            acceptor.accept(socket);
            std::thread(session, std::move(socket)).detach();
        }
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
