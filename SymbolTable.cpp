//
// Created by almogg on 12/23/18.
//

#include "SymbolTable.h"

SymbolTable *SymbolTable::instance = nullptr;

SymbolTable::SymbolTable() {
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
                             "/instrumentation/magnetic-compass/indicated-heading-deg",
                             "/instrumentation/slip-skid-ball/indicated-slip-skid",
                             "/instrumentation/turn-indicator/indicated-turn-rate",
                             "/instrumentation/vertical-speed-indicator/indicated-speed-fpm",
                             "/controls/flight/aileron", "/controls/flight/elevator", "/controls/flight/rudder",
                             "/controls/flight/flaps", "/controls/engines/engine/throttle", "/engines/engine/rpm"};

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
    map<string, double>::iterator it;
    it = this->symbolTable.find(varName);

    if (it != this->symbolTable.end()) {
        //exist - need to update the value
        this->symbolTable[varName] = value;
    } else {
        //if not exist - need to add the pair
        this->symbolTable.insert(pair<string, double>(varName, value));
    }
}

//return the value of this var
double SymbolTable::getValue(string varName) {
    //return the value of this var Name
    return this->symbolTable.find(varName)->second;
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
}

void SymbolTable::addValueByPathIndex(int index, double val) {
    //take the name in this place
    string path = this->names[index];

    //check if the path exist
    map<string, double >::iterator it;
    it = this->pathDouble.find(path);

    if (it != this->pathDouble.end()) {
        //exist - need to update the value
        this->pathDouble[path] = val;
    } else {
        //if not exist - need to add the pair
        this->pathDouble.insert(pair<string, double >(path, val));
    }
}

