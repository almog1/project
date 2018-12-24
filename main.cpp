#include <iostream>

#include "ExpressionHeaders.h"
#include "expressionDetect.h"
#include "Reader.h"
#include "Parser.h"
#include "OtherFunctions.h"
#include "OpenDataServer.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    map<string, double> symbolTebla;

    symbolTebla.insert(pair<string, double>("avi", 2));
    symbolTebla.insert(pair<string, double>("moshe", 4));

    OpenDataServer *dataServer = new OpenDataServer();
    dataServer->setPort(5400);
    dataServer->setHz(10);
    dataServer->doCommand();
    while (true){

    }

    return 0;
}