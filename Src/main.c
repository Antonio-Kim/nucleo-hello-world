#include <stddef.h>

//#include "main.h"

#define PERIPHBASE			(0x40000000UL)
#define AHB1_BASE			(0x40020000UL)
#define AHB2_BASE			(0x40010000UL)
#define GPIOA_BASE			(0x48000000UL)
#define RCC_BASE			(0x40021000UL)

#define RCC_AHB2ENR			(*(volatile unsigned int *) (RCC_BASE + 0x4C))
#define GPIOA_MODER			(*(volatile unsigned int *) (GPIOA_BASE + 0x00))
#define GPIOA_ODR			(*(volatile unsigned int *) (GPIOA_BASE + 0x14))


#define GPIOAEN				(1U<<0)
#define PIN_5				(1U<<5)
#define LED_PIN				PIN_5

int main(void) {
    	RCC_AHB2ENR |= GPIOAEN;
	GPIOA_MODER |= (1U<<10);
	GPIOA_MODER &= ~(1U<<11);
	while (1) {
		GPIOA_ODR ^= LED_PIN;
		for (size_t i = 0; i < 1000000;i++) {}
	}

//	 Use the following below if you're using main.h
//
//	 RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
//	 GPIOA->MODER |= (1U<<10);
//	 GPIOA->MODER &= ~(1U<<11);
//	 while (1) {
//		GPIOA->ODR ^= GPIO_ODR_PIN5;
//		for (size_t i = 0; i < 1000000;i++) {}
//	 }
}
