//
// Created by almogg on 12/17/18.
//

#include "Pow.h"
#include <cmath>
Pow::Pow(Expression *leftExp, Expression *rightExp) : BinaryExpression(leftExp, rightExp) {}

double Pow::calculate(map<string,double> symbolTable) {
    return (pow(this->getLeftExp()->calculate(symbolTable),this->getRightExp()->calculate(symbolTable)));
}
