#include "headers/assign.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>

void Assign::parse() {
    std::cout << "this:" << std::endl;
    //global_parser.check(NAME);
    //std::cout << global_parser.get_name() << std::endl;
    //name = global_parser.get_name();
    //global_parser.consume();
    //global_parser.check(ASSIGN);
    //global_parser.consume();
    //expression.parse();
    //global_parser.check(SEMICOLON);
    //global_parser.consume();
}

void Assign::print() {
    std::cout << name << " = ";
    expression.print();
    std::cout << ";" << std::endl;
}