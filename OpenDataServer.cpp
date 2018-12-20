
#include "OpenDataServer.h"
#include "Parser.h"
#include "Expression.h"
#include "expressionDetect.h"
#include "OtherFunctions.h"

/**
 * a defult constructor
 */
OpenDataServer::OpenDataServer() {
    //initilize the values
    this->port = 0;
    this->hz = 0;
}

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
 * run the command
 */
void OpenDataServer::doCommand() {
    //todo need to Open The Server

    struct MyParams* params = new MyParams();
    params->port = this->port;
    params->hz = this->hz;

    pthread_t id;
    pthread_create(&id, nullptr, ServerSocket::openSocket, params);


}

/**
 *
 * @param data a vector witch contains all the words from the script (command and values - expression)
 * @param index - points on a place in the data vector
 * @return how much we need to move on the array (the num of values for a specific command)
 */
int OpenDataServer::setParameters(vector<string> data, int index) {
    //take the first and second
    //put spaces in the port string
    string portStr = putSpaces(data[index + 1]);
    Expression *portExp = evaluate(portStr);
    this->port = (int) (portExp->calculate(this->symbolTable));

    string hzStr = putSpaces(data[index + 2]);
    Expression *hzExp = evaluate(hzStr);
    this->hz = (int) (hzExp->calculate(this->symbolTable));

    //read the command name and two arguments
    return 3;
}