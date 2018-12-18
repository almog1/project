//
// Created by almogg on 12/18/18.
//

#ifndef PROGECT_CONNECTCOMMAND_H
#define PROGECT_CONNECTCOMMAND_H

#include "Command.h"

class ConnectCommand : public Command {
    string ip;
    int port;
public:
    ConnectCommand();

    int doCommand(vector<string> data) override;

    const string &getIp() const;

    void setIp(const string &ip);

    int getPort() const;

    void setPort(int port);
};

#endif //PROGECT_CONNECTCOMMAND_H
