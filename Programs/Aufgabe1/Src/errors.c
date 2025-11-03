#include "errors.h"
#include "display.h"
#include "scanner.h"
#include <stdlib.h>

#define LEN_ERR_MSG 256

int error_handler(int errorCode){
    char *errorMsg;
    setErrMode();
    switch (errorCode) {
        case STACK_OVERFLOW:
            errorMsg = "Es fand ein Stack Overflow statt!\n";
            printStdout(errorMsg);
            break;
        case STACK_UNDERFLOW:
            errorMsg = "Es fand ein Stack Underflow statt!\n";
            printStdout(errorMsg);
            break;
        case NUMBER_OVERFLOW:
            errorMsg = "Es fand ein Arithmetischer Overflow statt!\n";
            printStdout(errorMsg);
            break;
        case NUMBER_UNDERFLOW:
            errorMsg = "Es fand ein Arithmetischer Underflow statt!\n";
            printStdout(errorMsg);
            break;
        case DIVISION_WITH_ZERO:
            errorMsg = "Es wurde versucht durch Null zu teilen!\n";
            printStdout(errorMsg);
            break;
        case UNEXPECTED_INPUT:
            errorMsg = "Ein unerwartetes Signal ist eingegangen!\n";
            printStdout(errorMsg);
            break;
        case STACK_INITILASITION_FAILED:
            errorMsg = "Stack konnte nicht initialisiert werden!\n Das Programm wird beendet!\n";
            printStdout(errorMsg);
            return EXIT;
            break;
        case STACK_NOT_INITALISED:
            errorMsg = "Stack wurde nicht initialisiert!\n Das Programm wird beendet!\n";
            printStdout(errorMsg);
            return EXIT;
            break;
        default:
            errorMsg = "Unbekannter errorCode!\n Das Programm wird beendet!\n";
            return EXIT;
    }
    while(true){
        T_token input = nextToken();
        if(input.tok == 'C'){
            //evtl. clear command
            break;
        }
    }
    return EOK;
}