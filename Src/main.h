#ifndef MAIN_H
#define MAIN_H

#include <stdint.h>

typedef struct {
    volatile uint32_t MODER;
    volatile uint32_t DUMMY[4];
    volatile uint32_t ODR;
} GPIO_TypeDef;

typedef struct {
    volatile uint32_t DUMMY[18];
    volatile uint32_t AHB1ENR;     
    volatile uint32_t AHB2ENR;     
} RCC_TypeDef;

#endif
