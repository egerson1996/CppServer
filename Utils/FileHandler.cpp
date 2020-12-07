//
// Created by elisha on 11/16/20.
//

#include <fcntl.h>
#include "FileHandler.hpp"
#include <unistd.h>
#include <algorithm>

FileHandler::FileHandler(const char *file_path) {
    if (nullptr == file_path) {
        m_socket = -1;
    }

    else {
        // For now open as read write - shouldnt let write if dont need but for now well leave it
        m_socket = open(file_path, O_RDWR);
    }
}

FileHandler::~FileHandler() {
    if (INVALID_SOCKET != m_socket) {
        // Doesnt check close's return value mainly as i dont see what we can do upn failure (log?)
        close(m_socket);
    }
}

size_t FileHandler::getLine(char* buf, const size_t buflen, size_t amount) const {
    if (INVALID_SOCKET == m_socket) {
        return 0;
    }

    // If user requests more than size of buffer change the amount to buflen
    if (amount > buflen || amount > MAX_LINE_LENGTH) {
        amount = std::min(buflen, static_cast<size_t>(MAX_LINE_LENGTH));
    }

    return read(m_socket, buf, amount);
}

size_t FileHandler::writeLine(const char* buf, const size_t buflen, size_t amount) const {
    if (INVALID_SOCKET == m_socket) {
        return 0;
    }

    // If user requests more than size of buffer change the amount to buflen
    if (amount > buflen || amount > MAX_LINE_LENGTH) {
        amount = std::min(buflen, static_cast<size_t>(MAX_LINE_LENGTH));
    }

     return write(m_socket, buf, amount);
}

// As of now only allow seek from SEEK_SET meaning from offset bytes from the begining of the file - might need to fix later
bool FileHandler::seek(size_t offset) {
    return -1 == lseek(m_socket, offset, SEEK_SET);
}