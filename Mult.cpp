
#include "Mult.h"

/**
 *
 * @param symbolTable the table that contains all the variables
 * @return the calclation of the mult expression
 */
double Mult::calculate(map<string,double> symbolTable) {
    return (this->getLeftExp()->calculate(symbolTable) * this->getRightExp()->calculate(symbolTable));
}

/**
 *
 * @param leftExp the left expression
 * @param rightExp the right expression
 * build a mult expression with right and left side
 */
Mult::Mult(Expression *leftExp, Expression *rightExp) : BinaryExpression(leftExp, rightExp) {}
