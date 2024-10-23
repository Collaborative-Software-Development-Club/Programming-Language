#include "headers/factor.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>

void Factor::parse() {
    if (global_parser.token_stream.value().current_token() == NAME) {
        factorType = 0;
        name = global_parser.get_name();
        global_parser.consume();
    }
    else if (global_parser.token_stream.value().current_token() == NUMBER) {
        factorType = 1;
        num = global_parser.get_num();
        global_parser.consume();
    }
    else {
        factorType = 2;
        global_parser.check(LPAREN);
        global_parser.consume();
        expression->parse();
        global_parser.check(RPAREN);
        global_parser.consume();
    }
}

void Factor::print() {
    if (factorType == 0) {
        std::cout << name;
    }
    else if (factorType == 1) {
        std::cout << num;
    }
    else {
        std::cout << "(";
        expression->print();
        std::cout << ")";
    }
}