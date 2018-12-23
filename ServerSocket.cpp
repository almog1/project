//
// Created by chagit on 12/22/18.
//

#include <iostream>
#include "ServerSocket.h"


using namespace std;

struct MyParams {
    int port;
    int hz;
};

void *ServerSocket::openSocket(void *arg) {
    vector<string> vars;
    struct MyParams *params = (struct MyParams *) arg;

    int sockfd, newsockfd, portno, clilen;
    char buffer[1024];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    // Creating socket file descriptor
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    //initialize socket structure
    bzero((char *) &serv_addr, sizeof(serv_addr));

    portno = params->port;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // now bind the host adress using bind call
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error on binding");
        exit(1);
    }

    /**
     * now start listening to teh client. here process wii go in sleep mode and will wait
     * for the incoming connection
     */
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    //accept actual connection from the client
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
    //cout << "hii" << endl;

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    //if connections is established then start communicating
    bzero(buffer, 1024);

    //sleep fot this->hz
    while (true) {
        n = read(newsockfd, buffer, 1024);
        string b = buffer;
        cout << buffer << endl;
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        vector<string> line;
        size_t pos = 0;
        string delimiter = ",";
        //spliting by ','
        while ((pos = b.find(delimiter)) != string::npos) {
            line.push_back(b.substr(0, pos));
            b.erase(0, pos + delimiter.length());
        }
        line.push_back(b.substr(0, pos));

        //update the map with the values from the simulator
//        Command *c;
//        vector<string, double> data = c->getSymbolTable();
//        for (int i = 0; i < line.size(); ++i) {
//            data.find[vars[i]].setValue(stod(line[i]));
//        }
    }
}