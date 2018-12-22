//
// Created by almogg on 12/22/18.
//

#ifndef PROGECT_LOOPCOMMAND_H
#define PROGECT_LOOPCOMMAND_H

#include "Command.h"

class LoopCommand : public Command {
public:
    int setParameters(vector<string> data, int index) override;

    void doCommand() override;
};

#endif //PROGECT_LOOPCOMMAND_H
