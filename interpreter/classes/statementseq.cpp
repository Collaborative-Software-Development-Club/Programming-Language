#include "headers/statementseq.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>

void StatementSeq::parse() {
    s = std::make_unique<Statement>();
    s->parse();
    tester = 2;
}

void StatementSeq::print() {
    s->print();
    //if (ss != nullptr) ss->print();
    std::cout << tester << std::endl;
}