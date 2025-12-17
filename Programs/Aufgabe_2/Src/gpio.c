#include "gpio.h"
#include "errors.h"
#include "stm32f4xx_hal_gpio.h"
#include "stdbool.h"

#define MAX_PIN 7
#define MIN_PIN 0


int setGpioPin(GPIO_TypeDef* gpio, int pin, bool on){
    if (pin < MIN_PIN || pin > MAX_PIN) {
        return PIN_OUT_OF_RANGE;
    }
    int offset = (on)? 0 : 16;

    gpio->BSRR = (0x01 << (pin + offset));
    return EOK;
}

int setGpioReg(GPIO_TypeDef* gpio, unsigned int bitmask, bool on){
    char bit_mask = bitmask;

    int offset = (on)? 0:16;

    gpio->BSRR = (bitmask << offset);
}

int readGpioPin(GPIO_TypeDef* gpio, int pin, int *value){
    if (pin < MIN_PIN || pin > MAX_PIN) {
        return PIN_OUT_OF_RANGE;
    }

    *value = (0x01 << pin) != (gpio->IDR & (0x01 << pin));
    return EOK;
}