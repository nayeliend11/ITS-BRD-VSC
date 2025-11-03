
#ifndef STACK_H
#define STACK_H

#include "errors.h"
#include <stdbool.h>
//#include "stdlib.h"
typedef struct Stack Stack;
struct Stack{
    //Variablen
    int size;
    int top;
    int *arr;
    //Funktions-pointer
    int (*push)(Stack *self, int val);
    int (*pop)(Stack *self, int* val);
    int (*peak)(Stack *self, int index, int *val);
    int (*clear)(Stack *self);
    int (*duplicate)(Stack *self);
    int (*swap)(Stack *self);
    void (*delete)(Stack *self);
    bool (*isEmpty)(Stack *self);
    bool (*isFull)(Stack *self);
}typedef Stack;

int newStack(Stack* stack_ptr, int size);
#endif
//eof