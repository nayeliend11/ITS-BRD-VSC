#include "stack.h"
#include "errors.h"
#include "token.h"
#include <stdbool.h>
#include <stdlib.h>

#define EMPTY_STACK -1



int deleteStack(Stack *self){
    if(self == NULL)return NO_STACK;
    free(self->arr);
    self->arr = NULL;
    self->push = NULL;
    self->pop = NULL;
    self->peak = NULL;
    self->clear = NULL;
    self->duplicate = NULL;
    self->swap = NULL;
    self->delete = NULL;
    free(self);
    return EOK;
}

bool isStackEmpty(Stack *self){
    if(self->top == EMPTY_STACK) return true;
    return false;
}

bool isStackFull(Stack *self){
    if(self->top == self->size - 1) return true;
    return false;
}

int push(Stack *self, int val){
    if(self == NULL) return  NO_STACK;
    if(val == NULL) return NO_VALUE;
    if(self->arr == NULL) return STACK_NO_ARRAY;
    if(isStackFull(self)) return STACK_OVERFLOW;
    self->top++;
    self->arr[self->top] = val;
    return EOK;
}

int pop(Stack *self, int *val){
    if(self == NULL) return  NO_STACK;
    if(val == NULL) return NO_VALUE;
    if(self->arr == NULL) return STACK_NO_ARRAY;
    if(isStackEmpty(self)) return STACK_UNDERFLOW;
    *val = self->arr[self->top];
    self->top--;
    return EOK;
}

int peak(Stack *self, int index, int* val){
    if(self == NULL) return  NO_STACK;
    if(val == NULL) return NO_VALUE;
    if(self->arr == NULL) return STACK_NO_ARRAY;
    if(isStackEmpty(self)) return STACK_UNDERFLOW;
    if(index > self->top || index < 0) return INDEX_OUT_OF_BOUND;
    *val = self->arr[index];
    return EOK;
}

int clearStack(Stack *self){
    if(self == NULL) return  NO_STACK;
    if(self->arr == NULL) return STACK_NO_ARRAY;
    self->top = EMPTY_STACK;
    return EOK;
}

int duplicate(Stack *self){
    if(self == NULL) return  NO_STACK;
    int errorCode = 0;
    int val = 0;

    errorCode = self->peak(self,self->top, &val);
    if(errorCode != EOK) return errorCode;
    errorCode = self->push(self, val);
    if(errorCode != EOK) return errorCode;
    return EOK;
}

int swap(Stack *self){
    if(self == NULL) return  NO_STACK;
    int firstElem = 0;
    int secondElem = 0;
    int errorCode = 0;

    errorCode = self->pop(self, &firstElem);
    if(errorCode != EOK) return errorCode;
    errorCode = self->pop(self, &secondElem);
    if(errorCode != EOK){
        if(errorCode == STACK_UNDERFLOW){
            self->push(self,firstElem);
        }
        return errorCode;
    }
    errorCode = self->push(self, firstElem);
    if(errorCode != EOK) return errorCode;
    errorCode = self->push(self, secondElem);
    if(errorCode != EOK) return errorCode;
    return EOK;
}


int newStack(Stack* stack_ptr, int size){

    stack_ptr->size = size;
    stack_ptr->top = EMPTY_STACK;
    stack_ptr->arr = (int*) calloc(size, sizeof(int));
    stack_ptr->push = push;
    stack_ptr->pop = pop;
    stack_ptr->peak = peak;
    stack_ptr->clear = clearStack;
    stack_ptr->duplicate = duplicate;
    stack_ptr->swap = swap;
    stack_ptr->delete = deleteStack;

    if(stack_ptr->arr == NULL) return STACK_INITILASITION_FAILED;
    return EOK;
}
