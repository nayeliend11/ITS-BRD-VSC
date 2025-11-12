#ifndef __ERROR_H__
#define __ERROR_H__

#define EOK 0
#define STACK_OVERFLOW -1
#define STACK_UNDERFLOW -2
#define NUMBER_OVERFLOW -3
#define NUMBER_UNDERFLOW -4
#define DIVISION_WITH_ZERO -5
#define UNEXPECTED_INPUT -6
#define STACK_INITILASITION_FAILED -7
#define STACK_NO_ARRAY -8
#define EXIT -9
#define NO_STACK -10
#define NO_VALUE -11
#define INDEX_OUT_OF_BOUND -12
#define STACK_SIZE_INVALID -13

int error_handler(int errorCode);

#endif
//eof