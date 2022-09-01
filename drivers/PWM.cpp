#include "PWM.hpp"
#include "../system/rpi4_system.hpp"
#include <unistd.h>

PWM::PWM(uint8_t _pin, double _freq) : pin(_pin), freq(_freq) {
    switch (pin){
        case 12: case 13: case 18: case 19: case 40: case 41: case 45:
            break;
        default:
            sendMessage("GPIO" + std::to_string(pin) + " has no PWM function", MessageLevel::error);
            return;
    }

    switch (pin){
        case 12: case 13: case 40: case 41: case 45:
            rpi4_setGpioFunction(pin, GPIO_Function::ALT0);
            break;
        case 18: case 19:
            rpi4_setGpioFunction(pin, GPIO_Function::ALT5);
            break;
    }

    setFrequency(freq);

};

double PWM::write(double duty){
    uint32_t dat = clock_source * duty / freq;

    switch (pin){
        case 12:
        case 18:
            REG_PWM0->DAT1 = dat;
            REG_PWM0->CTL |= 0b1;
            break;
        case 13:
        case 19:
        case 45:
            REG_PWM0->DAT2 = dat;
            REG_PWM1->CTL |= 0b1 << 8;
            break;
        case 40:
            REG_PWM1->DAT1 = dat;
            REG_PWM1->CTL |= 0b1;
            break;
        case 41:
            REG_PWM1->DAT2 = dat;
            REG_PWM1->CTL |= 0b1 << 8;
            break;
    }
    return freq;
}

double PWM::setFrequency(double _freq){
    freq = _freq;
    uint32_t rng = clock_source / freq;

    rpi4_clock_config(REG_CLK->CM_PWMCTL, REG_CLK->CM_PWMDIV, CLKSRC::OSC, 2.16, 1); // set pwm source clock frequency to 25MHz
    
    switch (pin){
        case 12:
        case 18:
            REG_PWM0->CTL &= ~0b10111111;
            REG_PWM0->RNG1 = rng;
            REG_PWM0->DAT1 = 0;
            REG_PWM0->CTL |= 0b10000001;
            break;
        case 13:
        case 19:
        case 45:
            REG_PWM0->CTL &= ~(0b10111111 << 8);
            REG_PWM0->RNG2 = rng;
            REG_PWM0->DAT2 = 0;
            REG_PWM0->CTL |= 0b10000001 << 8;
            break;
        case 40:
            REG_PWM1->CTL &= ~0b10111111;
            REG_PWM1->RNG1 = rng;
            REG_PWM1->DAT1 = 0;
            REG_PWM1->CTL |= 0b10000001;
            break;
        case 41:
            REG_PWM1->CTL &= ~(0b10111111 << 8);
            REG_PWM1->RNG2 = rng;
            REG_PWM1->DAT2 = 0;
            REG_PWM1->CTL |= 0b10000001 << 8;
            break;
    }
    return freq;
}