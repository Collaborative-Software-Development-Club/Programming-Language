#include "headers/assign.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>
#include <string>

using namespace std;


void Assign::parse(){
    global_parser.check(NAME);
    global_parser.consume();
    global_parser.check(ASSIGN);
    expression.parse();
    global_parser.check(SEMICOLON);
    global_parser.consume();
}

void Assign::print(){
    std::cout << "designation designate "<<std::endl;
    expression.print();
    std::cout << ".\n" << std::endl;
} 
//<assign> ::= NAME ASSIGN <expression> SEMICOLON
