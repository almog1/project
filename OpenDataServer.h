//
// Created by almogg on 12/18/18.
//

#ifndef PROGECT_OPENDATASERVER_H
#define PROGECT_OPENDATASERVER_H

#include "Command.h"

class OpenDataServer : public Command {
    int port;
    int hz;
public:
    OpenDataServer();

    int doCommand(vector<string> data) override;

    int getPort() const;

    void setPort(int port);

    int getHz() const;

    void setHz(int hz);
};

#endif //PROGECT_OPENDATASERVER_H
