#ifndef RPI4_MESSAGE_HPP_
#define RPI4_MESSAGE_HPP_

#include <string>

enum class MessageLevel{
    error,
    warning,
    info
};

void sendMessage(std::string message, MessageLevel lebel);
void sendMessage(std::string message);

#endif