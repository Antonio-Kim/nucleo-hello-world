// LED PORT may be PA5 or PB13
// Peripherals starts at 0x4000_0000
// 		- APB1 bus up to 0x4000_9800
// 		- APB2 bus 0x4001_0000 to 0x4001_6400
//		- AHB1 bus 0x4002_0000 to 0x4002_4400
//		- AHB2 bus 0x4800_0000 to 0x5006_0C00
//
// PA5 - AHB2 0x4800 0000 to 0x4800 03FF
// PB13 - AHB2 0x4800 0400 to 0x4800 07FF
//
// RCC is also needed (RCC - Reset and Control Clock)
// 		- AHB1 Bus 0x4002_1000 - 0x400213FF
// RCC requires to enable clocks for the buses
// NB: L476 has different registers for RCC
//
// GPIO has at least two registers: direction and data
// direction is used to set the pin as input or output
// data register is used to store the data
//
// Must enable both the mode register and the output data
// registers, which are called MODER and ODR registers,
// respectively

#define PERIPH_BASE 		(0x40000000UL)
#define AHB1PERIPH_OFFSET	(0x00020000UL)
#define AHB2PERIPH_OFFSET	(0x08000000UL)
#define AHB1PERIPH_BASE		(PERIPH_BASE + AHB1PERIPH_OFFSET)
#define AHB2PERIPH_BASE		(PERIPH_BASE + AHB2PERIPH_OFFSET)

#define GPIOA_OFFSET		(0x00000000UL)
#define GPIOB_OFFSET		(0x00000400UL)
#define GPIOA_BASE			(AHB2PERIPH_BASE + GPIOA_OFFSET)
#define GPIOB_BASE			(AHB2PERIPH_BASE + GPIOB_OFFSET)
#define RCC_OFFSET			(0x00021000UL)
#define RCC_BASE			(AHB1PERIPH_BASE + RCC_OFFSET)

#define AHB2EN_R_OFFSET		(0x4CUL)
#define RCC_AHB2EN_R		(*(volatile unsigned int *)(RCC_BASE + AHB1EN_R_OFFSET))

#define GPIOAEN				(1U<<0)

#define MODE_R_OFFSET		(0x00UL)
#define GPIOA_MODE_R		(*(volatile unsigned int *)(GPIOA_BASE + MODE_R_OFFSET))

#define OD_R_OFFSET			(0x14UL)
#define GPIOA_OD_R			(*(volatile unsigned int *)(GPIOA_BASE + OD_R_OFFSET))
#define PIN5				(1U<<5)
#define LED_PIN				PIN5
