#include "Server.h"

Server::Server(io_context& io, std::atomic<bool>& running, short port)
    : acceptor_(io, tcp::endpoint(tcp::v4(), port)), running_(running) {
    do_accept();
}

void Server::do_accept() {
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
