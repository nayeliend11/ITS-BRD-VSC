#ifndef OUTPUT_H
#define OUTPUT_H
#include "terminal.h"

/*
*@Brief Gibt das Standartlayout auf dem Display aus. Das StandartLayout ist der Text der während der Laufzeit auf dem Display zusehen ist.
*@Return EOK wird zurückgegeben, wenn kein Fehler auftritt.
*/
int stdLayout();
/*
*@Brief Gibt den übergebenden String als Fehlermeldung aus.
*@Param err_msg ist ein Pointer auf ein String, welcher ausgegeben werden soll.
*/
int printError(char* err_msg);
/*
*@Brief Entfernt alle 
*@Param
*/
int printWinkel(char* winkel, int pos);
/*
*@Brief Entfernt alle 
*@Param
*/
int printWinkelges(char* winkelges, int pos);
#endif
//eof