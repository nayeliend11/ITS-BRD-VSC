#include "output.h"
#include "display.h"
#include "stack.h"
#include <limits.h>
#include <stdbool.h>


void  intToString(int val, char *output){

    char buffer [16];
    int i= 0, j;
    bool negative = (val < 0);

    if(negative){
        val = -val;
    }
    
    // sonderfall einführen für INTMIN! 

  
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

int printTop(){
if (isStackEmpty())
{
    /* fehlerbehandlung */
}
intToString();
printStdout();

}
int printStack(){
    if(isStackEmpty()){
        // fehlerbehandlung
    }
}