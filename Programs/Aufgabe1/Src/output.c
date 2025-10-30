#include "output.h"
#include <stdbool.h>



void  intToString(int val, char *output){

    char buffer [16];
    int i= 0, j;
    bool negative = (val < 0);

    if(negative){
        val = -val;
    }

    do {

        buffer[i] = (val %10) + '0'; // modulo schreibt rückwärts
        i++;
        val /=10;
    } while (val > 0);

    if (negative){
        buffer [i] = '-'; // vorzeichen hinzufügen 
        i++;
    }

    for (j = 0; j < i; j++) {
        output[j]= buffer [i-j-1]; // rückwärts reinschreiben 
    }
    output [j] = '\0';
}