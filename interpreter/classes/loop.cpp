#include "headers/loop.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>
#include <memory>

void Loop::parse() {
    condition = std::make_unique<Condition>();
    statementSeq = std::make_unique<StatementSeq>();

    global_parser.check(WHILE);
    global_parser.consume();
    
    condition->parse();
    global_parser.check(LCURL);
    global_parser.consume();
    statementSeq->parse();
    global_parser.check(RCURL);
    global_parser.consume();
}

//No need to instantiate the unique ptr object stuff as we assume they've already been created!
void Loop::print() {
    std::cout << "while ";
    condition->print();
    std::cout << "(";
    statementSeq->print();
    std::cout << ")" << std::endl;
}