//
// Created by almogg on 12/23/18.
//

#include <iostream>
#include "SymbolTable.h"

SymbolTable *SymbolTable::instance = nullptr;

SymbolTable::SymbolTable() {
    pthread_mutex_init(&mutex, nullptr);
    this->names = {"/instrumentation/airspeed-indicator/indicated-speed-kt",
                   "/instrumentation/altimeter/indicated-altitude-ft",
                   "/instrumentation/altimeter/pressure-alt-ft",
                   "/instrumentation/attitude-indicator/indicated-pitch-deg",
                   "/instrumentation/attitude-indicator/indicated-roll-deg",
                   "/instrumentation/attitude-indicator/internal-pitch-deg",
                   "/instrumentation/attitude-indicator/internal-roll-deg",
                   "/instrumentation/encoder/indicated-altitude-ft",
                   "/instrumentation/encoder/pressure-alt-ft", "/instrumentation/gps/indicated-altitude-ft",
                   "/instrumentation/gps/indicated-ground-speed-kt",
                   "/instrumentation/gps/indicated-vertical-speed",
                   "/instrumentation/heading-indicator/indicated-heading-deg",
                   "/instrumentation/heading-indicator/indicated-heading-deg",
                   "/instrumentation/slip-skid-ball/indicated-slip-skid",
                   "/instrumentation/turn-indicator/indicated-turn-rate",
                   "/instrumentation/vertical-speed-indicator/indicated-speed-fpm",
                   "/controls/flight/aileron", "/controls/flight/elevator", "/controls/flight/rudder",
                   "/controls/flight/flaps", "/controls/engines/current-engine/throttle", "/engines/engine/rpm"};

}

SymbolTable *SymbolTable::getInstance() {
    //if null - create new one
    if (instance == nullptr) {
        instance = new SymbolTable();
    }
    return instance;
}



void SymbolTable::addSymbolValue(string varName, double value) {
    //check if already in map - change its value
    //else- insert as pair

    //check if have path
    map<string, string>::iterator it;
    it = this->varPathTable.find(varName);
    //have path - take from pathDouble
    if (it != this->varPathTable.end()) {
        pthread_mutex_lock(&mutex);
        this->pathDouble[it->second] = value;
        pthread_mutex_unlock(&mutex);
    }else{
        //not have path
        //put in symbol table
        map<string, double>::iterator iter;
        iter = this->symbolTable.find(varName);
        if(iter!=this->symbolTable.end()){
            this->symbolTable[varName] = value;
        }else{
            //if not exist - need to add the pair
            this->symbolTable.insert(pair<string, double>(varName, value));
        }
    }

}

//return the value of this var
double SymbolTable::getValue(string varName) {
    double num;
    pthread_mutex_lock(&mutex);

    //check if it in have path
    map<string, string>::iterator it;
    it = this->varPathTable.find(varName);
    //have path - take from pathDouble
    if (it != this->varPathTable.end()) {
        num = this->pathDouble[it->second];
    }else{
        //not from the var path - need from symbol table
        num = this->symbolTable.find(varName)->second;
    }
    //return the value of this var Name
    pthread_mutex_unlock(&mutex);
    return num;
}

//map<string, double> *SymbolTable::getSymbolTable() {
//    return &this->symbolTable;
//}

//add path to the var name - if exist - replace the path
void SymbolTable::addPathToVar(string varName, string path) {
    map<string, string>::iterator it;
    it = this->varPathTable.find(varName);

    if (it != this->varPathTable.end()) {
        //exist - need to update the value
        this->varPathTable[varName] = path;
    } else {
        //if not exist - need to add the pair
        this->varPathTable.insert(pair<string, string>(varName, path));
    }

    //cout << "Added to path var " << this->varPathTable[varName] << endl;
}

void SymbolTable::addValueByPathIndex(int index, double val) {
    //take the name in this place
    string path = this->names[index];

    //check if the path exist
    map<string, double>::iterator it;
    it = this->pathDouble.find(path);
    pthread_mutex_lock(&mutex);
    if (it != this->pathDouble.end()) {
        //exist - need to update the value
        this->pathDouble[path] = val;
    } else {
        //if not exist - need to add the pair
        this->pathDouble.insert(pair<string, double>(path, val));
    }
   pthread_mutex_unlock(&mutex);

}

void SymbolTable::setValuesInSymbolTable() {
    map<string, string>::iterator it;
    string varName = "";
    string varPath = "";
    double val;

    //cout << "VALUES IN MAP FUNCTION" << endl;
    if (this->varPathTable.empty() == false) {
        for (it = this->varPathTable.begin(); it != this->varPathTable.end(); ++it) {
            varName = it->first;
            varPath = it->second;

            map<string, double>::iterator iter;
            iter = this->pathDouble.find(varPath);
            //check if exist in the map
            if (iter != this->pathDouble.end()) {
                val = iter->second;
                //update it in the symbol table map
                //this->addSymbolValue(varName, val);
                map<string, double>::iterator it;
                it = this->symbolTable.find(varName);

                if (it != this->symbolTable.end()) {
                    //exist - need to update the value
                    this->symbolTable[varName] = val;
                } else {
                    //if not exist - need to add the pair
                    this->symbolTable.insert(pair<string, double>(varName, val));
                }
            }
        }
    }
    //it->first << " => " << it->second << '\n';
}

string SymbolTable::getVarPath(string varName) {
    map<string, string>::iterator it;
    string varPath = "";

    it = this->varPathTable.find(varName);

    if (it != this->varPathTable.end()) {
        //if exist - return its value - the path
        varPath = it->second; //the real path
    }
    return varPath;
}

/**
 *
 * @param val a specific var
 * @return 'true' if the var exist in the map and 'false' otherwise
 */
bool SymbolTable::isValExist(string var) {

    bool isExist = false;
    map<string, string>::iterator it;
    it = this->varPathTable.find(var);
    if (it != this->varPathTable.end()) {
        isExist = true;
    }

    return isExist;
}

void SymbolTable::setClientId(int clientId) {
    this->clientId = clientId;
}

int SymbolTable::getClientId() const {
    return clientId;
}

void SymbolTable::setServerId(int serverId) {
    SymbolTable::serverId = serverId;
}

int SymbolTable::getServerId() const {
    return serverId;
}

bool SymbolTable::isConnect() const {
    return connect;
}

void SymbolTable::setConnect(bool connect) {
    SymbolTable::connect = connect;
}

const vector<string> &SymbolTable::getNames() const {
    return names;
}

bool SymbolTable::isServer() const {
    return server;
}

void SymbolTable::setServer(bool server) {
    SymbolTable::server = server;
}

SymbolTable::~SymbolTable() {
    delete instance;
}