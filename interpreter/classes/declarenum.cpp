#include "headers/declarenum.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>

void DeclareNum::parse(){

    global_parser.check(NUM);
    global_parser.consume();
    global_parser.check(NAME);
    name = global_parser.get_name();
    global_parser.consume();
    global_parser.check(SEMICOLON);
    global_parser.consume();
}

void DeclareNum::print(){
    std::cout << "tally " << name << "." << std::endl;
}