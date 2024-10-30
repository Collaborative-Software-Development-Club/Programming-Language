#include "headers/compare.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>
#include <memory>

void Compare::parse() {
    expr1 = std::make_unique<Expression>();
    expr1->parse();
    if (global_parser.token_stream.value().current_token() == EQUAL) {
        equal = false;
        global_parser.consume();
    }
    else {
        equal = true;
        global_parser.check(LESS);
        global_parser.consume();
    }
    expr2 = std::make_unique<Expression>();
    expr2->parse();
}

void Compare::print() {
    expr1->print();
    if (equal) {
        std::cout << " == ";
    }
    else {
        std::cout << " < ";
    }
    expr2->print();
}