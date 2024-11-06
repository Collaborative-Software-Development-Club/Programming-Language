#include "headers/declare.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>
#include <memory>

void Declare::parse() {
    dn = std::make_unique<DeclareNum>();
    dn->parse();
}

void Declare::print() {
    dn->print();
}

void Declare::execute() {
    dn->execute();
}