//
// Created by elisha on 1/24/21.
//

#pragma once

class FDWrapper {
public:
    FDWrapper(const int fd): m_fd(fd) {};

    FDWrapper(): m_fd (-1) {};

    inline bool is_init() {
        return -1 == m_fd;
    }

    virtual ~FDWrapper() = default;

private:

    int m_fd;
};

