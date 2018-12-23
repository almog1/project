#include <iostream>

#include "ExpressionHeaders.h"
#include "expressionDetect.h"
#include "Reader.h"
#include "Parser.h"
#include "OtherFunctions.h"
#include "OpenDataServer.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    map<string, double> symbolTebla;

    vector<string> names = {"/instrumentation/airspeed-indicator/indicated-speed-kt","/instrumentation/altimeter/indicated-altitude-ft","/instrumentation/altimeter/pressure-alt-ft","/instrumentation/attitude-indicator/indicated-pitch-deg","/instrumentation/attitude-indicator/indicated-roll-deg","/instrumentation/attitude-indicator/internal-pitch-deg","/instrumentation/attitude-indicator/internal-roll-deg","/instrumentation/encoder/indicated-altitude-ft","/instrumentation/encoder/pressure-alt-ft","/instrumentation/gps/indicated-altitude-ft","/instrumentation/gps/indicated-ground-speed-kt","/instrumentation/gps/indicated-vertical-speed","/instrumentation/heading-indicator/indicated-heading-deg","/instrumentation/magnetic-compass/indicated-heading-deg","/instrumentation/slip-skid-ball/indicated-slip-skid","/instrumentation/turn-indicator/indicated-turn-rate","/instrumentation/vertical-speed-indicator/indicated-speed-fpm","/controls/flight/aileron","/controls/flight/elevator","/controls/flight/rudder","/controls/flight/flaps","/controls/engines/engine/throttle","/engines/engine/rpm"};

    symbolTebla.insert(pair<string, double>("avi", 2));
    symbolTebla.insert(pair<string, double>("moshe", 4));


    OpenDataServer *dataServer = new OpenDataServer();
    dataServer->setPort(5400);
    dataServer->setHz(10);
    dataServer->doCommand();
    while (true){

    }

    return 0;
}