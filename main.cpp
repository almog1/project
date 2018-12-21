#include <iostream>

#include "ExpressionHeaders.h"
#include "expressionDetect.h"
#include "Reader.h"
#include "Parser.h"
#include "OtherFunctions.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    map<string, double> symbolTebla;

    symbolTebla.insert(pair<string, double>("avi", 2));
    symbolTebla.insert(pair<string, double>("moshe", 4));

    //Expression *exp = new Div(new Var("xxx"), new Var("yyy"));
    //cout << exp->calculate(symbolTebla) << endl;

    //   string str = "6 * ( 2 + 10 )";
    string str = "2+(- 4*3)";
    str = putSpaces(str);
    //string str = "5";
    Expression *exp2 = evaluate(str);
    cout << exp2->calculate(symbolTebla) << endl;


//    vector<string> lines;
//    //lines = Lexer("/home/almogg/Documents/ProjcetStep1/test.txt");
//    //lines = Lexer("/home/chagit/Documents/progectStep1/test1.txt");
//
//    for (vector<string>::iterator it = lines.begin(); it != lines.end(); ++it) {
//        cout << "\n" << *it;
//    }
//    cout << "\n" << endl;
//
//    string changed = putSpaces(lines[0]);
//    //string changed = "( 5 - 2 ) * ( -3 ) + 5";
//    Expression* exp3 = evaluate(changed);
//    cout << exp3->calculate(symbolTebla) << endl;
    return 0;
}