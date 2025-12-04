#include "output.h"
#include "LCD_GUI.h"
#include "errors.h"
#include "fonts.h"
#include "terminal.h"

#define FONT &Font24
#define WINKEL_MAX_NUMBER_LENGTH 3
#define WINKELGES_MAX_NUMBER_LENGTH 4

struct display{
    Terminal title;
    Terminal winkelString;
    Terminal winkelGesString;
    Terminal winkelNum [3];
    Terminal winkelGesNum [4];
    Terminal error;
}display;

struct winkel{
    int index;
    char winkel[3];
}winkelToPrint,currentWinkel;

struct winkelGes{
    int index;
    char winkelGes[4];
}winkelGesToPrint,currentWinkelGes;

int initLayout(){
    Coordinate TopLeft;
	Coordinate BottomRight;


    winkelGesToPrint.index = 0;
    for(int i = 0; i < WINKELGES_MAX_NUMBER_LENGTH; i++){
        winkelGesToPrint.winkelGes[i] = '0';
    }
    winkelToPrint.index = 0;
    for(int i = 0; i < WINKEL_MAX_NUMBER_LENGTH; i++){
        winkelToPrint.winkel[i] = '0';
    }
    currentWinkelGes.index = 0;
    for(int i = 0; i < WINKELGES_MAX_NUMBER_LENGTH; i++){
        currentWinkelGes.winkelGes[i] = '0';
    }
    currentWinkel.index = 0;
    for(int i = 0; i < WINKEL_MAX_NUMBER_LENGTH; i++){
        currentWinkel.winkel[i] = '0';
    }

	TopLeft.x = 20;
	TopLeft.y = 20;

	BottomRight.x = 200;
	BottomRight.y = 45;

	display.title = genTerm(TopLeft, BottomRight, WHITE, BLACK, FONT);
	printTerm("Aufgabe 2", &display.title);

	TopLeft.x = 20;
	TopLeft.y = 60;

	BottomRight.x = 200;
	BottomRight.y = 85;

	display.winkelString = genTerm(TopLeft, BottomRight, WHITE, BLACK, FONT);
	printTerm("Winkel:", &display.winkelString);

	TopLeft.x = 20;
	TopLeft.y = 100;

	BottomRight.x = 40;
	BottomRight.y = 125;

	display.winkelNum[0] = genTerm(TopLeft, BottomRight, WHITE, BLACK, FONT);
	printTerm("0", &display.winkelNum[0]);

	TopLeft.x = 40;
	TopLeft.y = 100;

	BottomRight.x = 60;
	BottomRight.y = 125;

	display.winkelNum[1] = genTerm(TopLeft, BottomRight, WHITE, BLACK, FONT);
	printTerm("0", &display.winkelNum[1]);

	TopLeft.x = 60;
	TopLeft.y = 100;

	BottomRight.x = 80;
	BottomRight.y = 125;

	display.winkelNum[2] = genTerm(TopLeft, BottomRight, WHITE, BLACK, FONT);
	printTerm("0", &display.winkelNum[2]);

	TopLeft.x = 20;
	TopLeft.y = 140;

	BottomRight.x = 400;
	BottomRight.y = 165;

	display.winkelGesString = genTerm(TopLeft, BottomRight, WHITE, BLACK, FONT);
	printTerm("Winkelgeschwindigkeit:", &display.winkelGesString);

	TopLeft.x = 20;
	TopLeft.y = 180;

	BottomRight.x = 40;
	BottomRight.y = 205;

	display.winkelGesNum[0] = genTerm(TopLeft, BottomRight, WHITE, BLACK, FONT);
	printTerm("0", &display.winkelGesNum[0]);

	TopLeft.x = 40;
	TopLeft.y = 180;

	BottomRight.x = 60;
	BottomRight.y = 205;

	display.winkelGesNum[1] = genTerm(TopLeft, BottomRight, WHITE, BLACK, FONT);
	printTerm("0", &display.winkelGesNum[1]);

	TopLeft.x = 60;
	TopLeft.y = 180;

	BottomRight.x = 80;
	BottomRight.y = 205;

	display.winkelGesNum[2] = genTerm(TopLeft, BottomRight, WHITE, BLACK, FONT);
	printTerm("0", &display.winkelGesNum[2]);

	TopLeft.x = 80;
	TopLeft.y = 180;

	BottomRight.x = 100;
	BottomRight.y = 205;

	display.winkelGesNum[3] = genTerm(TopLeft, BottomRight, WHITE, BLACK, FONT);
	printTerm("0", &display.winkelGesNum[3]);

    TopLeft.x = 20;
	TopLeft.y = 220;

	BottomRight.x = 450;
	BottomRight.y = 295;

    display.error = genTerm(TopLeft, BottomRight,WHITE, RED, FONT);
    
    return EOK;
}

int printError(char *err_msg){
    printTerm(err_msg, &display.error);
    return EOK;
}

int setWinkel(char* winkel){
    winkelToPrint.index = 0;
    for(int i = 0; i < WINKEL_MAX_NUMBER_LENGTH; i++){
        winkelToPrint.winkel[i] = winkel[i];
    }
    return EOK;
}

int setWinkelges(char* winkelGes){
    winkelGesToPrint.index = 0;
    for(int i = 0; i < WINKELGES_MAX_NUMBER_LENGTH; i++){
        winkelGesToPrint.winkelGes[i] = winkelGes[i];
    }
    return EOK;
}

int printNumbers(){
    if(winkelToPrint.index < WINKEL_MAX_NUMBER_LENGTH){
        if(currentWinkel.winkel[winkelToPrint.index] != winkelToPrint.winkel[winkelToPrint.index]){
            currentWinkel.winkel[winkelToPrint.index] = winkelToPrint.winkel[winkelToPrint.index];
            printTerm(&winkelToPrint.winkel[winkelToPrint.index], &display.winkelNum[winkelToPrint.index]);
        }
        winkelToPrint.index++;
    }
    if(winkelGesToPrint.index < WINKELGES_MAX_NUMBER_LENGTH){
        if (currentWinkelGes.winkelGes[winkelGesToPrint.index] != winkelGesToPrint.winkelGes[winkelGesToPrint.index]) {
            currentWinkelGes.winkelGes[winkelGesToPrint.index]  = winkelGesToPrint.winkelGes[winkelGesToPrint.index];
            printTerm(&winkelGesToPrint.winkelGes[winkelGesToPrint.index], &display.winkelGesNum[winkelGesToPrint.index]);
        }
        winkelGesToPrint.index++;
    }
    return EOK;
}