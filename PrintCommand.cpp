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

    string str;
    //take the first and second
    //check if string
    if(data[index+1].at(0) == '"'){
        this->printStr = data[index + 1].substr(1,data[index+1].size()-2);
    }else{
        //expression
        str = data[index+1];
        str = putSpaces(str);
        Expression * printExp = evaluate(str);
        this->printStr = to_string(printExp->calculate());
    }

    //read the command name and the var of it - num of time for sleeping
    return 2;
}

void PrintCommand::doCommand() {
    cout << this->printStr << endl;
}
