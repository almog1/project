//
// Created by almogg on 12/18/18.
//

#ifndef PROGECT_COMMANDEXPRESSION_H
#define PROGECT_COMMANDEXPRESSION_H

#include "Expression.h"
#include "Command.h"

class CommandExpression : public Expression {
protected:
    Command *command;
public:
    CommandExpression(Command *command);

    virtual double calculate(map<string, double> symbolTable);

    Command *getCommand() const;
};


#endif //PROGECT_COMMANDEXPRESSION_H
