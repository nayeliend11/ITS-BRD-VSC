#ifndef LED_H
#define LED_H
#include "stdbool.h"

/*
*@Brief: Schaltet LED D21 an
*@return: EOK wird zurückgegeben, wenn keine Fehler aufgetreten sind
*/
int errorLedOn();
/*
*@Brief: Schaltet LED D21 aus
*@return: EOK wird zurückgegeben, wenn keine Fehler aufgetreten sind
*/
int errorLedOff();
/*
*@Brief: setzt LEDs D8 - D15 in binär Darstellung der übergebenen Zahl
*@Param: number ist die in binär darzustellende Zahl
*@return: EOK wird zurückgegeben, wenn keine Fehler aufgetreten sind
*/
int setBinaryLeds(int number);
/*
*@Brief: Setzt D23 wenn eine vorwärst Richtung erkannt wurde und D22 bei einer rückwärts Richtung
*@Param: number ist die in binär darzustellende Zahl
*@return: EOK wird zurückgegeben, wenn keine Fehler aufgetreten sind
*/
int setDirectionrayLeds(bool forward);

#endif
//eof