//
// Created by almogg on 12/18/18.
//

#include "ConnectCommand.h"
#include "Expression.h"
#include "Parser.h"
#include "expressionDetect.h"
#include "OtherFunctions.h"

int ConnectCommand::doCommand(vector<string> data) {
    this->ip = data[4];
    string portStr = putSpaces(data[5]);
    Expression *portExp = evaluate(portStr);
    this->port = (int) (portExp->calculate(this->symbolTable));

    //todo connect by IP

    //read connect command name and two arguments
    return 3;
}

const string &ConnectCommand::getIp() const {
    return ip;
}

void ConnectCommand::setIp(const string &ip) {
    ConnectCommand::ip = ip;
}

int ConnectCommand::getPort() const {
    return port;
}

void ConnectCommand::setPort(int port) {
    ConnectCommand::port = port;
}

ConnectCommand::ConnectCommand() {
    //initilize the values
    this->port = 0;
    this->ip = "";
}
