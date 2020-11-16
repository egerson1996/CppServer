//
// Created by elisha on 11/16/20.
//

#include <fcntl.h>
#include "FileHandler.hpp"

FileHandler::FileHandler(const char *file_path) {
    if (nullptr == file_path) {
        m_socket = -1;
    }

    else {
        // For now open as read write - shouldnt let write if dont need bt for now well leave it
        m_socket = open(file_path, O_RDWR);
    }
}

FileHandler::~FileHandler() {
    if (INVALID_SOCKET != m_socket) {
        // Doesnt check close's return value mainly as i dont see what we can do upn failure (log?)
        close(m_socket);
    }
}