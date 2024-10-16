#include "headers/expression.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>

void Expression::parse() {
    term.parse();
    if (global_parser.token_stream.value().current_token() == ADD) {
        global_parser.consume();
        exprType = 1;
        e->parse();
    }
    else if (global_parser.token_stream.value().current_token() == SUBTRACT) {
        global_parser.consume();
        exprType = 2;
        e->parse();
    }
    else {
        exprType = 0;
    }
}

void Expression::print() {
    term.print();
    if (exprType == 1) {
        std::cout << " + ";
        e->print();
    }
    else if (exprType == 2) {
        std::cout << " - ";
        e->print();
    }
}