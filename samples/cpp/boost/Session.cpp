#include "Session.h"

Session::Session(tcp::socket socket)
    : socket_(std::move(socket)) {}

void Session::start() {
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

void Session::do_read() {
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

void Session::do_write(std::size_t length) {
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
