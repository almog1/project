//
// Created by almogg on 12/17/18.
//

#ifndef PROGECT_DIV_H
#define PROGECT_DIV_H

#include "BinaryExpression.h"

class Div : public BinaryExpression{
public:
    Div(Expression *leftExp, Expression *rightExp);

    double calculate(map<string,double> symbolTable) override;
};

#endif //PROGECT_DIV_H
