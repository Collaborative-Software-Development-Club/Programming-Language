#include "headers/term.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>

//<term> ::= <factor> | <factor> MULTIPLY <term> | <factor> DIVIDE <term>

void Term::parse() {
    factor.parse();
    simple t = global_parser.token_stream.value().current_token();
    if(t == MULTIPLY){
        global_parser.consume();
        type = 1;
        term2->parse();
    }else if (t == DIVIDE){
        global_parser.consume();
        type = 2;
        term2->parse();
    }
}

void Term::print() {
    factor.print();
    if(type == 1){
        std::cout << " * ";
        term2->print();
    }else if (type == 2){
        std::cout << " / ";
        term2->print();
    }
}