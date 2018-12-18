//
// Created by almogg on 12/18/18.
//

#ifndef PROGECT_READER_H
#define PROGECT_READER_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

/**
 * Read the information .
 */

    vector<string> Lexer(string fileName);

    vector<string> Split(string line, char divide);

#endif //PROGECT_READER_H
