#ifndef LOGIC_H
#define LOGIC_H

#include "stdbool.h"

typedef struct Status Status;
struct Status{
    bool vorwärts;
    short anzahl_phasenwechsel;
    double drehgeschwindigkeit;
    double winkel;
};

#endif
//eof