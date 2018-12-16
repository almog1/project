//

#ifndef PROGECT_EXPRESSION_H
#define PROGECT_EXPRESSION_H

using namespace std;

#include "Var.h"
#include <map>

/**
 * Expression - responsebable for ecpression
 * Represent an expression
 * Methods that associate for every expression that exist .
 */
class Expression {
public:

    /* Evaluate the expression using the variable values provided and return the result .
     */
    virtual double calculate(map<double, Var *> symbolTable);

    virtual Expression assign()

};


#endif //PROGECT_EXPRESSION_H
