//
// Created by elisha on 12/7/20.
//

#pragma once


#include <string>

class stringUtils {
public:
    static void trimStr(std::string& str);

    // Only trims from "left" seeing as it is a c style string there is no real right side
    static void trimCStr(const char **str);

private:
    static void leftTrimStr(std::string& str);

    static void rightTrimStr(std::string& str);

};
