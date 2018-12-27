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
    int clientId = -1;
    int serverId = -1;
    bool connect = true;
    bool server = true;

private:
    static SymbolTable *instance;

    SymbolTable();

    map<string, double> symbolTable;
    map<string, string> varPathTable;
    map<string, double> pathDouble;
    vector<string> names;
    pthread_mutex_t *mutex;

public:
    void setServerId(int serverId);

    static SymbolTable *getInstance();

    void addSymbolValue(string varName, double value);

    void addPathToVar(string varName, string path);

    void addValueByPathIndex(int index, double val);

    double getValue(string varName);

    string getVarPath(string varName);

    void setValuesInSymbolTable();

    /**
     *
     * @param var a specific var
     * @return 'true' if the val exist in the map, 'false' otherwise
     */
    bool isValExist(string var);

    bool isConnect() const;

    void setConnect(bool connect);

    void setClientId(int clientId);

    int getClientId() const;

    int getServerId() const;

    const vector<string> &getNames() const;

    bool isServer() const;

    void setServer(bool server);
};

#endif //PROGECT_SYMBOLTABLE_H
