//
// Created by almogg on 12/23/18.
//

#ifndef PROGECT_SYMBOLTABLE_H
#define PROGECT_SYMBOLTABLE_H

#include <map>
#include <string>
#include <vector>

using namespace std;

class SymbolTable {
private:
    static SymbolTable *instance;

    SymbolTable();

    map<string, double> symbolTable;
    map<string, string> varPathTable;
    map<string, double > pathDouble;
    vector<string> names;

public:
    static SymbolTable *getInstance();

    void addSymbolValue(string varName, double value);

    void addPathToVar(string varName, string path);

    void addValueByPathIndex(int index, double val);

    double getValue(string varName);

   // map<string,double > *getSymbolTable();


};

#endif //PROGECT_SYMBOLTABLE_H
