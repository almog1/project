//
// Created by chagit on 12/17/18.
//

#ifndef PROGECT_EXPRESSIONDETECT_H
#define PROGECT_EXPRESSIONDETECT_H

#include "ExpressionHeaders.h"

Expression *applyOp(Expression *a, Expression *b, char op);

int precedence(char op);

Expression *evaluate(string tokens);


#endif //PROGECT_EXPRESSIONDETECT_H
