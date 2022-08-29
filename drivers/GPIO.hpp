#ifndef GPIO_HPP_
#define GPIO_HPP_

#include <stdint.h>

enum class PinMode{
    input,
    input_pullup,
    input_pulldown,
    output
};

class GPIO{
private:
    uint8_t pin;
public:
    GPIO(uint8_t _pin, PinMode mode);
    bool read();
    bool write(bool output);
    void pinMode(PinMode mode);
    bool operator = (bool output){
        return write(output);
    }
};

#endif