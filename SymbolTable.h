//
// Created by almogg on 12/23/18.
//

#ifndef PROGECT_SYMBOLTABLE_H
#define PROGECT_SYMBOLTABLE_H

#include <map>
#include <string>

using namespace std;

class SymbolTable {
private:
    static SymbolTable *instance;

    SymbolTable();

    map<string, double> symbolTable;
public:
    static SymbolTable *getInstance();

    void addValue(string varName, double value);

    map<string,double > *getSymbolTable();
};

#endif //PROGECT_SYMBOLTABLE_H
