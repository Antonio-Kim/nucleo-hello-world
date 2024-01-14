#define PERIPH_BASE           (0x40000000UL)
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000UL)
#define AHB2PERIPH_BASE       (PERIPH_BASE + 0x08000000UL)
#define GPIOA_BASE            (AHB2PERIPH_BASE + 0x0000UL)
#define RCC_BASE 			  (AHB1PERIPH_BASE + 0x1000UL)

#define RCC_AHB2ENR_R					 	 (*(volatile unsigned int *)(RCC_BASE + 0x4CUL))
#define RCC_AHB2ENR_GPIOAEN_Pos              (0U)
#define RCC_AHB2ENR_GPIOAEN_Msk              (0x1UL << RCC_AHB2ENR_GPIOAEN_Pos) /*!< 0x00000001 */
#define RCC_AHB2ENR_GPIOAEN                  RCC_AHB2ENR_GPIOAEN_Msk

#define MODE_R_OFFSET		(0x00UL)
#define GPIOA_MODE_R		(*(volatile unsigned int *)(GPIOA_BASE + MODE_R_OFFSET)) // or (0xABFFFFFF)

#define GPIO_ODR_R			(*(volatile unsigned int *)(GPIOA_BASE + 0x14UL))

#define GPIO_ODR_OD5_Pos               (5U)
#define GPIO_ODR_OD5_Msk               (0x1UL << GPIO_ODR_OD5_Pos)             /*!< 0x00000020 */
#define GPIO_ODR_PIN5                   GPIO_ODR_OD5_Msk

