//
// Created by elisha on 11/16/20.
//

#pragma once

#include <unordered_map>
#include "Configurations/ConfigurationUtils.hpp"

class ServerManager {
public:
    ServerManager() : m_init(false) {}

    ~ServerManager(){}

    bool init(const char* config_path);
private:
    std::unordered_map<ConfigurationFields, uint32_t> configuration;

    bool m_init;
};
