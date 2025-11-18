#include "arithmetik.h"
#include "errors.h"
#include "stack.h"
#include <limits.h>

int plus(Stack *stack){
    int a, b;
    stack->pop(stack, &a);
    stack->pop(stack, &b);
    long sum = a+b;
    if(sum > INT_MAX )
{
   return error_handler(NUMBER_OVERFLOW);
}  if (sum < INT_MIN){
    return error_handler(NUMBER_UNDERFLOW);
} else {
stack->push(stack, sum);
}
return EOK;
  
}

int minus(Stack *stack){
    int a,b;
    stack->pop(stack, &a);
    stack->pop(stack, &b);
    long sum = b-a;
      if(sum > INT_MAX )
{
   return error_handler(NUMBER_OVERFLOW);
}  if (sum < INT_MIN){
    return error_handler(NUMBER_UNDERFLOW);
} else {
    stack->push (stack, sum); 

}
return EOK;
}

int multiply(Stack *stack){
    int a,b;
    stack->pop(stack, &a);
    stack->pop(stack, &b);
    long sum = a*b;
    if(a == 0||b == 0){
        stack->push(stack, 0);
    } else    if(sum > INT_MAX )
{
   return error_handler(NUMBER_OVERFLOW);
}  if (sum < INT_MIN){
    return error_handler(NUMBER_UNDERFLOW);
} else {
    stack->push(stack, sum);
    }
    return EOK;
}

int divide(Stack *stack){
    int a,b;
    stack->pop(stack, &a);
    stack->pop(stack, &b);
    long sum = a/b;

     if(a == 0||b == 0){
        return error_handler(DIVISION_WITH_ZERO);
     } else if (sum > INT_MAX )
{
   return error_handler(NUMBER_OVERFLOW);
}  if (sum < INT_MIN){
    return error_handler(NUMBER_UNDERFLOW);
} else {
       stack->push (stack, a/b);
     }
    return EOK;
}