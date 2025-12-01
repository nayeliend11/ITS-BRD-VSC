#ifndef GPIO_H
#define GPIO_H
#include "stm32f4xx_hal.h"

extern int setGpioPin(GPIO_TypeDef* gpio, int value);

extern int readGpioPin(GPIO_TypeDef* gpio, int* value);

#endif
//eof