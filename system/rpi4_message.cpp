#include "rpi4_message.hpp"
#include "rpi4_config.hpp"

#include <iostream>

void RPI4_Message(std::string message, MessageLevel lebel){
#ifdef RPI4_DEBUG
    if (lebel == MessageLevel::info)
        std::cout << "Info : " << message << std::endl;
    else if (lebel == MessageLevel::warning)
        std::cout << "\033[33mWarning : " << message << "\033[m"  << std::endl;
    else if (lebel == MessageLevel::error) {
        std::cout << "\033[1;31mError : " << message << "\033[m" << std::endl;
        exit(-1);
    }
#endif
}

void RPI4_Message(std::string message){
    RPI4_Message(message, MessageLevel::info);
}