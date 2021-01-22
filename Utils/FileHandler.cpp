//
// Created by elisha on 11/16/20.
//

#include <fcntl.h>
#include "FileHandler.hpp"
#include <unistd.h>
#include <algorithm>

FileHandler::FileHandler(const char *file_path, const int flags = O_RDONLY) {
    if (nullptr == file_path) {
        m_fd = INVALID_FD;
    }

    else {
        // For now open according to flags
        m_fd = open(file_path, flags);
    }
}

FileHandler::~FileHandler() {
    if (INVALID_FD != m_fd) {
        // Doesnt check close's return value mainly as i dont see what we can do upn failure (log?)
        close(m_fd);
    }
}

size_t FileHandler::getLine(char* buf, const size_t buflen, size_t amount) const {
    if (INVALID_FD == m_fd) {
        return 0;
    }

    // If user requests more than size of buffer change the amount to buflen
    if (amount > buflen || amount > MAX_LINE_LENGTH) {
        amount = std::min(buflen, static_cast<size_t>(MAX_LINE_LENGTH));
    }

    return read(m_fd, buf, amount);
}

size_t FileHandler::writeLine(const char* buf, const size_t buflen, size_t amount) const {
    if (INVALID_FD == m_fd) {
        return 0;
    }

    // If user requests more than size of buffer change the amount to buflen
    if (amount > buflen || amount > MAX_LINE_LENGTH) {
        amount = std::min(buflen, static_cast<size_t>(MAX_LINE_LENGTH));
    }

     return write(m_fd, buf, amount);
}

// As of now only allow seek from SEEK_SET meaning from offset bytes from the begining of the file - might need to fix later
bool FileHandler::seek(size_t offset) {
    return INVALID_FD == lseek(m_fd, offset, SEEK_SET);
}