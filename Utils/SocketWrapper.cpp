//
// Created by elisha on 1/22/21.
//

#include <netinet/in.h>
#include <cstring>
#include <iostream>
#include "SocketWrapper.hpp"

bool SocketWrapper::init() {
    // Create TCP socket
    m_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == m_socket) {
        return false;
    }

    int opt = 1;
    if (-1 == setsockopt(m_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        return false;
    }

    sockaddr_in s_addr;
    memset(&s_addr, 0, sizeof(sockaddr_in));

    s_addr.sin_family = AF_INET;
    s_addr.sin_addr.s_addr = INADDR_ANY;
    s_addr.sin_port = htons(m_port);

    if (-1 == bind(m_socket, reinterpret_cast<sockaddr*>(&s_addr), sizeof(s_addr))) {
        std::cout << strerror(errno) << "\n";
        return false;
    }

    // Server is now listening for new connections - listen is non waiting function
    if (-1 == listen(m_socket, MAX_BACKLOG)) {
        return false;
    }

    int connected_fd;
    sockaddr connecting_addr;
    socklen_t addr_len;

    // Right now accept is blocking - can either make it non blocking or open a new thread every time to handle a
    //  new connection, or use an epoll to watch the fd and alert us whenever the fd is ready
    //  For now we will go with the epoll implementation (maybe after we will also try thread per connection - but
    //   would exhaust quickly with a thread pool and a lot of connections)
    if (-1 == (connected_fd = accept(m_socket, &connecting_addr, &addr_len))) {
        return false;
    }

    std::cout << connecting_addr.sa_data << connecting_addr.sa_family << "\n";

    return true;
}