//
// Created by chagit on 12/17/18.
//

#ifndef PROGECT_COMMAND_H
#define PROGECT_COMMAND_H

#include <vector>
#include <string>
#include <map>

using namespace std;

class Command {
protected:
    map<string, double> symbolTable;
public:
    Command() {
        symbolTable.insert(pair<string, double>("x", 2));
        symbolTable.insert(pair<string, double>("y", 4));
    }

    virtual int doCommand(vector<string> , int index) = 0;
};

#endif //PROGECT_COMMAND_H
