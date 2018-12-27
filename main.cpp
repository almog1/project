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

int main(int argc, char* argv[]) {
  //  std::cout << "Hello, World!" << std::endl;
    string fileName = "";
    if(argc >= 1){
        fileName = argv[1];
    }

    vector<string> data = Lexer(fileName);
    Parser* parserRun = new Parser();
    parserRun->parser(data);

    pthread_exit(NULL);

    return 0;
}
