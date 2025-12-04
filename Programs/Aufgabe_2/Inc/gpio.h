#ifndef GPIO_H
#define GPIO_H
#include "stm32f4xx_hal.h"
#include "stdbool.h"

extern int setGpioPin(GPIO_TypeDef* gpio,int pin, bool on);

extern int readGpioPin(GPIO_TypeDef* gpio,int pin, int* value);

extern int setGpioReg(GPIO_TypeDef* gpio,unsigned int bitmask, bool on);
#endif
//eof