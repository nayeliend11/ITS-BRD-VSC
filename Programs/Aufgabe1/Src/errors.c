#include "errors.h"
#include "display.h"
#include "scanner.h"
#include <stdlib.h>

#define LEN_ERR_MSG 256

int error_handler(int errorCode){
    char *errorMsg;
    int returnVal = EOK;
    setErrMode();
    switch (errorCode) {
        case STACK_OVERFLOW:
            errorMsg = "Es fand ein Stack Overflow statt!\n";
            break;
        case STACK_UNDERFLOW:
            errorMsg = "Es fand ein Stack Underflow statt!\n";
            break;
        case NUMBER_OVERFLOW:
            errorMsg = "Es fand ein Arithmetischer Overflow statt!\n";
            break;
        case NUMBER_UNDERFLOW:
            errorMsg = "Es fand ein Arithmetischer Underflow statt!\n";
            break;
        case DIVISION_WITH_ZERO:
            errorMsg = "Es wurde versucht durch Null zu teilen!\n";
            break;
        case UNEXPECTED_INPUT:
            errorMsg = "Ein unerwartetes Signal ist eingegangen!\n";
            break;
        case STACK_INITILASITION_FAILED:
            errorMsg = "Stack konnte nicht initialisiert werden!\n";
            break;
        case STACK_NO_ARRAY:
            errorMsg = "Stack Array wurde nicht gefunden!\n";
            break;
        case NO_STACK:
            errorMsg = "Stack wurde nicht initialisiert!\n";
            break;
        case NO_VALUE:
            errorMsg = "Ein Wert wurde nicht gefunden!\n";
            break;
        case INDEX_OUT_OF_BOUND:
            errorMsg = "Index ist außerhalb des zulässigen Zugriffsbereichs!\n";
            break;
        case STACK_SIZE_INVALID:
            errorMsg = "Die gewählte maximale Stack göße ist ungültig\n";
            break;
        default:
            errorMsg = "Unbekannter errorCode!\n";
            returnVal = errorCode;
            break;
    }
    printStdout(errorMsg);
    while(true){
        T_token input = nextToken();
        if(input.tok == 'C'){
            //evtl. clear command
            break;
        }
    }
    return returnVal;
}