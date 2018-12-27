//
// Created by chagit on 12/25/18.
//

#include <cstring>
#include <unistd.h>
#include <iostream>
#include "equalsCommand.h"
#include "OtherFunctions.h"
#include "expressionDetect.h"


/**
 * defaul constructor
 */
equalsCommand::equalsCommand() {}

/**
 *
 * @param data the vector that contains all the data
 * @param index the index
 * @return how muck we need to move for the next command
 */
int equalsCommand::setParameters(vector<string> data, int index) {

    this->varTarget = data[index];
    //take the first and second
    //put spaces in the string
    string valStr = putSpaces(data[index + 1]);
    Expression *valExp = evaluate(valStr);
    this->value = (valExp->calculate());

    //read the command name and the var of it
    return 3;
}

/**
 * runs the command
 */
void equalsCommand::doCommand() {
    SymbolTable *symbolTab = SymbolTable::getInstance();
    //update the value in the symbol map
    symbolTab->addSymbolValue(varTarget, value);
    //getting the path of the var
    string path = symbolTab->getVarPath(varTarget);

    string message = "set "+ path + " " + to_string(value) + "\r\n";
    //sending message to the simulator
   // sendMessage(message);
   ThreadsendMessage(message);
   //enter to the table
}


void equalsCommand::ThreadsendMessage(string str){
    SymbolTable *table = SymbolTable::getInstance();
    int sockfd = table->getClientId();
    struct MyParams *params = new MyParams();
    params->clientId = sockfd;
    params->message = str;

    pthread_t threadId;
    pthread_create(&threadId, nullptr, sendMessage,params);
    pthread_join(threadId, nullptr);
}

void* equalsCommand::sendMessage(void* arg) {
    struct MyParams *params = (struct MyParams *) arg;
    SymbolTable *table = SymbolTable::getInstance();
    int sockfd = params->clientId;
    string str = params->message;

    char *s = const_cast<char *>(str.c_str());
    //send message to the server

    int n = ::write(sockfd, s, strlen(s));
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    cout << str << endl;
    cout << s << endl;
}
/*
void equalsCommand::sendMessage(string str) {
    SymbolTable *table = SymbolTable::getInstance();
    int sockfd = table->getClientId();
    char *s = const_cast<char *>(str.c_str());
    //send message to the server

    int n = ::write(sockfd, s, strlen(s));
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }
    cout << "SEND" << endl;
    cout<<"THIS IS MESSAGE AFTER SEND "<<endl;

    cout << str << endl;
    cout << s << endl;
}
*/