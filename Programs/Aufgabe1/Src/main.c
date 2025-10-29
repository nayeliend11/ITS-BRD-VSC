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
	int val = 0;

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

		/*case 'p':
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

		case 'n':
		val = val *10 + token.val; //verschiebt zahl auf nächste Stelle xxxx1 -> xxx1x
		intToString()
		printStdout
		break;

		case ' ':
		push(val);
		break;

		case'U':
		//fehlerbehanlung
		break;

		case'O':
		//fehlerbehandlung
		break;
*/
		//default: if(token.val<0){
			//fehler
		//} else {

	}

}

}




