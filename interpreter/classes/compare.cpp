#include "headers/compare.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>

void Compare::parse() {
    expression.parse();
    simple t = global_parser.token_stream.value().current_token();
    if(t == LESS){
        type = 1;
    }
    global_parser.consume();
    expression2.parse();
}

void Compare::print() {
    expression.print();
    if(type == 0){
        std::cout << " = ";
    } else{
        std::cout << " < ";
    }
    expression2.print();
}