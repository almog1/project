//
// Created by almogg on 12/17/18.
//

#ifndef PROGECT_MINUS_H
#define PROGECT_MINUS_H

#include "BinaryExpression.h"

class Minus : public BinaryExpression{
public:
    Minus(Expression *leftExp, Expression *rightExp);

    double calculate(map<string,double> symbolTable) override;

};
#endif //PROGECT_MINUS_H
