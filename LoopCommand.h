//
// Created by almogg on 12/22/18.
//

#ifndef PROGECT_LOOPCOMMAND_H
#define PROGECT_LOOPCOMMAND_H

#include "Command.h"
#include "ExpressionHeaders.h"
#include "expressionDetect.h"
#include "OtherFunctions.h"

class LoopCommand : public Command {
protected:
    Expression *leftExp;
    Expression *rightExp;
    string condition;
public:
    int setParameters(vector<string> data, int index) override;

    void doCommand() override;
};

#endif //PROGECT_LOOPCOMMAND_H
