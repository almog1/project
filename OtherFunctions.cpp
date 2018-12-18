//
// Created by almogg on 12/18/18.
//

#include "OtherFunctions.h"

string putSpaces(string str) {
    int i = 0;
    string newStr = "";
    newStr = str[0];

    //run on all the string and add spaces
    for (i = 1; i < str.length(); i++) {
        newStr = newStr + " " + str[i];
    }
    return newStr;
}