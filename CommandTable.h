//
// Created by almogg on 12/23/18.
//

#ifndef PROGECT_COMMANDTABLE_H
#define PROGECT_COMMANDTABLE_H
#include <map>
#include <string>
#include "CommandExpression.h"
#include "LoopCommand.h"

using namespace std;

/**
 * CommandTable Class
 *
 */
class CommandTable {
private:
    static CommandTable *instance;
    map<string, Expression*> commandTable;
    vector<Expression*> allExp;

public:
    CommandTable();

    ~CommandTable();

    static CommandTable *getInstance();

    void addValue(string commandName, Expression *exp);

    map<string, Expression*> getTable();

    void setMapValues();

};

#endif //PROGECT_COMMANDTABLE_H
