//
// Created by almogg on 12/18/18.
//

#include <iostream>
#include "Parser.h"
#include "OpenDataServer.h"
#include "VarCommand.h"
#include "ConnectCommand.h"
#include "CommandExpression.h"
#include "LoopCommand.h"
#include "CommandTable.h"

#define OPEN_DATA_SERVER "openDataServer"
#define CONNECT "connect"
#define VAR "var"
#define WHILE "while"
#define PRINT "print"
#define EXIT "exit"


Parser::Parser() {
 //   this->commandTable.insert(
   //         pair<string, Expression *>(OPEN_DATA_SERVER, new CommandExpression(new OpenDataServer())));
   // this->commandTable.insert(pair<string, Expression *>(CONNECT, new CommandExpression(new ConnectCommand())));
   // this->commandTable.insert(pair<string, Expression *>(VAR, new CommandExpression(new VarCommand())));
   // this->commandTable.insert(pair<string, Expression*>(WHILE, new CommandExpression(new LoopCommand())));
}

void Parser::parser(vector<string> data) {
    //check the data
    vector<string>::iterator it;
    int index = 0;

    CommandTable *commandTab = CommandTable::getInstance();
    this->commandTable = commandTab->getTable();

    while (index < data.size()) {
        //vector not empty
        if (data.empty() == false) {
            //todo - downcast!!!!!
            map<string, Expression*>::iterator it;

            //need to find the command
            it = this->commandTable.find(data[index]);
            CommandExpression *dataCommand;
            //check if exist
            if(it != this->commandTable.end()){
                 dataCommand = dynamic_cast<CommandExpression *>(it->second);
            }else{
                //its a var name
                //need to go to the VarCommand
                dataCommand = dynamic_cast<CommandExpression *>(this->commandTable.find(VAR)->second);
            }
            index += dataCommand->getCommand()->setParameters(data, index);

            dataCommand->calculate(dataCommand->getCommand()->getSymbolTable());

            //todo need to check if everything entered
        }
    }
}


