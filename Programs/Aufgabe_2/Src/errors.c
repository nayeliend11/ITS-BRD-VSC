
#include "errors.h"

/*int error_handler(int errorCode){
    char *errorMsg;
    int returnVal = EOK;
    //setErrMode();
    switch (errorCode) {
    }
}*/

/**
 * @file errors.c
 * @brief Error handling - LED D21 and button S6
 * 
 * ============================================================
 * HARDWARE:
 * ============================================================
 * LED D21 = GPIOE Pin 5 (ERROR_LED_PIN in general.h)
 * Button S6 = GPIOF Pin 6
 * 
 * ============================================================
 */


#include "gpio.h"
#include "led.h"
#include "general.h"
#include "stm32f429xx.h"
#include <stdbool.h>
#include <stdlib.h>

/*
 * BUTTON S6 DEFINITION
 */
#define S6_PIN          6
#define S6_PORT         GPIOF

/*
 * MODULE STATE
 */
static int current_error = EOK;
static bool button_was_pressed = false;


/**
 * @brief Initialize error module
 */
int error_init(void)
{
    current_error = EOK;
    button_was_pressed = false;
    errorLedOff();
    return EOK;
}


/**
 * @brief Set an error
 */
void error_set(int errorCode)
{
    current_error = errorCode;
    errorLedOn();
}


/**
 * @brief Clear the error
 */
void error_clear(void)
{
    current_error = EOK;
    errorLedOff();
}


/**
 * @brief Check if error is active
 */
bool error_is_active(void)
{
    return (current_error != EOK);
}


/**
 * @brief Update error state - check button S6
 * 
 * Uses edge detection: only clears on button press, not hold.
 */
int error_update(void)
{
    int button_raw;
    int errCode;
    bool button_pressed_now;
    
    /* Read button S6 */
    errCode = readGpioPin(S6_PORT, S6_PIN, &button_raw);
    if (errCode != EOK) {
        return errCode;
    }
    
    /*
     * gpio.c has inverted logic:
     * button_raw = 0 means button IS pressed
     * button_raw = 1 means button is NOT pressed
     */
    button_pressed_now = (button_raw == 0);
    
    /* Edge detection: clear only when button first pressed */
    if (button_pressed_now && !button_was_pressed) {
        error_clear();
    }
    
    button_was_pressed = button_pressed_now;
    
    return EOK;
}


/**
 * @brief Legacy error handler
 */
int error_handler(int errorCode)
{
    if (errorCode != EOK) {
        error_set(errorCode);
    }
    return EOK;
}


