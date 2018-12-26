#include <iostream>
#include <fstream>
#include "ExpressionHeaders.h"
#include "expressionDetect.h"
#include "Reader.h"
#include "Parser.h"
#include "OtherFunctions.h"
#include "OpenDataServer.h"
#include "CommandExpression.h"
#include "SymbolTable.h"

using namespace std;
ifstream file;

int main() {
    std::cout << "Hello, World!" << std::endl;

//    OpenDataServer *dataServer = new OpenDataServer();
//    dataServer->setPort(5400);
//    dataServer->setHz(10);
//    dataServer->doCommand();


    vector<string> data = Lexer("test1.txt");
    Parser parserRun;
    parserRun.parser(data);

    pthread_exit(NULL);

    return 0;
}
