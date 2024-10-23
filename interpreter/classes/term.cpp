#include "headers/term.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>

void Term::parse(){
    type = 0; 
    
    factor.parse();

    if(global_parser.token_stream.value().current_token() == MULTIPLY){
        type = 1;
        global_parser.consume();
        term_ptr->parse();
    }else if(global_parser.token_stream.value().current_token() ==DIVIDE){
        type = 2; 
        global_parser.consume();
        term_ptr->parse();
    }
}
//<term> ::= <factor> | <factor> MULTIPLY <term> | <factor> DIVIDE <term>
void Term::print(){
    factor.print();

    if(type == 1){
        std::cout << " mushroom "<< std::endl;
        term_ptr->print();
    }else if(type == 2){
        std::cout << " dichotomize "<< std::endl;
        term_ptr->print();
    }
}