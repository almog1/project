//
// Created by almogg on 12/17/18.
//

#include "Div.h"

Div::Div(Expression *leftExp, Expression *rightExp) : BinaryExpression(leftExp, rightExp) {}

double Div::calculate(map<string,double> symbolTable) {
    return (this->getLeftExp()->calculate(symbolTable) / this->getRightExp()->calculate(symbolTable));
}
