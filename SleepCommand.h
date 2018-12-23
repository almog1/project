//
// Created by chagit on 12/23/18.
//

#ifndef PROGECT_SLEEPCOMMAND_H
#define PROGECT_SLEEPCOMMAND_H

#include "Command.h"
#include "ExpressionHeaders.h"
#include "expressionDetect.h"
#include "ExpressionHeaders.h"
#include "OtherFunctions.h"
#include "unistd.h"


/**
 * SleepCommand Class
 * the class who runs the sleep command
 */
class SleepCommand : public Command {
    int sleepTime;
public:
    /**
     * constructor
     */
    SleepCommand();

    /**
     *
     * @param data
     * @param index
     * @return
     */
    int setParameters(vector<string> data, int index) override;

    /**
     * run the sleep command
     */
    void doCommand() override;

};

#endif //PROGECT_SLEEPCOMMAND_H
