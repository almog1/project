//
// Created by chagit on 12/24/18.
//

#include <iostream>
#include "PrintCommand.h"
#include "SymbolTable.h"

PrintCommand::PrintCommand() {
}

int PrintCommand::setParameters(vector<string> data, int index) {
    SymbolTable *symbolTab = SymbolTable::getInstance();

    //take the first and second
    //put spaces in the sleep string
    string temp=data[index + 1].substr(1,data[index+1].size()-2);
    string sleepStr = putSpaces(temp);
    Expression *sleepExp = evaluate(sleepStr);
    this->printStr = (int) (sleepExp->calculate());

    //read the command name and the var of it - num of time for sleeping
    return 2;
}

void PrintCommand::doCommand() {
    cout << this->printStr << endl;
}
