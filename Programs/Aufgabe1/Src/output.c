#include "output.h"
#include "display.h"
#include "errors.h"
#include "stack.h"
#include <limits.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


void  intToString(int val, char *output){

    char buffer [16];
    int i= 0, j;
    int top = -1;
    bool negative = (val < 0);
    int temp_val = val;
  
     // sonderfall einführen für INTMIN! 
    if(val == INT_MIN){
    int last_digit = -(val%10);
    buffer [i++] = last_digit + '0';
    temp_val = -(val/10);
    negative = true;
    }
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

int printTop(Stack *stack){
 if(stack == NULL){
       return error_handler(NO_STACK);
   }
    char buffer[16]= {0};
    int value = 0;
    intToString(value, buffer);
    printStdout(buffer);
    return EOK;
}
int printStack(Stack *stack){
    if(stack == NULL){
       return error_handler(NO_STACK);
   }
    char buffer[16]= {0};
    int i = 0;

    for (i = stack ->top; i>= 0; i--)
    {
        int value = stack ->arr[i];

        intToString(value, buffer);

        printStdout(buffer);

    }
    return EOK; 

}