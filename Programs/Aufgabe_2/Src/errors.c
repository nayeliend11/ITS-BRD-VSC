#include "errors.h"
#include <stdlib.h>


int error_handler(int errorCode){
    char *errorMsg;
    int returnVal = EOK;
    setErrMode();
    switch (errorCode) {
