#ifndef RPI4_SYSTEM_HPP_
#define RPI4_SYSTEM_HPP_

#include "rpi4_registers.hpp"
#include "rpi4_message.hpp"
#include "iostream"

uint8_t rpi4_init(void);
uint8_t rpi4_setGpioFunction(uint8_t pin, GPIO_Function alt);

extern GPIO_Typedef* REG_GPIO;
extern PWM_Typedef*  REG_PWM0;
extern PWM_Typedef*  REG_PWM1;

#endif