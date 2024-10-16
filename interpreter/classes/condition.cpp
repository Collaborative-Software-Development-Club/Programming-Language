#include "headers/condition.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>

void Condition::parse() {
    if (global_parser.token_stream.value().current_token() == NOT) {
        global_parser.check(NOT);
        global_parser.consume();
        cndType = 1;
        cnd->parse();
    }
    else {
        compare.parse();
        if (global_parser.token_stream.value().current_token() == OR) {
            global_parser.consume();
            cndType = 2;
            cnd->parse();
        }
        else if (global_parser.token_stream.value().current_token() == AND) {
            global_parser.consume();
            cndType = 3;
            cnd->parse();
        }
    }
}

void Condition::print() {
    switch (cndType) {
        case 0:
        compare.print();
        break;
        case 1:
        std::cout << " not ";
        cnd->print();
        break;
        case 2:
        compare.print();
        std::cout << " or ";
        cnd->print();
        break;
        case 3:
        compare.print();
        std::cout << " and ";
        cnd->print();
        break;
        default:
        break;
    }
}