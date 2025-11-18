#ifndef ARITHMETIK_H
#define ARITHMETIK_H

#include "stack.h"

int plus(Stack *stack);
/*
Addiert die beiden obersten Werte des Stacks.
Die Werte werden vom Stack entfernt und das Ergebnis wird statdessen auf den Stack gelegt. 
Es wird auf Overflow / Underflow geprüft.
*/


int minus(Stack *stack);  

/*
Subtrahiert 1.(oberen) Wert auf dem Stack von dem 2.
Die Werte werden vom Stack entfernt und das Ergebnis wird statdessen auf den Stack gelegt.
Es wird auf Overflow / Underflow geprüft.
*/
int multiply(Stack *stack); 
/*
Multiplizert die beiden obersten Werte des Stacks.
Die Werte werden vom Stack entfernt und das Ergebnis wird statdessen auf den Stack gelegt. 
Es wird auf Overflow / Underflow geprüft.
*/

int divide(Stack *stack); //teilt den 2. Wert durch den 1.
/*
Dividiert den zweitobersten Wert / obersten Wert des Stacks.
Die Werte werden vom Stack entfernt und das Ergebnis wird statdessen auf den Stack gelegt. 
Es wird auf Overflow / Underflow geprüft.
Es wird auf eine Division mit Null geprüft. 
*/



#endif