cmake_minimum_required(VERSION 3.17)
project(webServer)

set(CMAKE_CXX_STANDARD 14)

add_executable(webServer main.cpp Configurations/ConfigurationLoader.cpp Configurations/ConfigurationLoader.hpp Configurations/IConfigurationLoader.hpp Configurations/ConfigurationUtils.hpp Utils/FileHandler.cpp Utils/FileHandler.hpp ServerManager.cpp ServerManager.hpp Utils/stringUtils.cpp Utils/stringUtils.hpp Utils/SocketWrapper.cpp Utils/SocketWrapper.hpp)