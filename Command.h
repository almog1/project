
#ifndef PROGECT_COMMAND_H
#define PROGECT_COMMAND_H

#include <vector>
#include <string>
#include <map>

using namespace std;

/**
 * Command Class -
 * responsible on the command in the program
 */
class Command {
protected:
    //contains a map of all the string vars and their values in the program
   // map<string, double> symbolTable;
    //connection between var name and path
    //map<string, string> varPathTable;
    // todo - maybe need to intilize the map for the beggining
public:
    /**
     * constructor - build a new command
     */
    Command() {
        //todo change it
      //  symbolTable.insert(pair<string, double>("x", 2));
       // symbolTable.insert(pair<string, double>("y", 4));
    }

    /**
     *
     * @return the table with all the variables
     */
//    const map<string, double> getSymbolTable() const;

    /**
     *
     * @param data a vector witch contains all the words from the script (command and values - expression)
     * @param index - points on a place in the data vector
     * @return how much we need to move on the array (the num of values for a specific command)
     */
    virtual int setParameters(vector<string> data, int index) = 0;

    /**
     * the function that runs the command we want
     */
    virtual void doCommand() = 0;
};

#endif //PROGECT_COMMAND_H
