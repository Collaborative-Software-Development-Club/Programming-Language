#include "headers/if.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>

void If::parse() {
    global_parser.check(IF);
    global_parser.consume();
    condition.parse();
    global_parser.check(LCURL);
    global_parser.consume();
    statementSeq->parse();
    global_parser.check(RCURL);
    global_parser.consume();
    if (global_parser.token_stream.value().current_token() == ELSE) {
        hasElse = true;
        global_parser.check(ELSE);
        global_parser.consume();
        global_parser.check(LCURL);
        global_parser.consume();
        statementSeq2->parse();
        global_parser.check(RCURL);
        global_parser.consume();
    }
}

void If::print() {
    std::cout << "if ";
    condition.print();
    std::cout << " {" << std::endl;
    statementSeq->print();
    std::cout << "}" << std::endl;
    if (hasElse) {
        std::cout << "else ";
        std::cout << " {" << std::endl;
        statementSeq2->print();
        std::cout << "}" << std::endl;
    }
}