#include "Session.h"
#include <iomanip>

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
                auto now = std::chrono::system_clock::now();
                auto now_time_t = std::chrono::system_clock::to_time_t(now);
                auto now_tm = *std::localtime(&now_time_t);
                std::ostringstream oss;
                oss << std::put_time(&now_tm, "%H:%M:%S");
                std::string timestamp = oss.str();
                std::string message(data_, length);
                std::string response = "You said@" + timestamp + ":" + message;
                std::memcpy(data_, response.c_str(), response.size());
                length = response.size();
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
