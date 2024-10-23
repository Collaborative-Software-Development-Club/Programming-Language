#include "headers/expression.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>

void Expression::parse(){

    term.parse();
    t = 0;

    if(global_parser.token_stream.value().current_token() ==AND){
        t = 1; 
        global_parser.consume();
    }else if(global_parser.token_stream.value().current_token() == SUBTRACT ){
        t=2;
        global_parser.consume();
    }

    ex_ptr->parse();
}

void Expression::print(){
    term.print();

    switch(t){
        case 1: 
           std::cout << " replenish "<< std::endl;
           ex_ptr->print();
           break; 
        case 2: 
            std::cout << " diminish "<< std::endl;
            ex_ptr->print();
            break;
    }
}