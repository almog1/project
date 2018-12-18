//
// Created by almogg on 12/18/18.
//

#include "OpenDataServer.h"
#include "Parser.h"
#include "Expression.h"
#include "expressionDetect.h"

int OpenDataServer::getPort() const {
    return port;
}

void OpenDataServer::setPort(int port) {
    OpenDataServer::port = port;
}

int OpenDataServer::getHz() const {
    return hz;
}

void OpenDataServer::setHz(int hz) {
    OpenDataServer::hz = hz;
}

/**
 * Do the command by the values in the data .
 * @param data .vector to read the values from it
 * @return how much arguments been readed
 */
int OpenDataServer::doCommand(vector<string> data) {
    //take the first and second
    Parser prs;
    //put spaces in the port string
    // todo change the parser to just function
    string portStr = prs.putSpaces(data[1]);
    Expression* portExp = evaluate(portStr);
    this->port = (int) (portExp->calculate(this->symbolTable));

    string hzStr = prs.putSpaces(data[2]);
    Expression* hzExp = evaluate(hzStr);
    this->hz = (int) (hzExp->calculate(this->symbolTable));


    //todo need to Open The Server

    return 2;
}
