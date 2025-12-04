#include "led.h"
#include "errors.h"
#include "general.h"
#include "gpio.h"
#include "stm32f429xx.h"
#include <stdbool.h>



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

