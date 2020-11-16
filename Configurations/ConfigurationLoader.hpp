//
// Created by elisha on 10/20/20.
//

#pragma once

#include <iostream>
#include "IConfigurationLoader.hpp"
#include "ConfigurationUtils.hpp"

class ConfigurationLoader: public IConfigurationLoader {
public:
    ConfigurationLoader()   = default;
    virtual ~ConfigurationLoader()  = default;

    virtual bool loadConfiguration() override;
};
