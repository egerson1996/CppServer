//
// Created by elisha on 1/22/21.
//

#pragma once

#include <sys/types.h>
#include <sys/socket.h>

// For now SocketWRapper will support TCP type sockets - need to expand to more modular type (UDP and UDS sockets) later
//  either using an interface and polmorphysim or templates
class SocketWrapper {
public:
    SocketWrapper(const uint16_t port): m_port(port) {};

    virtual ~SocketWrapper() = default;

    bool init();

private:
    static constexpr int MAX_BACKLOG = 10;

    int m_socket;

    const uint16_t m_port;

    bool m_init;
};

