
#include "Minus.h"

/**
 *
 * @param symbolTable the table that contains all the variables
 * @return the calclation of the minus expression
 */
double Minus::calculate(map<string, double> symbolTable) {
    return (this->getLeftExp()->calculate(symbolTable) - this->getRightExp()->calculate(symbolTable));
}

/**
 *
 * @param leftExp the left expression
 * @param rightExp the right expression
 * build a minus expression with right and left side
 */
Minus::Minus(Expression *leftExp, Expression *rightExp) : BinaryExpression(leftExp, rightExp) {}

