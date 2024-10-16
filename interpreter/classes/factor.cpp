#include "headers/factor.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>

void Factor::parse(){
    simple current = global_parser.token_stream.value().current_token();
    if(current == NAME){
        type = 0; 
        name = global_parser.get_name(); 
        global_parser.consume(); 

    }else if(current == NUMBER){
        type = 1; 
        value = global_parser.get_num();
        global_parser.consume(); 

    }else{
        type = 2; 
        global_parser.check(LPAREN);
        expression->parse();

        global_parser.check(RPAREN);
        global_parser.consume(); 
    }
}

void Factor::print(){
     if (factorType == 0) {
        std::cout << name;
    }
    else if (factorType == 1) {
        std::cout << num;
    }
    else {
        std::cout << "(";
        expression->print();
        std::cout << ")";
    }
}