#include <stddef.h>

#define PERIPH_BASE                 (0x40000000UL)
#define AHB1PERIPH_BASE             (PERIPH_BASE + 0x00020000UL)
#define AHB2PERIPH_BASE             (PERIPH_BASE + 0x08000000UL)
#define GPIOA_BASE                  (AHB2PERIPH_BASE + 0x0000UL)
#define RCC_BASE 			        (AHB1PERIPH_BASE + 0x1000UL)

#define RCC_AHB2ENR_R			    (*(volatile unsigned int *)(RCC_BASE + 0x4CUL))
#define RCC_AHB2ENR_GPIOAEN_Pos     (0U)
#define RCC_AHB2ENR_GPIOAEN_Msk     (0x1UL << RCC_AHB2ENR_GPIOAEN_Pos) 
#define RCC_AHB2ENR_GPIOAEN         RCC_AHB2ENR_GPIOAEN_Msk

#define MODE_R_OFFSET		        (0x00UL)
#define GPIOA_MODE_R		        (*(volatile unsigned int *)(GPIOA_BASE + MODE_R_OFFSET)) 
#define GPIO_ODR_R			        (*(volatile unsigned int *)(GPIOA_BASE + 0x14UL))

#define GPIO_ODR_OD5_Pos            (5U)
#define GPIO_ODR_OD5_Msk            (0x1UL << GPIO_ODR_OD5_Pos) 
#define GPIO_ODR_PIN5               GPIO_ODR_OD5_Msk

int main(void) {
	RCC_AHB2ENR_R |= RCC_AHB2ENR_GPIOAEN;
	GPIOA_MODE_R |= (1U<<10);
	GPIOA_MODE_R &= ~(1U<<11);
	while (1) {
		GPIO_ODR_R ^= GPIO_ODR_PIN5;
		for (size_t i = 0; i < 1000000;i++) {}
	}
}
