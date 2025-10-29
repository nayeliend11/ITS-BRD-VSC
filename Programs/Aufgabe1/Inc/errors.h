#ifndef __ERROR_H__
#define __ERROR_H__

#define EOK 0
#define STACK_OVERFLOW -1
#define STACK_UNDERFLOW -2
#define NUMBER_OVERFLOW -3
#define NUMBER_UNDERFLOW -4
#define DIVISION_WITH_ZERO -5
#define UNEXPECTED_INPUT -6

void error_handler(int errorCode);

#endif
//eof