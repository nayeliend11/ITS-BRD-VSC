#include "arithmetik.h"
#include "stack.h"
#include <limits.h>

int plus(Stack *stack){
    int a, b;
    stack->pop(stack, &a);
    stack->pop(stack, &b);
    long sum = a+b;
    if(sum > INT_MAX ||sum < INT_MIN)
{
    //fehlerbehandlung
}    stack->push(stack, sum);
}

int minus(Stack *stack){
    int a,b;
    stack->pop(stack, &a);
    stack->pop(stack, &b);
    long sum = b-a;
    if(sum > INT_MAX ||sum < INT_MIN){
        //fehlerbehandlung
    }
    stack->push (stack, sum); 

}

int multiply(Stack *stack){
    int a,b;
    stack->pop(stack, &a);
    stack->pop(stack, &b);
    long sum = a*b;
    if(a == 0||b == 0){
        stack->push(stack, 0);
    } else if  (sum > INT_MAX ||sum < INT_MIN) {
     //fehlerbehandlung
    } else {
    stack->push(stack, sum);
    }
    
}

int divide(Stack *stack){
    int a,b;
    stack->pop(stack, &a);
    stack->pop(stack, &b);

     if(a == 0||b == 0){
        //fehlerbehandlung;
     } else {
       stack->push (stack, a/b);
     }
    
}