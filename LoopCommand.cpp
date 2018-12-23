//
// Created by almogg on 12/22/18.
//

#include "LoopCommand.h"
//#include "CommandTable.h"

int LoopCommand::setParameters(vector<string> data, int index) {
//    CommandTable* commadTab = CommandTable::getInstance();
  //  map<string, Expression*> commandTable = commadTab->getTable();
    //check what is the condition

    int newIndex = 4;
    //todo - make sure enough arguments
    //date[index] = while
    string leftCondition = putSpaces(data[index + 1]);
    this->leftExp = evaluate(leftCondition); //just make the expression and save it to member

    string rightCond = putSpaces(data[index + 3]);
    this->rightExp = evaluate(rightCond); // just take the expression and save as member

    //save the condition
    this->condition = data[index + 2];

    //take the expression value
    return newIndex;
}

void LoopCommand::doCommand() {

}
