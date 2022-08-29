#ifndef RASPBERRYPI4_REGISTERS_HPP_
#define RASPBERRYPI4_REGISTERS_HPP_

#include <stdint.h>

#define GPIO_BASE 0xFE200000
#define GPIO_SIZE 0x000000F4
typedef struct
{
    uint32_t GPFSEL0;               // 0x00
    uint32_t GPFSEL1;               // 0x04
    uint32_t GPFSEL2;               // 0x08
    uint32_t GPFSEL3;               // 0x0c
    uint32_t GPFSEL4;               // 0x10
    uint32_t GPFSEL5;               // 0x14
    uint32_t RESERVED_1;            // 0x18
    uint32_t GPSET0;                // 0x1c
    uint32_t GPSET1;                // 0x20
    uint32_t RESERVED_2;            // 0x24
    uint32_t GPCLR0;                // 0x28
    uint32_t GPCLR1;                // 0x2c
    uint32_t RESERVED_3;            // 0x30
    uint32_t GPLEV0;                // 0x34
    uint32_t GPLEV1;                // 0x38
    uint32_t RESERVED_4;            // 0x3c
    uint32_t GPEDS0;                // 0x40
    uint32_t GPEDS1;                // 0x44
    uint32_t RESERVED_5;            // 0x48
    uint32_t GPREN0;                // 0x4c
    uint32_t GPREN1;                // 0x50
    uint32_t RESERVED_6;            // 0x54
    uint32_t GPFEN0;                // 0x58
    uint32_t GPFEN1;                // 0x5c
    uint32_t RESERVED_7;            // 0x60
    uint32_t GPHEN0;                // 0x64
    uint32_t GPHEN1;                // 0x68
    uint32_t RESERVED_8;            // 0x6c
    uint32_t GPLEN0;                // 0x70
    uint32_t GPLEN1;                // 0x74
    uint32_t RESERVED_9;            // 0x78
    uint32_t GPAREN0;               // 0x7c
    uint32_t GPAREN1;               // 0x80
    uint32_t RESERVED_10;           // 0x84
    uint32_t GPAFEN0;               // 0x88
    uint32_t GPAFEN1;               // 0x8c
    uint32_t RESERVED_11[21];       // 0x90~0xe0
    uint32_t PUP_PDN_CNTRL_REG0;    // 0xe4
    uint32_t PUP_PDN_CNTRL_REG1;    // 0xe8
    uint32_t PUP_PDN_CNTRL_REG2;    // 0xec
    uint32_t PUP_PDN_CNTRL_REG3;    // 0xf0
} GPIO_Typedef;

enum class GPIO_Function : uint8_t
{
    INPUT =  0b000,
    OUTPUT = 0b001,
    ALT0   = 0b100,
    ALT1   = 0b101,
    ALT2   = 0b110,
    ALT3   = 0b111,
    ALT4   = 0b011,
    ALT5   = 0b010,
};


#define PWM0_BASE 0xFE20C000
#define PWM1_BASE 0xFE20C800
#define PWM_SIZE 0x00000028
typedef struct
{
    uint32_t CTL;           // 0x00
    uint32_t STA;           // 0x04
    uint32_t DMAC;          // 0x08
    uint32_t RESERVED_1;    // 0x0c
    uint32_t RNG1;          // 0x10
    uint32_t DAT1;          // 0x14
    uint32_t FIF1;          // 0x18
    uint32_t RESERVED_2;    // 0x1c
    uint32_t RNG2;          // 0x20
    uint32_t DAT2;          // 0x24
} PWM_Typedef;

#endif