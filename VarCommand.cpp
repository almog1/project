//
// Created by almogg on 12/18/18.
//

#include "VarCommand.h"
#include "OtherFunctions.h"
#include "Expression.h"
#include "SymbolTable.h"

VarCommand::VarCommand() {
    //todo - check if need to set something in the constructor
}

int VarCommand::setParameters(vector<string> data, int index) {
    SymbolTable * symbolTab = SymbolTable::getInstance();


    int newIndex = 0;
    string varName = "";
    //check if first is Var
    if (data[index] == "var") {
        //get the vector when index is on the string "var"
        //make share size is more then 4
        if ((index + 4) > data.size()) {
            throw "Not Enough Args!";
        }

        //second is the var name
        varName = data[index + 1];
        string varPath = "";
        //third should be '='
        if (data[index + 2] != "=") {
            throw "Not Correct Argumnent";
        }

        //check if 'bind'
        if (data[index + 3] == "bind") {
            //take the string
            //make sure in the values
            if ((index + 5) > data.size()) {
                throw "Not Enoght Args!";
            }
            varPath = data[index + 4];

            //insert the var name with its path
            symbolTab->addPathToVar(varName,varPath);

           // this->varPathTable.insert(pair<string, string>(varName, varPath));
            newIndex = 5;
            //todo - check if need with or without the ""
        } else {
            //other var name
            double value;
            //if it can be an expression
            string val = putSpaces(data[index + 3]);
            Expression *valExp = evaluate(val);

            value = valExp->calculate(*symbolTab->getSymbolTable());

            //if it will be just name of var - it will take it from the map and return its value there
            //need to put its value in string value
            // value = this->symbolTable.at(data[index + 3]);

            symbolTab->addSymbolValue(varName,value);
            newIndex = 4;
        }
    } else {
        //start from the real var name
        //make share size is more then 3
        if ((index + 3) > data.size()) {
            throw "Not Enough Args!";
        }
        varName = data[index];
        if (data[index + 1] != "=") {
            throw "Should be '=' here!";
        }

        double value;
        //if it can be an expression
        string val = putSpaces(data[index + 2]);
        Expression *valExp = evaluate(val);
        value = valExp->calculate(*symbolTab->getSymbolTable());
        //take the expression value

        symbolTab->addSymbolValue(varName,value);
        newIndex = 3;
    }
    //todo - make sure need to return 5 and not 4
    return newIndex;
}

void VarCommand::doCommand() {

}
