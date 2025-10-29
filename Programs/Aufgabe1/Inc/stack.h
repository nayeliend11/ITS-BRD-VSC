
#ifndef STACK_H
#define STACK_H

#include "errors.h"
#include <stdbool.h>

struct stack{
    int size;
    int top;
    int *arr;
}typedef Stack;

int initStack(int size);
void deleteStack();
int push(int val);
int pop(int* val);
bool isStackFull();
bool isStackEmpty();
int peak(int index, int *val);
int clearStack();
int duplicate();
int swap();

#endif
//eof