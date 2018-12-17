//
// Created by almogg on 12/17/18.
//

#include "BinaryExpression.h"

Expression *BinaryExpression::getRightExp() const {
    return this->rightExp;
}

Expression *BinaryExpression::getLeftExp() const {
    return this->leftExp;
}

BinaryExpression::BinaryExpression(Expression *leftExp, Expression *rightExp) {
    this->leftExp = leftExp;
    this->rightExp = rightExp;
}
