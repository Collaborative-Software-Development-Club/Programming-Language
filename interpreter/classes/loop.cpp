#include "headers/loop.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>
#include <memory>

void Loop::parse() {
    global_parser.check(WHILE);
    global_parser.consume();
    cnd = std::make_unique<Condition>();
    cnd->parse();
    global_parser.check(LCURL);
    global_parser.consume();
    ss = std::make_unique<StatementSeq>();
    ss->parse();
    global_parser.check(RCURL);
    global_parser.consume();
}

void Loop::print() {
    std::cout << "while ";
    cnd->print();
    std::cout << " {" << std::endl;
    ss->print(); 
    std::cout << "}" << std::endl;
}

void Loop::execute() {
    while (cnd->execute()) {
        global_memory.make_scope();
        ss->execute();
        global_memory.demake_scope();
    }
}