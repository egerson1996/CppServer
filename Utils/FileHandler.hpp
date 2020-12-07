//
// Created by elisha on 11/16/20.
//

#pragma once

#include <unistd.h>
#include <cstdint>

// Should these declarations be inside class or not?
static constexpr int INVALID_SOCKET         = -1;
static constexpr uint32_t MAX_LINE_LENGTH   = 255;

class FileHandler {

public:
    FileHandler(const char* file_path);

    ~FileHandler();

    bool is_valid() const noexcept {
        return INVALID_SOCKET != m_socket;
    }

    size_t getLine(char* buf, const size_t buflen, size_t amount) const;

    size_t writeLine(const char* buf, const size_t buflen, size_t amount) const;

    bool seek(size_t offset);

private:
    int m_socket;
};

