#include "headers/declare.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>
#include <memory>

void Declare::parse() {
    dm = std::make_unique<DeclareNum>();
    dm->parse();
}

void Declare::print() {
    dm->print();
}