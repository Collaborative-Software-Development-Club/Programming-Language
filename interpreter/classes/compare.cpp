#include "headers/compare.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>
#include <memory>
void Compare::parse() {
    expression = std::make_unique<Expression>();
    expression2 = std::make_unique<Expression>();

    expression->parse();
    simple t = global_parser.token_stream.value().current_token();
    if(t == LESS){
        type = 1;
    }
    global_parser.consume();
    expression2->parse();
}

void Compare::print() {
    expression->print();
    if(type == 0){
        std::cout << " = ";
    } else{
        std::cout << " < ";
    }
    expression2->print();
}