
#ifndef PROGECT_OPENDATASERVER_H
#define PROGECT_OPENDATASERVER_H

#include "Command.h"

/**
 * OpenDataServer Class
 * the class who responsible for open a server to connect with the client
 */
class OpenDataServer : public Command {
    // the port we are gonna to connect
    int port;

    //num of miiseconds we are gonna to read the information from the client
    int hz;
public:
    /**
     * a defult constructor
     */
    OpenDataServer();

    /**
     *
     * @param data a vector witch contains all the words from the script (command and values - expression)
     * @param index - points on a place in the data vector
     * @return how much we need to move on the array (the num of values for a specific command)
     */
    int setParameters(vector<string> data, int index) override;

    /**
     * run the command
     */
    void doCommand() override;

    int getPort() const;

    void setPort(int port);

    int getHz() const;

    void setHz(int hz);
};

#endif //PROGECT_OPENDATASERVER_H
