#ifndef LOGIC_H
#define LOGIC_H

#include "stdbool.h"

typedef struct Status Status;
struct Status{
    bool vorwärts;
    u_short anzahl_phasenwechsel;
    drehgeschwindigkeit;
    winkel;
};

#endif
//eof