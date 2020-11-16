//
// Created by elisha on 11/16/20.
//

#pragma once

#include <unistd.h>

static constexpr int INVALID_SOCKET = -1;

class FileHandler {

public:
    FileHandler(const char* file_path);

    ~FileHandler();

    bool is_valid() const {
        return INVALID_SOCKET != m_socket;
    }

private:
    int m_socket;
};

