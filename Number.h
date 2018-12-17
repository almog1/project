//
// Created by almogg on 12/17/18.
//

#ifndef PROGECT_NUMBER_H
#define PROGECT_NUMBER_H

#include "Expression.h"

class Number : public Expression {
private:
    double value;
public:
    explicit Number(double value);

    double calculate(map<string, double> symbolTable) override;
};

#endif //PROGECT_NUMBER_H
