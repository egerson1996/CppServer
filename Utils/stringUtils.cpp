//
// Created by elisha on 12/7/20.
//

#include "stringUtils.hpp"
#include <algorithm>

void stringUtils::trimStr(std::string &str)  {
    leftTrimStr(str);
    rightTrimStr(str);
}

void stringUtils::leftTrimStr(std::string &str) {
    str.erase(str.cbegin(), std::find_if_not(str.cbegin(), str.cend(),
                [](const char character) {
                    return isspace(character);
                }));
}

void stringUtils::rightTrimStr(std::string &str) {
    str.erase(std::find_if_not(str.rbegin(), str.rend(),
                                             [](const char character) {
                                                 return isspace(character);
                                             }).base(), str.cend());
}

void stringUtils::trimCStr(const char **str) {
    const char* ptr_to_str = *str;
    while (isspace(*ptr_to_str)) {
        ptr_to_str++;
    }

    *str = ptr_to_str;
}
