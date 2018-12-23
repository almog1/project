//
// Created by almogg on 12/23/18.
//

#include "SymbolTable.h"

SymbolTable *SymbolTable::instance = nullptr;

SymbolTable::SymbolTable() {

}

SymbolTable *SymbolTable::getInstance() {
    //if null - create new one
    if (instance == nullptr) {
        instance = new SymbolTable();
    }
    return instance;
}

void SymbolTable::addValue(string varName, double value) {
    //check if already in map - change its value
    //else- insert as pair
    map<string, double > ::iterator it;
    it = this->symbolTable.find(varName);

    if(it != this->symbolTable.end()){
        //exist - need to update the value
        this->symbolTable[varName] = value;
    }else{
        //if not exist - need to add the pair
        this->symbolTable.insert(pair<string, double>(varName,value));
    }
}

map<string,double >* SymbolTable::getSymbolTable() {
    return &this->symbolTable;
}