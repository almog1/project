//
// Created by almogg on 12/17/18.
//

#ifndef PROGECT_MINUS_H
#define PROGECT_MINUS_H

#include "BinaryExpression.h"

class Minus : public BinaryExpression{
public:
    double calculate(map<string,double> symbolTable) override;

    Minus(Expression *leftExp, Expression *rightExp);
};
#endif //PROGECT_MINUS_H
