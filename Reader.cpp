//
// Created by almogg on 12/18/18.
//

#include "Reader.h"

vector<string> Lexer(string fileName) {
    vector<string> data;
    bool isInOp = false;
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
            string oldSegmaent;
            char last, first;
            bool lastOp = false, firstOp = false;
            //split by " "
            while (getline(temp, segment, ' ')) {
                last = segment[segment.length() - 1];
                first = segment[0];
                //check if its operator - need to take the next one too
                if (last == '+' || last == '-' || last == '/' || last == '*') {
                    lastOp = true;
                }
                if (first == '+' || first == '-' || first == '/' || first == '*') {
                    firstOp = true;
                }
                if (firstOp == true || lastOp == true) {
                    //if just this char
                    if (segment.length() == 1 || (firstOp && lastOp)) {
                        isInOp = true;
                        data[data.size() - 1] = data[data.size() - 1] + segment;
                    } else {
                        if (firstOp) {
                            data[data.size() - 1] = data[data.size() - 1] + segment;
                            isInOp = false;
                        }
                        if (lastOp) {
                            if(isInOp == true){
                                data[data.size() - 1] = data[data.size() - 1] + segment;
                            }else{
                                data.push_back(segment);
                            }
                            isInOp = true;
                        }
                    }
                } else {
                    //check if end "("
                    if (last == '(') {
                        if (isInOp == true) {
                            data[data.size() - 1] = data[data.size() - 1] + segment;
                        } else {
                            data.push_back(segment);
                        }
                        isInOp = true;
                    } else {
                        if (last == ')' || first == ')') {
                            data[data.size() - 1] = data[data.size() - 1] + segment;
                        } else {
                            if (isInOp == true) {
                                data[data.size() - 1] = data[data.size() - 1] + segment;
                            } else {
                                data.push_back(segment);
                            }
                        }
                        isInOp = false;
                    }
                }
                firstOp = false;
                lastOp = false;
                //oldSegmaent = segment;
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