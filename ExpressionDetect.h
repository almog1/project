//
// Created by chagit on 12/17/18.
//

#ifndef PROGECT_EXPRESSIONDETECT_H
#define PROGECT_EXPRESSIONDETECT_H

#include <list>
#include "ExpressionHeaders.h"
#include "OtherFunctions.h"

class ExpressionDetect {
    list<Expression *> listOfVars;
public:
    ExpressionDetect();

    Expression *applyOp(Expression *a, Expression *b, char op);

    int precedence(char op);

    Expression *evaluate(string tokens);

    virtual ~ExpressionDetect();


};


#endif //PROGECT_EXPRESSIONDETECT_H
