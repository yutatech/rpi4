#include "rpi4_clock.hpp"
#include "rpi4_registers.hpp"
#include "stdint.h"

#define PASSWD 0x5a

void RPI4_SetCmCtl(uint32_t &reg, uint32_t data){
    reg = (PASSWD << 24) | data;
}
    
void RPI4_SetCmDiv(uint32_t &reg, uint32_t divi, uint32_t divf){
    reg = (PASSWD << 24) | (divi << 12) | divf;
}

void RPI4_ClockConfig(uint32_t &reg_ctl, uint32_t &reg_div, CLKSRC src, double div, uint8_t mash){
  RPI4_SetCmCtl(reg_ctl, reg_ctl & 0xffef); // disable clock

  uint16_t divi = (uint16_t)div & 0b111111111111;
  uint16_t divf = (uint16_t)((div - (uint16_t)div) * 4096) & 0b111111111111;

  while (reg_ctl & 0x0080); // wait for the end of clock


  RPI4_SetCmCtl(reg_ctl, (uint32_t)src | ((mash & 3) << 9));  // set clock source and mash
  RPI4_SetCmDiv(reg_div, divi, divf);
  RPI4_SetCmCtl(reg_ctl, reg_ctl | (1<<4)); // enable clock
}