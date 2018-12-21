
#include "Neg.h"

Neg::Neg(Expression *expression) : UnaryExpression(expression) {}

double Neg::calculate(map<string, double> symbolTable) {
    return (this->expression->calculate(symbolTable) * (-1));
}
