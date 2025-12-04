#ifndef OUTPUT_H
#define OUTPUT_H
#include "terminal.h"

/*
*@Brief Gibt das Standartlayout auf dem Display aus. Das StandartLayout ist der Text der während der Laufzeit auf dem Display zusehen ist.
*@Return EOK wird zurückgegeben, wenn kein Fehler auftritt.
*/
int initLayout();
/*
*@Brief Gibt den übergebenden String als Fehlermeldung aus.
*@Param err_msg ist ein Pointer auf ein String, welcher ausgegeben werden soll.
*/
int printError(char* err_msg);
/*
*@Brief Entfernt alle 
*@Param
*/
int setWinkel(char* winkel);
/*
*@Brief Entfernt alle 
*@Param
*/
int setWinkelges(char* winkelges);

int printNumbers();
#endif
//eof