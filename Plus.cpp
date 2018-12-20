
#include "Plus.h"
/**
 *
 * @param leftExp the left expression
 * @param rightExp the right expression
 * build a plus expression with right and left side
 */
Plus::Plus(Expression *leftExp, Expression *rightExp) : BinaryExpression(leftExp, rightExp) {
}

/**
 *
 * @param symbolTable the table that contains all the variables
 * @return the calclation of the plus expression
 */
double Plus::calculate(map<string, double> symbolTable) {
    return (this->getLeftExp()->calculate(symbolTable) + this->getRightExp()->calculate(symbolTable));
}


