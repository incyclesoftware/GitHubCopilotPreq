#pragma once

#include <boost/asio.hpp>
#include <memory>
#include <iostream>

using namespace boost::asio;
using ip::tcp;

class Session : public std::enable_shared_from_this<Session> {
public:
    explicit Session(tcp::socket socket);
    void start();

private:
    void do_read();
    void do_write(std::size_t length);

    tcp::socket socket_;
    char data_[1024];
};
