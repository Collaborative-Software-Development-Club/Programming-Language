#include "headers/if.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>
#include <memory>

void If::parse() {
    global_parser.check(IF);
    global_parser.consume();
    cnd = std::make_unique<Condition>();
    cnd->parse();
    global_parser.check(LCURL);
    global_parser.consume();
    ss1 = std::make_unique<StatementSeq>();
    ss1->parse();
    global_parser.check(RCURL);
    global_parser.consume();
    if (global_parser.token_stream.value().current_token() == ELSE) {
        hasElse = true;
        global_parser.check(ELSE);
        global_parser.consume();
        global_parser.check(LCURL);
        global_parser.consume();
        ss2 = std::make_unique<StatementSeq>();
        ss2->parse();
        global_parser.check(RCURL);
        global_parser.consume();
    }
}

void If::print() {
    std::cout << "if ";
    cnd->print();
    std::cout << " {" << std::endl;
    ss1->print();
    std::cout << "}" << std::endl;
    if (hasElse) {
        std::cout << "else ";
        std::cout << " {" << std::endl;
        ss2->print();
        std::cout << "}" << std::endl;
    }
}

void If::execute() {
    if (!hasElse) {
        if (cnd->execute()) {
            global_memory.make_scope();
            ss1->execute();
            global_memory.demake_scope();
        }
    }
    else {
        if (cnd->execute()) {
            global_memory.make_scope();
            ss1->execute();
            global_memory.demake_scope();
        }
        else {
            global_memory.make_scope();
            ss2->execute();
            global_memory.demake_scope();
        }
    }
}