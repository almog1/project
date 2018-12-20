
#include "Div.h"

/**
 *
 * @param leftExp the left expression
 * @param rightExp the right expression
 * build a div expression with right and left side
 */
Div::Div(Expression *leftExp, Expression *rightExp) : BinaryExpression(leftExp, rightExp) {}

/**
 *
 * @param symbolTable the table that contains all the variables
 * @return the calclation of the div expression
 */
double Div::calculate(map<string,double> symbolTable) {
    return (this->getLeftExp()->calculate(symbolTable) / this->getRightExp()->calculate(symbolTable));
}
