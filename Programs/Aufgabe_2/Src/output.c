#include "output.h"
#include "LCD_GUI.h"
#include "error.h"
#include "errors.h"
#include "fonts.h"
#include "terminal.h"

struct display{
    Terminal title;
    Terminal winkelString;
    Terminal winkelGesString;
    Terminal winkelNum0;
    Terminal winkelNum1;
    Terminal winkelNum2;
    Terminal winkelGesNum0;
    Terminal winkelGesNum1;
    Terminal winkelGesNum2;
    Terminal winkelGesNum3;
    Terminal error;
}display;

int stdLayout(){
    Coordinate TopLeft;
	Coordinate BottomRight;

	TopLeft.x = 20;
	TopLeft.y = 20;

	BottomRight.x = 200;
	BottomRight.y = 45;

	display.title = genTerm(TopLeft, BottomRight, WHITE, BLACK, &Font24);
	printTerm("Aufgabe 2", &display.title);

	TopLeft.x = 20;
	TopLeft.y = 60;

	BottomRight.x = 200;
	BottomRight.y = 85;

	display.winkelString = genTerm(TopLeft, BottomRight, WHITE, BLACK, &Font24);
	printTerm("Winkel:", &display.winkelString);

	TopLeft.x = 20;
	TopLeft.y = 100;

	BottomRight.x = 40;
	BottomRight.y = 125;

	display.winkelNum0 = genTerm(TopLeft, BottomRight, WHITE, BLACK, &Font24);
	printTerm("0", &display.winkelNum0);

	TopLeft.x = 40;
	TopLeft.y = 100;

	BottomRight.x = 60;
	BottomRight.y = 125;

	display.winkelNum1 = genTerm(TopLeft, BottomRight, WHITE, BLACK, &Font24);
	printTerm("0", &display.winkelNum1);

	TopLeft.x = 60;
	TopLeft.y = 100;

	BottomRight.x = 80;
	BottomRight.y = 125;

	display.winkelNum2 = genTerm(TopLeft, BottomRight, WHITE, BLACK, &Font24);
	printTerm("0", &display.winkelNum2);

	TopLeft.x = 20;
	TopLeft.y = 140;

	BottomRight.x = 400;
	BottomRight.y = 165;

	display.winkelGesString = genTerm(TopLeft, BottomRight, WHITE, BLACK, &Font24);
	printTerm("Winkelgeschwindigkeit:", &display.winkelGesString);

	TopLeft.x = 20;
	TopLeft.y = 180;

	BottomRight.x = 40;
	BottomRight.y = 205;

	display.winkelGesNum0 = genTerm(TopLeft, BottomRight, WHITE, BLACK, &Font24);
	printTerm("0", &display.winkelGesNum0);

	TopLeft.x = 40;
	TopLeft.y = 180;

	BottomRight.x = 60;
	BottomRight.y = 205;

	display.winkelGesNum1 = genTerm(TopLeft, BottomRight, WHITE, BLACK, &Font24);
	printTerm("0", &display.winkelGesNum1);

	TopLeft.x = 60;
	TopLeft.y = 180;

	BottomRight.x = 80;
	BottomRight.y = 205;

	display.winkelGesNum2 = genTerm(TopLeft, BottomRight, WHITE, BLACK, &Font24);
	printTerm("0", &display.winkelGesNum2);

	TopLeft.x = 80;
	TopLeft.y = 180;

	BottomRight.x = 100;
	BottomRight.y = 205;

	display.winkelGesNum3 = genTerm(TopLeft, BottomRight, WHITE, BLACK, &Font24);
	printTerm("0", &display.winkelGesNum3);

    TopLeft.x = 20;
	TopLeft.y = 220;

	BottomRight.x = 450;
	BottomRight.y = 295;

    display.error = genTerm(TopLeft, BottomRight,WHITE, RED, &Font24);
    
    return EOK;
}

int printError(char *err_msg){
    printTerm(err_msg, &display.error);
    return EOK;
}

int printWinkel(char* winkel, int pos){

}

int printWinkelges(char* winkelGes, int pos){

}