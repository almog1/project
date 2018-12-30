//
// Created by almogg on 12/30/18.
//

#include "ExitCommand.h"
ExitCommand::ExitCommand() {

}

void ExitCommand::doCommand() {
    exit(0);
}

int ExitCommand::setParameters(vector<string> data, int index) {
    return 1;
}

ExitCommand::~ExitCommand() {}