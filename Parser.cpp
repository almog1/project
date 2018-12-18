//
// Created by almogg on 12/18/18.
//

#include <iostream>
#include "Parser.h"
#include "OpenDataServer.h"
#include "VarCommand.h"
#include "ConnectCommand.h"

#define OPEN_DATA_SERVER "openDataServer"
#define CONNECT "connect"
#define VAR "var"


Parser::Parser() {
    this->commandTable.insert(pair<string, Command *>(OPEN_DATA_SERVER, new OpenDataServer()));
    this->commandTable.insert(pair<string, Command *>(CONNECT, new ConnectCommand()));
    this->commandTable.insert(pair<string, Command *>(VAR, new VarCommand()));
}

void Parser::parser(vector<string> data) {
    //check the data
    vector<string>::iterator it;
    int index = 0;

    while (index<data.size()){
        //vector not empty
        if (data.empty() == false){

            Command *c = (this->commandTable.find(data[index]))->second;
            index += c->doCommand(data, index);

            //todo need to check if everything entered
        }
    }
}


