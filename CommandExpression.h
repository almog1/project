
#ifndef PROGECT_COMMANDEXPRESSION_H
#define PROGECT_COMMANDEXPRESSION_H

#include "Expression.h"
#include "Command.h"

/**
 * CommandExpression Class
 * the class that connect between command and expression
 */
class CommandExpression : public Expression {
protected:
    //contains a variable type command
    Command *command;
public:
    /**
     *
     * @param command pointer to a specific command
     */
    CommandExpression(Command *command);

    /**
     *
     * @param symbolTable the table that contains all the variables in the program
     * @return the calculation of the expression
     */
    virtual double calculate(map<string, double> symbolTable);

    /**
     *
     * @return the command
     */
    Command *getCommand() const;
};


#endif //PROGECT_COMMANDEXPRESSION_H
