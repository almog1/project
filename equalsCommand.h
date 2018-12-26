//
// Created by chagit on 12/25/18.
//

#ifndef PROGECT_EQUALSCOMMAND_H
#define PROGECT_EQUALSCOMMAND_H

#include "Command.h"
#include "SymbolTable.h"

class equalsCommand : public Command {
    string ip;
    string varTarget;
    double value;

public:
    equalsCommand();

    void sendMessage(string str);

    int setParameters(vector<string> data, int index) override;

    void doCommand() override;

};

#endif //PROGECT_EQUALSCOMMAND_H
