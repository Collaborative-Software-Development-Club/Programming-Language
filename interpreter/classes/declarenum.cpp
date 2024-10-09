#include "headers/declarenum.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>

void DeclareNum::parse() {
    simple currentToken = global_parser.token_stream.value().current_token();
    global_parser.check(NUM);
    global_parser.consume();
    
    global_parser.check(NAME);
    num = global_parser.get_num();
    global_parser.consume();

    global_parser.check(SEMICOLON);
    global_parser.consume();
}

void DeclareNum::print() {
    std::cout << "NuM " << num << ";" << std::endl;
}