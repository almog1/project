//
// Created by almogg on 12/18/18.
//

#include "CommandExpression.h"

double CommandExpression::calculate(map<string, double> symbolTable) {
    this->command->doCommand();
    //todo need to return double
}

CommandExpression::CommandExpression(Command *command) : command(command) {}

Command *CommandExpression::getCommand() const {
    return command;
}
