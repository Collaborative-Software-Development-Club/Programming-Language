#include "headers/print.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>

void Print::parse() {
    global_parser.check(PRINT);
    global_parser.consume();
    global_parser.check(LPAREN);
    global_parser.consume();

    expression.parse();

    global_parser.check(RPAREN);
    global_parser.consume();

    global_parser.check(SEMICOLON);
    global_parser.consume();
}

void Print::print() {
    std::cout << "print(";
    expression.print();
    std::cout << ")" << std::endl; 
}