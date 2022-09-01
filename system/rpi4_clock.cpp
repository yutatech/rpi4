#include "rpi4_clock.hpp"
#include "rpi4_registers.hpp"
#include "stdint.h"

#define PASSWD 0x5a

void rpi4_set_cm_ctl(uint32_t &reg, uint32_t data){
    reg = (PASSWD << 24) | data;
}
    
void rpi4_set_cm_div(uint32_t &reg, uint32_t divi, uint32_t divf){
    reg = (PASSWD << 24) | (divi << 12) | divf;
}

void rpi4_clock_config(uint32_t &reg_ctl, uint32_t &reg_div, CLKSRC src, double div, uint8_t mash){
  rpi4_set_cm_ctl(reg_ctl, reg_ctl & 0xffef); // disable clock

  uint16_t divi = (uint16_t)div & 0b111111111111;
  uint16_t divf = (uint16_t)((div - (uint16_t)div) * 4096) & 0b111111111111;

  while (reg_ctl & 0x0080); // wait for the end of clock


  rpi4_set_cm_ctl(reg_ctl, (uint32_t)src | ((mash & 3) << 9));  // set clock source and mash
  rpi4_set_cm_div(reg_div, divi, divf);
  rpi4_set_cm_ctl(reg_ctl, reg_ctl | (1<<4)); // enable clock
}