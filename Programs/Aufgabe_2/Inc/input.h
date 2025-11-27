#ifndef INPUT_H
#define INPUT_H
#include "stdbool.h"

typedef enum {
    // Kanal A low, Kanal B low 
    PHASE_A = 0x00,
    // Kanal A high, Kanal B low 
    PHASE_B = 0x02,
    // Kanal A high, Kanal B high 
    PHASE_C = 0x03,
    // Kanal A low, Kanal B high 
    PHASE_D = 0x01
}phase_t;
#endif

bool input_A();
bool input_B();

void pins_aktualisieren();