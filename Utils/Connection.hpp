//
// Created by elisha on 1/23/21.
//

#pragma once


#include <cstdint>

struct endpoint {
    uint16_t m_port;
    // Something to represent ip address
};

class Connection {
public:
    Connection() =default;

    virtual ~Connection() = default;

private:
    int m_socket;

    const endpoint m_other_endpoint;
};

