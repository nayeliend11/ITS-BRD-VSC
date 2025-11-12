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
#include "error.h"
#include "output.h"

#include "stm32f4xx_hal.h"
#include "init.h"
#include "LCD_GUI.h"
#include "LCD_Touch.h"
#include "lcd.h"
#include "fontsFLASH.h"
#include "additionalFonts.h"


#define STACK_SIZE 10

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

	Stack stack; 
	errorCode = newStack(&stack, STACK_SIZE);

while(1){
	T_token token = nextToken();
	switch(token.tok){

		case '+':
		errorCode = plus(&stack);
		break;

		case '-':
		errorCode = minus(&stack);
		break; 

		case '*':
		errorCode = multiply(&stack);
		break;

		case '/':
		errorCode = divide(&stack);
		break;

		case 'p':
		errorCode = printTop(&stack);
		break;

		case 'P':
		errorCode = printStack(&stack);
		break;

		case'C':
		errorCode = stack.clear(&stack);
		break;

		case'd':
		errorCode = stack.duplicate(&stack);
		break;

		case'r':
		errorCode = stack.swap(&stack);
		break;

		case ' ':
		errorCode = stack.push(&stack, token.val);
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




