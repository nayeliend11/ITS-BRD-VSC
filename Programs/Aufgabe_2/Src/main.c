/**
  ******************************************************************************
  * @file    main.c
  * @author  Franz Korf
  * @brief   Kleines Testprogramm fuer neu erstelle Fonts.
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/

#include "errors.h"
#include "led.h"
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
#include <stdbool.h>


int main(void) {
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
		*/
		while (1) {
		setGpioReg(GPIOD, 0xf0, true);
		waitForTaster();
		setGpioReg(GPIOD, 0xf0, false);
		waitForTaster();
		}
		
		
	return EOK;
}

// EOF
