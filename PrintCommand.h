//
// Created by chagit on 12/24/18.
//

#ifndef PROGECT_PRINTCOMMAND_H
#define PROGECT_PRINTCOMMAND_H


#include "Command.h"
#include "ExpressionHeaders.h"
#include "ExpressionDetect.h"
#include "ExpressionHeaders.h"
#include "OtherFunctions.h"
#include "unistd.h"
#include <string>

using namespace std;

/**
 * PrintCommand Class
 * runs the print command
 */
class PrintCommand : public Command {
    string printStr;

public:
    PrintCommand();

    int setParameters(vector<string> data, int index) override;

    void doCommand() override;
};

#endif //PROGECT_PRINTCOMMAND_H
