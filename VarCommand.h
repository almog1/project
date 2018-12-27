//
// Created by almogg on 12/18/18.
//

#ifndef PROGECT_VARCOMMAND_H
#define PROGECT_VARCOMMAND_H

#include "Command.h"
#include "ExpressionHeaders.h"
#include "expressionDetect.h"
#include "PlacementCommand.h"

class VarCommand : public Command {
    bool isBind;
    string var;
    double val;
    string path;

    bool isCommandExist;
    Command* command;
public:
    VarCommand();

    ~VarCommand();

    int setParameters(vector<string> data, int index) override;

    void doCommand() override;

};

#endif //PROGECT_VARCOMMAND_H
