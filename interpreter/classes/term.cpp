#include "headers/term.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>

void Term::parse() {
    factor.parse();
    if (global_parser.token_stream.value().current_token() == MULTIPLY) {
        global_parser.consume();
        termType = 1;
        t->parse();
    }
    else if (global_parser.token_stream.value().current_token() == DIVIDE) {
        global_parser.consume();
        termType = 2;
        t->parse();
    }
    else {
        termType = 0;
    }
}

void Term::print() {
    factor.print();
    if (termType == 1) {
        std::cout << " * ";
        t->print();
    }
    else if (termType == 2) {
        std::cout << " / ";
        t->print();
    }
} 