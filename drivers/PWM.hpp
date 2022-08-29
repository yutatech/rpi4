#ifndef PWM_HPP_
#define PWM_HPP_

#include <stdint.h>

class PWM{
private:
    uint8_t pin;
    double freq;
    const int clock_source = 100000000;
public:
    PWM(uint8_t _pin, double _freq);
    double write(double duty);
    double setFrequency(double _freq);
    double operator = (double duty){
        return write(duty);
    }
};

#endif