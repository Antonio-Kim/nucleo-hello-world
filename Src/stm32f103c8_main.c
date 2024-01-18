#include <stdint.h>

#define PERIPHBASE			(0x40000000UL)
#define APB2_BASE			(PERIPHBASE + 0x10000UL)
#define GPIOA_BASE			(0x040010800UL)
#define GPIOB_BASE			(APB2_BASE + 0xC00UL)
#define GPIOC_BASE			(APB2_BASE + 0x1000UL)
#define RCC_BASE			(0x40021000UL)

#define RCC_APB2ENR			(*(volatile unsigned int *)(RCC_BASE + 0x18))
#define GPIOA_CRL			(*(volatile unsigned int *)(GPIOA_BASE + 0x00))
#define GPIOA_CRH			(*(volatile unsigned int *)(GPIOA_BASE + 0x04))
#define GPIOA_ODR			(*(volatile unsigned int *)(GPIOA_BASE + 0x0C))

#define GPIOB_CRL			(*(volatile unsigned int *)(GPIOB_BASE + 0x00))
#define GPIOB_CRH			(*(volatile unsigned int *)(GPIOB_BASE + 0x04))
#define GPIOB_ODR			(*(volatile unsigned int *)(GPIOB_BASE + 0x0C))

#define GPIOC_CRL			(*(volatile unsigned int *)(GPIOC_BASE + 0x00))
#define GPIOC_CRH			(*(volatile unsigned int *)(GPIOC_BASE + 0x04))
#define GPIOC_ODR			(*(volatile unsigned int *)(GPIOC_BASE + 0x0C))

#define GPIOAEN				(1U<<2)
#define GPIOBEN				(1U<<3)
#define GPIOCEN				(1U<<4)


int main(void) {
	RCC_APB2ENR |= GPIOBEN;
	GPIOB_CRL |= (3<<0);
	GPIOB_CRL &= ~(3<<2);
	while(1) {
		GPIOB_ODR |= (1<<0);
	}
}
