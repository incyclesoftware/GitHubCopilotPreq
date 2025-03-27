#pragma once

#include <boost/asio.hpp>
#include <atomic>
#include <memory>
#include "Session.h"

using namespace boost::asio;
using ip::tcp;

class Server {
public:
    Server(io_context& io, std::atomic<bool>& running, short port);

private:
    void do_accept();

    tcp::acceptor acceptor_;
    std::atomic<bool>& running_;
};
