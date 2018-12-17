//
// Created by almogg on 12/16/18.
//

#include "Expression.h"

Expression::Expression(Expression *leftExp, Expression *rightExp) : leftExp(leftExp), rightExp(rightExp) {}

Expression *Expression::getLeftExp() const {
    return leftExp;
}

void Expression::setLeftExp(Expression *leftExp) {
    Expression::leftExp = leftExp;
}

Expression *Expression::getRightExp() const {
    return rightExp;
}

void Expression::setRightExp(Expression *rightExp) {
    Expression::rightExp = rightExp;
}
