#include "errors.h"
#include "display.h"
#include <stdlib.h>

#define LEN_ERR_MSG 256

void error_handler(int errorCode){
    char *errorMsg;
    setErrMode();
    switch (errorCode) {
        case STACK_OVERFLOW:
        break;
        case STACK_UNDERFLOW:
        break;
        case NUMBER_OVERFLOW:
        break;
        case NUMBER_UNDERFLOW:
        break;
        case DIVISION_WITH_ZERO:
            break;
        case UNEXPECTED_INPUT:
            break;
        case STACK_INITILASITION_FAILED:
            break;
        case STACK_NOT_INITALISED:
            errorMsg = "Stack wurde nicht initialisiert. Das Programm wird beendet";
            printStdout(errorMsg);
            exit(errorCode);
            break;
        default:
            errorMsg = "Unbekannter errorCode. Das Programm wird beendet";
    }
    return;
}