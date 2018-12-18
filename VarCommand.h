//
// Created by almogg on 12/18/18.
//

#ifndef PROGECT_VARCOMMAND_H
#define PROGECT_VARCOMMAND_H

#include "Command.h"

class VarCommand : public Command {
public:
    int setParameters(vector<string> data, int index) override;

    void doCommand() override;

};

#endif //PROGECT_VARCOMMAND_H
