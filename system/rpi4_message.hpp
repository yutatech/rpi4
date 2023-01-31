#ifndef RPI4_MESSAGE_HPP_
#define RPI4_MESSAGE_HPP_

#include <string>

enum class MessageLevel{
    error,
    warning,
    info
};

void RPI4_Message(std::string RPI4_Message, MessageLevel lebel);
void RPI4_Message(std::string RPI4_Message);

#endif