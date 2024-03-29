#ifndef RPI4_SYSTEM_HPP_
#define RPI4_SYSTEM_HPP_

// Header files commonly used in the rpi4 library 
#include "rpi4_registers.hpp"
#include "rpi4_clock.hpp"
#include "rpi4_message.hpp"
#include "iostream"

uint8_t RPI4_Init(void);
uint8_t RPI4_SetGpioFunction(uint8_t pin, GPIO_Function alt);

extern GPIO_Typedef* REG_GPIO;
extern PWM_Typedef*  REG_PWM0;
extern PWM_Typedef*  REG_PWM1;
extern CLK_Typedef*  REG_CLK;

#endif