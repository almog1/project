//
// Created by almogg on 12/30/18.
//

#ifndef PROGECT_EXITCOMMAND_H
#define PROGECT_EXITCOMMAND_H

#include "Command.h"

class ExitCommand: public Command{
public:
    ExitCommand();

    ~ExitCommand();

    int setParameters(vector<string> data, int index) override;

    void doCommand() override;
};
#endif //PROGECT_EXITCOMMAND_H
