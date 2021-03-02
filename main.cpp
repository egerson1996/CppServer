#include <iostream>
#include "Configurations/ConfigurationLoader.hpp"
#include "Utils/FileHandler.hpp"
#include "Utils/stringUtils.hpp"
#include "Utils/SocketWrapper.hpp"

int main() {
    ConfigurationLoader serverLoader;
    std::string filename = "hello_world";
    char arr [] = "lets try this non const char *";
    SocketWrapper socket_1(8082);
    if (! socket_1.init()) {
        std::cout << "Cool bro" << "\n";
    }


    //std::cout << "Hello, World! " << serverLoader.loadConfiguration()<< '\n';
    std::string a("    Hello     Elisha          ");
    stringUtils::trimStr(a);
    std::cout << a << "\n";
    return 0;
}
