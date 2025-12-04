#include "taster.h"
#include "gpio.h"
#include "errors.h"
#include "stm32f429xx.h"

#define BUTTON_PRESSED 1
#define S6_PIN 6

int waitForTaster(){
    int value;
    int errCode;
    do {
        errCode = readGpioPin(GPIOF, S6_PIN, &value);
        if(errCode!=EOK)return errCode;
    }while (value != BUTTON_PRESSED);
    return EOK;
}