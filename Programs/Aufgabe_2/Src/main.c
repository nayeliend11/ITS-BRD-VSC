/**
  ******************************************************************************
  * @file    main.c
  * @author  Franz Korf
  * @brief   Kleines Testprogramm fuer neu erstelle Fonts.
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/

#include "LCD_general.h"
#include "errors.h"
#include "fonts.h"
#include "led.h"
#include "output.h"
#include "stm32f429xx.h"
#include "stm32f4xx_hal.h"
#include "init.h"
#include "LCD_GUI.h"
#include "LCD_Touch.h"
#include "lcd.h"
#include "fontsFLASH.h"
#include "additionalFonts.h"
#include "error.h"
#include "gpio.h"
#include "taster.h"
#include <math.h>
#include <stdbool.h>
#include "terminal.h"

/**
 * @brief Format angle for display (3 characters)
 */
static void format_angle(double angle, char* buffer)
{
    int angle_int;
    
    /* Get absolute value, limit to 0-999 */
    if (angle < 0) angle = -angle;
    angle_int = (int)fmod(angle, 1000.0);
    
    /* Format as 3 digits */
    buffer[0] = '0' + (angle_int / 100);
    buffer[1] = '0' + ((angle_int / 10) % 10);
    buffer[2] = '0' + (angle_int % 10);
}


/**
 * @brief Format velocity for display (4 characters)
 */
static void format_velocity(double velocity, char* buffer)
{
    int vel_int;
    
    /* Get absolute value, limit to 0-9999 */
    if (velocity < 0) velocity = -velocity;
    vel_int = (int)fmod(velocity, 10000.0);
    
    /* Format as 4 digits */
    buffer[0] = '0' + (vel_int / 1000);
    buffer[1] = '0' + ((vel_int / 100) % 10);
    buffer[2] = '0' + ((vel_int / 10) % 10);
    buffer[3] = '0' + (vel_int % 10);
}


/**
 * @brief Main function
 */
int main(void)
{
    TransitionResult_t result;
    Direction_t direction;
    double angle;
    double velocity;
    char angleStr[4];
    char velocityStr[5];
    
    /*
     * ========================================
     * INITIALIZATION
     * ========================================
     */
    
    /* Initialize ITS Board hardware */
    initITSboard();
    
    /* Initialize LCD */
    GUI_init(DEFAULT_BRIGHTNESS);
    TP_Init(false);
    
    /* Initialize LCD layout */
    initLayout();
    
    /* Initialize modules */
    input_init();
    error_init();
    logic_init();
    
    
    /*
     * ========================================
     * SUPER-LOOP
     * ========================================
     */
    while (1)
    {
        /*
         * STEP 1: Read and process encoder
         */
        logic_process(&result);
        
        
        /*
         * STEP 2: Check error button (S6)
         */
        error_update();
        
        
        /*
         * STEP 3: Update binary counter LEDs (D8-D15)
         */
        setBinaryLeds(logic_get_step_count_8bit());
        
        
        /*
         * STEP 4: Update direction LEDs (D22, D23)
         */
        direction = logic_get_direction();
        if (direction == DIR_FORWARD) {
            setDirectionrayLeds(true);   /* D23 on, D22 off */
        } else if (direction == DIR_BACKWARD) {
            setDirectionrayLeds(false);  /* D23 off, D22 on */
        }
        
        
        /*
         * STEP 5: Update display (every 250-500ms)
         */
        if (logic_should_update_display())
        {
            angle = logic_get_angle();
            velocity = logic_get_angular_velocity();
            
            format_angle(angle, angleStr);
            format_velocity(velocity, velocityStr);
            
            setWinkel(angleStr);
            setWinkelges(velocityStr);
        }
        
        
        /*
         * STEP 6: Output one character to display
         */
        printNumbers();
    }
    
    return EOK;
}

/*int main(void) {
	initITSboard();    // Initialisierung des ITS Boards
	
	GUI_init(DEFAULT_BRIGHTNESS);   // Initialisierung des LCD Boards mit Touch
	TP_Init(false);                 // Initialisierung des LCD Boards mit Touch

	/*
	// Test in Endlosschleife
	while(1) {
		//Input
		int phase;

		//Berechnung


	}

	initLayout();
	printError("Hello World");
	return EOK;
}*/

// EOF
