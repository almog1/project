//
// Created by almogg on 12/17/18.
//

#ifndef PROGECT_BINARYEXPRESSION_H
#define PROGECT_BINARYEXPRESSION_H

#include "Expression.h"

class BinaryExpression : public Expression {
protected:
    Expression *leftExp;
    Expression *rightExp;
public:
    BinaryExpression(Expression *leftExp, Expression *rightExp);

    Expression *getLeftExp() const;
    Expression *getRightExp() const;

    /* Evaluate the expression using the variable values provided and return the result .
     */
    virtual double calculate(map<string,double> symbolTable) = 0;

};

#endif //PROGECT_BINARYEXPRESSION_H
