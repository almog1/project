//
// Created by almogg on 12/17/18.
//

#ifndef PROGECT_PLUS_H
#define PROGECT_PLUS_H

#include "BinaryExpression.h"

class Plus : public BinaryExpression {
public:
    double calculate(map<string, double> symbolTable) override;

    Plus(Expression *leftExp, Expression *rightExp);
};

#endif //PROGECT_PLUS_H
