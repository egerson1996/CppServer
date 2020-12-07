//
// Created by elisha on 10/21/20.
//

#pragma once

#include <stdint.h>

enum class ConfigType : uint8_t {
    ServerConfig,
    HTTPConfig
};

enum class ConfigurationFields : uint8_t {
    Port,
    Running_Directory,
    Max_Clients,
    Supported_Methods,
    Threads
};
