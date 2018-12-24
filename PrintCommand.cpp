//
// Created by chagit on 12/24/18.
//

#include <iostream>
#include "PrintCommand.h"
#include "SymbolTable.h"

PrintCommand::PrintCommand() {
    //todo check if we need to write something here
}

int PrintCommand::setParameters(vector<string> data, int index) {
    SymbolTable *symbolTab = SymbolTable::getInstance();

    //take the first and second
    //put spaces in the sleep string
    string sleepStr = putSpaces(data[index + 1]);
    Expression *sleepExp = evaluate(sleepStr);
    this->printStr = (int) (sleepExp->calculate());

    //read the command name and the var of it - num of time for sleeping
    return 2;
}

void PrintCommand::doCommand() {
    cout << this->printStr << endl;
}
