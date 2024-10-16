#include "headers/compare.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>

void Compare::parse() {
    expression.parse();
    if (global_parser.token_stream.value().current_token() == EQUAL) {
        equal = false;
        global_parser.consume();
    }
    else {
        equal = true;
        global_parser.check(LESS);
        global_parser.consume();
    }
    expression2.parse();
}

void Compare::print() {
    expression.print();
    if (equal) {
        std::cout << " == ";
    }
    else {
        std::cout << " < ";
    }
    expression2.print();
}