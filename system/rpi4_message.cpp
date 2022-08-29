#include "rpi4_message.hpp"
#include "rpi4_config.hpp"

#include <iostream>

void sendMessage(std::string message, MessageLevel lebel){
#ifdef RPI4_DEBUG
    if(lebel == MessageLevel::info)
        std::cout << "Info : " << message << std::endl;
    else if(lebel == MessageLevel::warning)
        std::cout << "\033[33mWarning : " << message << "\033[m"  << std::endl;
    else if(lebel == MessageLevel::error)
        std::cout << "\033[1;31mError : " << message << "\033[m" << std::endl;
#endif
}

void sendMmessage(std::string message){
    sendMessage(message, MessageLevel::info);
}