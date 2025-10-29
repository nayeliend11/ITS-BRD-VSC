/**
  ******************************************************************************
  * @file    main.c
  * @author  Franz Korf
  * @brief   Kleines Testprogramm fuer neu erstelle Fonts.
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "arithmetik.h"
#include "display.h"
#include "errors.h"
#include"stack.h"
#include "scanner.h"
#include "stm32f4xx_hal.h"
#include "init.h"
#include "LCD_GUI.h"
#include "LCD_Touch.h"
#include "lcd.h"
#include "fontsFLASH.h"
#include "additionalFonts.h"
#include "error.h"


int main(void) {
	initITSboard();    // Initialisierung des ITS Boards
	
	GUI_init(DEFAULT_BRIGHTNESS);   // Initialisierung des LCD Boards mit Touch
	TP_Init(false);                 // Initialisierung des LCD Boards mit Touch

  // Begruessungstext	
	//lcdPrintlnS("Hallo liebes TI-Labor (c-project)");
	
	// Test in Endlosschleife
	//while(1) {
		//HAL_Delay(10000);
	//}

	initDisplay();
	int errorCode = 0;

while(1){
	T_token token = nextToken();
	switch(token.tok){

		case '+':
		plus();
		break;

		case '-':
		minus();
		break; 

		case '*':
		multiply();
		break;

		case '/':
		divide();
		break;

		case 'p':
		printTop();
		break;

		case 'P':
		printAll();
		break;

		case'C':
		clearStack();
		break;

		case'd':
		duplicateTop();
		break;

		case'r':
		swap();
		break;

		case ' ':
		push(token.val);
		break;

		case'U':
		errorCode = UNEXPECTED_INPUT;
		break;

		case'O':
		errorCode = NUMBER_OVERFLOW;
		break;
	}

	if(errorCode != EOK){
		error_handler(errorCode);
		errorCode = EOK;
	}

}

}




