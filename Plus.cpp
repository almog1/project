//
// Created by almogg on 12/17/18.
//

#include "Plus.h"

Plus::Plus(Expression *leftExp, Expression *rightExp) : BinaryExpression(leftExp, rightExp) {}

double Plus::calculate(map<string,double> symbolTable) {
    return (this->getLeftExp()->calculate(symbolTable) + this->getRightExp()->calculate(symbolTable));
}
