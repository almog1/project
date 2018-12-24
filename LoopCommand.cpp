//
// Created by almogg on 12/22/18.
//

#include "LoopCommand.h"
#include "CommandTable.h"
#include "OtherFunctions.h"
//#include "CommandTable.h"

int LoopCommand::setParameters(vector<string> data, int index) {
//    CommandTable* commadTab = CommandTable::getInstance();
    //  map<string, Expression*> commandTable = commadTab->getTable();
    //check what is the condition

    int newIndex = 5;
    //todo - make sure enough arguments
    //date[index] = while
    string leftCondition = putSpaces(data[index + 1]);
    this->leftExp = evaluate(leftCondition); //just make the expression and save it to member

    string rightCond = putSpaces(data[index + 3]);
    this->rightExp = evaluate(rightCond); // just take the expression and save as member

    //save the condition
    this->condition = data[index + 2];

    //create the loop command - create the vector of commands
    newIndex = this->createLoop(data, newIndex);

    //take the expression value
    return newIndex;
}

void LoopCommand::doCommand() {
    //check condition
    //as long as the condition is true - run on all the commands in the loop
    while (this->checkCondition()) {
        int i = 0;
        for (int i = 0; i < this->commands.size(); i++) {
            this->commands[i]->calculate(); //do the command
        }
    }
}

int LoopCommand::createLoop(vector<string> data, int index) {
    CommandTable *commandTab = CommandTable::getInstance();
    map<string, Expression *> commandTable = commandTab->getTable();

    //check its not the end of the loop
    //and data isn't over
    while (index < data.size() && data[index] != "}") {
        //add command to the command vector
        //this->commands.insert()

        map<string, Expression *>::iterator it;

        //need to find the command
        it = commandTable.find(data[index]);
        CommandExpression *dataCommand;
        //check if exist
        if (it != commandTable.end()) {
            dataCommand = dynamic_cast<CommandExpression *>(it->second);
        } else {
            //its a var name
            //need to go to the VarCommand
            dataCommand = dynamic_cast<CommandExpression *>(commandTable.find("var")->second);
        }
        index += dataCommand->getCommand()->setParameters(data, index);

        //add the command to the vector of commands
        commands.push_back(dataCommand);
    }
    //check if this is the '}'
    if (data[index] == "}") {
        index = index + 1;
    }
    return index;
}

bool LoopCommand::checkCondition() {
    double leftVal = this->leftExp->calculate();
    double rightVal = this->rightExp->calculate();

    //check what is the condition
    if (this->condition == "==") {
        if (leftVal == rightVal) {
            return true;
        } else {
            return false;
        }
    } else if (this->condition == "<=") {
        if (leftVal <= rightVal) {
            return true;
        } else {
            return false;
        }

    } else if (this->condition == ">=") {
        if (leftVal >= rightVal) {
            return true;
        } else {
            return false;
        }
    } else if (this->condition == "!=") {
        if (leftVal != rightVal) {
            return true;
        } else {
            return false;
        }
    } else if (this->condition == "<") {
        if (leftVal < rightVal) {
            return true;
        } else {
            return false;
        }
    } else if (this->condition == ">") {
        if (leftVal > rightVal) {
            return true;
        } else {
            return false;
        }
    }
}
//bool checkCondition()