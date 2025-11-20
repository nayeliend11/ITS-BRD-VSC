#include "arithmetik.h"
#include "errors.h"
#include "stack.h"
#include <limits.h>

int plus(Stack *stack){
    int a, b, errorCode,sum;
    errorCode = stack->pop(stack, &a);
    if(errorCode != EOK)return errorCode;
    errorCode = stack->pop(stack, &b);
    if(errorCode != EOK)return errorCode;

    if(a >= 0){
        if( b > INT_MAX - a){
            return NUMBER_OVERFLOW;
        }
    }
    else{
        if( b < INT_MIN - a){
            return NUMBER_UNDERFLOW;
        }
    }

    sum = a+b;
    errorCode = stack->push(stack, sum);
    if(errorCode != EOK)return errorCode;
    return EOK;
  
}

int minus(Stack *stack){
    int a,b,errorCode;
    errorCode = stack->pop(stack, &a);
    if(errorCode != EOK)return errorCode;
    errorCode = stack->pop(stack, &b);
    if(errorCode != EOK)return errorCode;
    long long sum = b-a;
    if(a >= 0){
        if(b < INT_MIN + a){
            return NUMBER_UNDERFLOW;
        }
    } else {
        if (b > INT_MAX + a) {
            return NUMBER_OVERFLOW;
        }
    }

    errorCode = stack->push (stack, sum); 
    if(errorCode != EOK)return errorCode;
    return EOK;
}

int multiply(Stack *stack){
    int a,b,errorCode;

    errorCode = stack->pop(stack, &a);
    if(errorCode != EOK) return errorCode;
    errorCode = stack->pop(stack, &b);
    if(errorCode != EOK) return errorCode;

    long sum = a*b;
    
    if(sum/b != a){
        return NUMBER_OVERFLOW;
    }
    errorCode = stack->push(stack,sum);
    if(errorCode != EOK) return errorCode;
    return EOK;
}

int divide(Stack *stack){
    int a,b, errorCode;
    errorCode = stack->pop(stack, &b);
    if(errorCode != EOK)return errorCode;
    errorCode = stack->pop(stack, &a);
    if(errorCode != EOK)return errorCode;
    long sum = a/b;

     if(a == 0||b == 0){
        return error_handler(DIVISION_WITH_ZERO);
     } else if (sum > INT_MAX )
{
   return error_handler(NUMBER_OVERFLOW);
}  if (sum < INT_MIN){
    return error_handler(NUMBER_UNDERFLOW);
} else {
       errorCode = stack->push (stack, a/b);
       if(errorCode != EOK)return errorCode;
     }
    return EOK;
}