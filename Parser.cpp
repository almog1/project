//
// Created by almogg on 12/18/18.
//

#include <iostream>
#include "Parser.h"

#define OPEN_DATA_SERVER "openDataServer"
#define CONNECT "connect"
#define VAR "var"

void Parser::parser(vector<string> data) {
    //check the data
    vector<string>::iterator it;

    //vector not empty
    if (data.empty() == false) {
        it = data.begin();
        if (*it == OPEN_DATA_SERVER) {
            ++it;
            while(it!= data.end() && (*it)!= CONNECT){

            }
        } else {
            throw "first argument isn't openDataServer";
        }
    }


    //run on the data in the data vector - check it
    for (it = data.begin(); it != data.end(); ++it) {
        //need to see the open data server
        if (*it == OPEN_DATA_SERVER) {

        }

    }
}