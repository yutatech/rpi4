#ifndef RASPBERRYPI4_REGISTERS_HPP_
#define RASPBERRYPI4_REGISTERS_HPP_

#include <stdint.h>


/* GPIO registers */

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

/* GPIO registers end */


/* PWM registers */

#define PWM0_BASE 0xFE20C000
#define PWM1_BASE 0xFE20C800
#define PWM_SIZE  0x00000028
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

/* PWM registers end */


/* CLOCK registers */

#define CLK_BASE 0xFE101000
#define CLK_SIZE 0x000001C8
typedef struct
{
    uint32_t RESERVED_1[2]; // 0x000 ~ 0x007
    uint32_t CM_VPUCTL;		// 0x008
    uint32_t CM_VPUDIV;		// 0x00c
    uint32_t CM_SYSCTL;		// 0x010
    uint32_t CM_SYSDIV;		// 0x014
    uint32_t CM_PERIACTL;	// 0x018
    uint32_t CM_PERIADIV;	// 0x01c
    uint32_t CM_PERIICTL;	// 0x020
    uint32_t CM_PERIIDIV;	// 0x024
    uint32_t CM_H264CTL;	// 0x028
    uint32_t CM_H264DIV;	// 0x02c
    uint32_t CM_ISPCTL;		// 0x030
    uint32_t CM_ISPDIV;		// 0x034
    uint32_t CM_V3DCTL;		// 0x038
    uint32_t CM_V3DDIV;		// 0x03c
    uint32_t CM_CAM0CTL;	// 0x040
    uint32_t CM_CAM0DIV;	// 0x044
    uint32_t CM_CAM1CTL;	// 0x048
    uint32_t CM_CAM1DIV;	// 0x04c
    uint32_t CM_CCP2CTL;	// 0x050
    uint32_t CM_CCP2DIV;	// 0x054
    uint32_t CM_DSI0ECTL;	// 0x058
    uint32_t CM_DSI0EDIV;	// 0x05c
    uint32_t CM_DSI0PCTL;	// 0x060
    uint32_t CM_DSI0PDIV;	// 0x064
    uint32_t CM_DPICTL;		// 0x068
    uint32_t CM_DPIDIV;		// 0x06c
    uint32_t CM_GP0CTL;		// 0x070
    uint32_t CM_GP0DIV;		// 0x074
    uint32_t CM_GP1CTL;		// 0x078
    uint32_t CM_GP1DIV;		// 0x07c
    uint32_t CM_GP2CTL;		// 0x080
    uint32_t CM_GP2DIV;		// 0x084
    uint32_t CM_HSMCTL;		// 0x088
    uint32_t CM_HSMDIV;		// 0x08c
    uint32_t CM_OTPCTL;		// 0x090
    uint32_t CM_OTPDIV;		// 0x094
    uint32_t CM_PCMCTL;		// 0x098
    uint32_t CM_PCMDIV;		// 0x09c
    uint32_t CM_PWMCTL;		// 0x0a0
    uint32_t CM_PWMDIV;		// 0x0a4
    uint32_t CM_SLIMCTL;	// 0x0a8
    uint32_t CM_SLIMDIV;	// 0x0ac
    uint32_t CM_SMICTL;		// 0x0b0
    uint32_t CM_SMIDIV;		// 0x0b4
    uint32_t RESERVED2[2];  // 0x0b8 ~ 0x0bf
    uint32_t CM_TCNTCTL;	// 0x0c0
    uint32_t CM_TCNTCNT;	// 0x0c4
    uint32_t CM_TECCTL;		// 0x0c8
    uint32_t CM_TECDIV;		// 0x0cc
    uint32_t CM_TD0CTL;		// 0x0d0
    uint32_t CM_TD0DIV;		// 0x0d4
    uint32_t CM_TD1CTL;		// 0x0d8
    uint32_t CM_TD1DIV;		// 0x0dc
    uint32_t CM_TSENSCTL;	// 0x0e0
    uint32_t CM_TSENSDIV;	// 0x0e4
    uint32_t CM_TIMERCTL;	// 0x0e8
    uint32_t CM_TIMERDIV;	// 0x0ec
    uint32_t CM_UARTCTL;	// 0x0f0
    uint32_t CM_UARTDIV;	// 0x0f4
    uint32_t CM_VECCTL;		// 0x0f8
    uint32_t CM_VECDIV;		// 0x0fc
    uint32_t RESERVED3[36]; // 0x100 ~ 0x18f
    uint32_t CM_PULSECTL;	// 0x190
    uint32_t CM_PULSEDIV;	// 0x194
    uint32_t RESERVE4[4];   // 0x198 ~ 0x1a7
    uint32_t CM_SDCCTL;		// 0x1a8
    uint32_t CM_SDCDIV;		// 0x1ac
    uint32_t CM_ARMCTL;		// 0x1b0
    uint32_t RESERVED5;     // 0x1b4
    uint32_t CM_AVEOCTL;	// 0x1b8
    uint32_t CM_AVEODIV;	// 0x1bc
    uint32_t CM_EMMCCTL;	// 0x1c0
    uint32_t CM_EMMCDIV;	// 0x1c4
} CLK_Typedef;

/* CLOCK registers end */


#endif