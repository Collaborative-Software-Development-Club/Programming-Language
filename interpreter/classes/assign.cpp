#include "headers/assign.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>
#include <memory>

void Assign::parse() {
    global_parser.check(NAME);
    name = global_parser.get_name();
    global_parser.consume();
    global_parser.check(ASSIGN);
    global_parser.consume();
    expr = std::make_unique<Expression>();
    expr->parse();
    global_parser.check(SEMICOLON);
    global_parser.consume();
}

void Assign::print() {
    std::cout << name << " = ";
    expr->print();
    std::cout << ";" << std::endl;
}