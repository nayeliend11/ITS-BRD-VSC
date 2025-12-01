#include "gpio.h"
#include "errors.h"
#include "stm32f4xx_hal_gpio.h"
#include "stdbool.h"

#define MAX_PIN 7
#define MIN_PIN 0

#define PIN_OUT_OF_RANGE -1

int setRegister(GPIO_TypeDef* gpio, int pin, bool value){
    if (pin < MIN_PIN || pin > MAX_PIN) {
        return PIN_OUT_OF_RANGE;
    }
    
    return EOK;
}

int getRegister(GPIO_TypeDef* gpio, int pin, bool *value){
    if (pin < MIN_PIN || pin > MAX_PIN) {
        return PIN_OUT_OF_RANGE;
    }

    *value = (0x01 << pin) != (gpio->IDR & (0x01 << pin));
    return EOK;
}