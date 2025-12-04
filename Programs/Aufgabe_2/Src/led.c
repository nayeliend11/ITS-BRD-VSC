#include "led.h"
#include "errors.h"
#include "general.h"
#include "gpio.h"
#include "stm32f429xx.h"
#include <stdbool.h>

#define INVALID_NEGATIVE_NUMBER -1


int errorLedOn(){
    int errCode = setGpioPin(LEFT_LEDS,ERROR_LED_PIN,true);
    if(errCode != EOK){
        return errCode;
    }
    return EOK;
}

int errorLedOff(){
        int errCode = setGpioPin(LEFT_LEDS,ERROR_LED_PIN,false);
    if(errCode != EOK){
        return errCode;
    }
    return EOK;
}

int setBinaryLeds(int number){
    if(number < 0){
        return INVALID_NEGATIVE_NUMBER;
    }
    number = number % 256;

    setGpioReg(GPIOD, 0xff, false);
    setGpioReg(GPIOD, number, true);
    return EOK;
}

int setDirectionrayLeds(bool forward){
    if(forward){
        setGpioPin(GPIOE, FORWARD_LED_PIN, true);
        setGpioPin(GPIOE, BACKWARD_LED_PIN, false);
    }
    else {
        setGpioPin(GPIOE, FORWARD_LED_PIN, false);
        setGpioPin(GPIOE, BACKWARD_LED_PIN, true);
    }
    return EOK;
}