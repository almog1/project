
//

#ifndef PROGECT_VAR_H
#define PROGECT_VAR_H

#include "string"

using namespace std;

/**
 * For the variables
 */
class Var {
private:
    string name;
    string path;
    double value;
public:
    Var(const string &name, const string &path, double value);

    void setName(const string &name);

    void setPath(const string &path);

    void setValue(double value);

    const string &getName() const;

    const string &getPath() const;

    double getValue() const;
};

#endif //PROGECT_VAR_H
