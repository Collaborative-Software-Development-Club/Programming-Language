#include "headers/loop.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>

void Loop::parse() {
    global_parser.check(WHILE);
    global_parser.consume();
    condition.parse();
    global_parser.check(LCURL);
    global_parser.consume();
    statementSeq.parse();
    global_parser.check(RCURL);
    global_parser.consume();
}

void Loop::print() {
    std::cout << "while ";
    condition.print();
    std::cout << " {" << std::endl;
    statementSeq.print(); 
    std::cout << "}" << std::endl;
}