#include <iostream>

#include "ExpressionHeaders.h"
#include "expressionDetect.h"
#include "Reader.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    map<string, double> symbolTebla;

    symbolTebla.insert(pair<string, double>("x", 2));
    symbolTebla.insert(pair<string, double>("y", 4));

    Expression *exp = new Div(new Var("x"), new Var("y"));
    cout << exp->calculate(symbolTebla) << endl;

 //   string str = "6 * ( 2 + 10 )";
    string str = "2 * ( 3 + 9 ) / 12 + 4";
    Expression *exp2 = evaluate(str);
    cout << exp2->calculate(symbolTebla) << endl;

    vector<string> lines;
    lines = Lexer("/home/almogg/Documents/ProjcetStep1/test.txt");

    for (vector<string>::iterator it = lines.begin(); it != lines.end(); ++it) {
        cout << "\n" << *it;
    }
    return 0;
}