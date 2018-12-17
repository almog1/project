//
// Created by almogg on 12/17/18.
//

#include "Mult.h"

double Mult::calculate(map<string,double> symbolTable) {
    return (this->getLeftExp()->calculate(symbolTable) * this->getRightExp()->calculate(symbolTable));
}

Mult::Mult(Expression *leftExp, Expression *rightExp) : BinaryExpression(leftExp, rightExp) {}
