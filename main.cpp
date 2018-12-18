#include <iostream>

#include "ExpressionHeaders.h"
#include "expressionDetect.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    map<string, double> symbolTebla;

    symbolTebla.insert(pair<string, double>("x", 2));
    symbolTebla.insert(pair<string, double>("y", 4));

    Expression *exp = new Div(new Var("x"), new Var("y"));
    cout << exp->calculate(symbolTebla) << endl;

    string str = "6 * ( 2 + 10 )";
    Expression* exp2=evaluate(str);
    cout << exp2->calculate(symbolTebla) << endl;
    return 0;
}