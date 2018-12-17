//
// Created by almogg on 12/17/18.
//

#include "Minus.h"

double Minus::calculate(map<string, double> symbolTable) {
    return (this->getLeftExp()->calculate(symbolTable) - this->getRightExp()->calculate(symbolTable));

}

Minus::Minus(Expression *leftExp, Expression *rightExp) : BinaryExpression(leftExp, rightExp) {}

