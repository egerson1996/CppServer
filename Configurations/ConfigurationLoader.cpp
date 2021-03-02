//
// Created by elisha on 10/20/20.
//

#include "ConfigurationLoader.hpp"
#include "../Utils/FileHandler.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fcntl.h>

bool ConfigurationLoader::loadConfiguration(const std::string& file_path) {

   FileHandler config_file(file_path.c_str(), O_RDONLY);

   if (! config_file.is_valid()) {
       return false;
   }

   char buf[MAX_LINE_LENGTH];

   while (0 != config_file.getLine(buf, MAX_LINE_LENGTH, MAX_LINE_LENGTH)) {
        //const char* ptr_to_delim = std::find(buf, buf + MAX_LINE_LENGTH , DELIMITER);
        printf("Balls");

   }


    return true;
}