//
// Created by almogg on 12/17/18.
//

#ifndef PROGECT_MULT_H
#define PROGECT_MULT_H

#include "BinaryExpression.h"

class Mult : public BinaryExpression{
public:
    Mult(Expression *leftExp, Expression *rightExp);

    double calculate(map<string,double> symbolTable) override;
};
#endif //PROGECT_MULT_H
