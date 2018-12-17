//
// Created by almogg on 12/17/18.
//

#include "Number.h"

double Number::calculate(map<string, double> symbolTable) {
    return this->value;
}

Number::Number(double value) : value(value) {}
