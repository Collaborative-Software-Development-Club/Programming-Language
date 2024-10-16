#include "headers/expression.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>

void Expression::parse() {
    term.parse();
    simple t = global_parser.token_stream.value().current_token();
    if(t == ADD){
        global_parser.consume();
        type = 1;
        e->parse();
    }else if (t == SUBTRACT){
        global_parser.consume();
        type = 2;
        e->parse();
    }
}

void Expression::print() {
    term.print();
    if(type == 1){
        std::cout << " + ";
        e->print();
    }else if (type == 2){
        std::cout << " - ";
        e->print();
    }
}