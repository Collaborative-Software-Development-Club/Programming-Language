#include "headers/print.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>
#include <string>
#include <memory>

void Print::parse() {
    global_parser.check(PRINT);
    global_parser.consume();
    global_parser.check(LPAREN);
    global_parser.consume();
    expr = std::make_unique<Expression>();
    expr->parse();
    global_parser.check(RPAREN);
    global_parser.consume();
    global_parser.check(SEMICOLON);
    global_parser.consume();
}

void Print::print() {
    std::cout << "print(";
    expr->print();
    std::cout << ");" << std::endl;
}

void Print::execute() {
    std::cout << expr->execute() << std::endl;
}