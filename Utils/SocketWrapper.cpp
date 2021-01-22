//
// Created by elisha on 1/22/21.
//

#include <netinet/in.h>
#include <cstring>
#include "SocketWrapper.hpp"

bool SocketWrapper::init(const uint16_t port) {
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
    s_addr.sin_port = htons(port);

    if (-1 == bind(m_socket, reinterpret_cast<sockaddr*>(&s_addr), sizeof(s_addr))) {
        return false;
    }

    // Server is now listening for new connections - listen is non waiting function
    if (-1 == listen(m_socket, MAX_BACKLOG)) {
        return false;
    }

    return true;
}