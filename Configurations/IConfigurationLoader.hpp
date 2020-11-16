//
// Created by elisha on 10/20/20.
//

#pragma once

class IConfigurationLoader {
public:
    virtual ~IConfigurationLoader () = default;
    virtual bool loadConfiguration() = 0;
};
