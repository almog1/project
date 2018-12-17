//

#ifndef PROGECT_EXPRESSION_H
#define PROGECT_EXPRESSION_H

using namespace std;

#include <map>

/**
 * Expression - responsebale for ecpression
 * Represent an expression
 * Methods that associate for every expression that exist .
 */
class Expression {
public:
    virtual double calculate(map<string,double> symbolTable) = 0;
};


#endif //PROGECT_EXPRESSION_H
