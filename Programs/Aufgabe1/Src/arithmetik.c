#include "arithmetik.h"
#include "stack.h"
#include <limits.h>

void plus(){
    int a, b;
    pop(&a);
    pop(&b);
    long sum = a+b;
    if(sum > INT_MAX ||sum < INT_MIN)
{
    //fehlerbehandlung
}    push(sum);
}

void minus(){
    int a,b;
    pop(&a);
    pop(&b);
    long sum = b-a;
    if(sum > INT_MAX ||sum < INT_MIN){
        //fehlerbehandlung
    }
    push (sum); 

}

void multiply(){
    int a,b;
    pop(&a);
    pop(&b);
    long sum = a*b;
    if(a == 0||b == 0){
        push(0);
    } else if  (sum > INT_MAX ||sum < INT_MIN) {
     //fehlerbehandlung
    } else {
    push(sum);
    }
    
}

void divide(){
    int a,b;
    pop(&a);
    pop(&b);

     if(a == 0||b == 0){
        //fehlerbehandlung;
     } else {
       push (a/b);
     }
    
}