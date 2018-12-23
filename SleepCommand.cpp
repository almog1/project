//
// Created by chagit on 12/23/18.
//

#include "SleepCommand.h"

//todo check if we need to do something
SleepCommand::SleepCommand() {

}

int SleepCommand::setParameters(vector<string> data, int index) {
    //take the first and second
    //put spaces in the sleep string
    string sleepStr = putSpaces(data[index + 1]);
    Expression *sleepExp = evaluate(sleepStr);
    this->sleepTime = (int) (sleepExp->calculate(this->symbolTable));

    //read the command name and the var of it - num of time for sleeping
    return 2;
}

void SleepCommand::doCommand() {
    //sleep the program according to the variable that we get
    sleep(this->sleepTime);
}
