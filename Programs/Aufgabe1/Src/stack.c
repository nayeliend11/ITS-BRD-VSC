#include "stack.h"
#include "errors.h"
#include <stdbool.h>

#define NULL 0

#define EMPTY_STACK -1
#define STACK_SIZE 10

static Stack stack;
static int arr[STACK_SIZE];

int initStack(){
    stack.size = STACK_SIZE;
    stack.top = EMPTY_STACK;
    stack.arr = arr;
    if(stack.arr == NULL && stack.top != EMPTY_STACK && stack.size != STACK_SIZE) return STACK_INITILASITION_FAILED;
    return EOK;
}

void deleteStack(){
    stack.arr = NULL;
    stack.size = 0;
    stack.top = 0;
}

bool isStackEmpty(){
    if(stack.top == EMPTY_STACK) return true;
    return false;
}

bool isStackFull(){
    if(stack.top == stack.size - 1) return true;
    return false;
}

int push(int val){
    if(stack.arr == NULL) return STACK_NOT_INITALISED;
    if(isStackFull()) return STACK_OVERFLOW;
    stack.top++;
    stack.arr[stack.top] = val;
    return EOK;
}

int pop(int *val){
    if(stack.arr == NULL) return STACK_NOT_INITALISED;
    if(isStackEmpty()) return STACK_UNDERFLOW;
    *val = stack.arr[stack.top];
    stack.top--;
    return EOK;
}

int peak(int index, int* val){
    if(stack.arr == NULL) return STACK_NOT_INITALISED;
    if(isStackEmpty()) return STACK_UNDERFLOW;
    *val = stack.arr[index];
    return EOK;
}

int clearStack(){
    if(stack.arr == NULL) return STACK_NOT_INITALISED;
    int stack_size = stack.size;
    int errorcode = 0;
    deleteStack();
    errorcode = initStack();
    if (errorcode != EOK) return errorcode;
    return EOK;
}

int duplicate(){
    if(stack.arr == NULL) return STACK_NOT_INITALISED;
    int errorCode = 0;
    int val = 0;

    errorCode = peak(stack.top, &val);
    if(errorCode != EOK) return errorCode;
    errorCode = push(val);
    if(errorCode != NULL) return errorCode;
    return EOK;
}

int swap(){
    int firstElem = 0;
    int secondElem = 0;
    int errorCode = 0;

    errorCode = pop(&firstElem);
    if(errorCode != EOK) return errorCode;
    errorCode = pop(&secondElem);
    if(errorCode != EOK) return errorCode;
    errorCode = push(firstElem);
    if(errorCode != EOK) return errorCode;
    errorCode = push(secondElem);
    if(errorCode != EOK) return errorCode;
    return EOK;
}


