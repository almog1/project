//
// Created by almogg on 12/23/18.
//

#include "CommandTable.h"
#include "OpenDataServer.h"
#include "VarCommand.h"
#include "ConnectCommand.h"
#include "CommandExpression.h"
#include "LoopCommand.h"

#define OPEN_DATA_SERVER "openDataServer"
#define CONNECT "connect"
#define VAR "var"
#define WHILE "while"
#define PRINT "print"
#define EXIT "exit"

CommandTable *CommandTable::instance = nullptr;

CommandTable::CommandTable() {
    this->commandTable.insert(
            pair<string, Expression *>(OPEN_DATA_SERVER, new CommandExpression(new OpenDataServer())));
    this->commandTable.insert(pair<string, Expression *>(CONNECT, new CommandExpression(new ConnectCommand())));
    this->commandTable.insert(pair<string, Expression *>(VAR, new CommandExpression(new VarCommand())));
    this->commandTable.insert(pair<string, Expression*>(WHILE, new CommandExpression(new LoopCommand())));

}

void CommandTable::addValue(string commandName, Expression* exp) {
    //check if already in map - change its value
    //else- insert as pair
    map<string, Expression* > ::iterator it;
    it = this->commandTable.find(commandName);

    if(it != this->commandTable.end()){
        //exist - need to update the value
        this->commandTable[commandName] = exp;
    }else{
        //if not exist - need to add the pair
        this->commandTable.insert(pair<string, Expression*>(commandName,exp));
    }
}

CommandTable* CommandTable::getInstance() {
    //if null - create new one
    if (instance == nullptr) {
        instance = new CommandTable();
    }
    return instance;
}

map<string, Expression*> CommandTable::getTable() {
    return this->commandTable;
}