#include "stack.h"

#define STACK_SIZE 10

int pop(int *val)
{
    return 0;
}
int stack [STACK_SIZE];
int count = 0;

int push(int val){
    if (count >= STACK_SIZE){
        return 0;//Fehlermeldung
    }
    stack[count] = val;
    count ++;
}
