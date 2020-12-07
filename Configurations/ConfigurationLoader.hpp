//
// Created by elisha on 10/20/20.
//

#pragma once

#include <iostream>
#include "IConfigurationLoader.hpp"
#include "ConfigurationUtils.hpp"

class ConfigurationLoader {
    static constexpr char DELIMITER = ':';
public:
    ConfigurationLoader()   = default;
    ~ConfigurationLoader()  = default;

    bool loadConfiguration(const std::string& file_path);
};
