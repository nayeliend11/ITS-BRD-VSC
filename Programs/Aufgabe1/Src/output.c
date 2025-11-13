#include "output.h"
#include "display.h"
#include "stack.h"
#include <limits.h>
#include <stdio.h>
#include <stdbool.h>


void  intToString(int val, char *output){

    char buffer [16];
    int i= 0, j;
    int top = -1;
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

int printTop(Stack *stack){
//if (isStackEmpty())
//{
    /* fehlerbehandlung */
//}
    char buffer[16]= {0};
    int value = 0;
    intToString(value, buffer);
    printStdout(buffer);

}
int printStack(Stack *stack){
    //if(isStackEmpty()){
        // fehlerbehandlung
   // }
    char buffer[16]= {0};
    int i = 0;

    for (i = stack ->top; i>= 0; i--)
    {
        int value = stack ->arr[i];

        intToString(value, buffer);

        printStdout(buffer);

    }

}