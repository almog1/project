//
// Created by almogg on 12/16/18.
//

#include "Var.h"

Var::Var(const string &name, const string &path, double value) : name(name), path(path), value(value) {

}

const string &Var::getName() const {
    return this.name;
}

const string &Var::getPath() const {
    return this.path;
}

double Var::getValue() const {
    return this.value;
}

void Var::setName(const string &name) {
    Var::name = name;
}

void Var::setPath(const string &path) {
    Var::path = path;
}

void Var::setValue(double value) {
    Var::value = value;
}
