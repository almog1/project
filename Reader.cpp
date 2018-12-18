//
// Created by almogg on 12/18/18.
//

#include "Reader.h"

vector<string> Lexer(string fileName) {
    vector<string> data;

    //read rhe information from the file
    string line;
    //check if the file exist
    ifstream ifs(fileName);
    if (ifs.is_open()) {
        //take a string of line
        while (getline(ifs, line)) {
            //add the line to the vector
            stringstream temp(line);
            //create from the line
            string segment;
            //split by " "
            while (getline(temp, segment, ' ')) {
                data.push_back(segment);
            }
        }
        ifs.close();
    }
    return data;
}

/**
     * Split the line by char .
     * @param line . string the line to split
     * @param divide . char to split by it
     * @return vector after been splitted
     */
vector<string> Split(string line, char divide) {
    stringstream temp(line);
    //create from the line
    string segment;
    vector<std::string> seglist;
    //split by ","
    while (getline(temp, segment, divide)) {
        seglist.push_back(segment);
    }
    return seglist;
}