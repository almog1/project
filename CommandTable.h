//
// Created by almogg on 12/23/18.
//

#ifndef PROGECT_COMMANDTABLE_H
#define PROGECT_COMMANDTABLE_H
#include <map>
#include <string>
#include "CommandExpression.h"

using namespace std;

class CommandTable {
private:
    static CommandTable *instance;

    CommandTable();

    map<string, Expression*> commandTable;
public:
    static CommandTable *getInstance();

    void addValue(string commandName, Expression* exp);

    map<string, Expression*> getTable();

};

#endif //PROGECT_COMMANDTABLE_H
