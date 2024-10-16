#include "headers/factor.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>

//<factor> ::= NAME | NUMBER | LPAREN <expression> RPAREN


void Factor::parse() {
    simple t = global_parser.token_stream.value().current_token();
    switch(t){
        case (NAME):
            name=global_parser.get_name();
            global_parser.consume();
            break;
        case (NUMBER):
            value = global_parser.get_num();
            global_parser.consume();
            break;
        case (LPAREN):
            isParen = true;
            global_parser.consume();
            expression->parse();
            global_parser.consume(); //consume the )
            break;
        default:
            break;
    }
}

void Factor::print() {
    if(type == 0){
        std::cout << name << std::endl;
    }else if(type == 1){
        std::cout << value << std::endl;
    }else{
        //must be the parenthesis part...
        std::cout << "(";
        expression->parse();
        std::cout << ")" << std::endl;
    }
}