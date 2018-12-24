//
// Created by almogg on 12/18/18.
//

#include "ConnectCommand.h"
#include "Expression.h"
#include "Parser.h"
#include "expressionDetect.h"
#include "OtherFunctions.h"
#include "ClientSocket.h"

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

/**
 * a defult constructor
 */
ConnectCommand::ConnectCommand() {
    //initilize the values
    this->port = 0;
    this->ip = "";
}

/**
 *
 * @param data a vector witch contains all the words from the script (command and values - expression)
 * @param index - points on a place in the data vector
 * @return how much we need to move on the array (the num of values for a specific command)
 */
int ConnectCommand::setParameters(vector<string> data, int index) {
    this->ip = data[index + 1];
    string portStr = putSpaces(data[index + 2]);
    Expression *portExp = evaluate(portStr);
    this->port = (int) (portExp->calculate(this->symbolTable));

    //read connect command name and two arguments
    return 3;
}

/**
 * run the connect command
 */
void ConnectCommand::doCommand() {
    struct MyParams *params = new MyParams();
    params->port = this->port;
    params->ip = this->ip;

    pthread_t id;
    pthread_create(&id, nullptr, ClientSocket::openSocket, params);
}