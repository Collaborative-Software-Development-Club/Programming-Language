#include "headers/condition.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>

void Condition::parse(){
    type = 1;
    if(global_parser.token_stream.value().current_token() == NOT){
        global_parser.consume();
        type = 2; 
        cnd_ptr->parse();        
    }else{
        compare.parse();
        if(global_parser.token_stream.value().current_token() == OR){
            global_parser.consume();
            type = 3;
            cnd_ptr->parse();
        }else if(global_parser.token_stream.value().current_token() == AND){
            global_parser.consume();
            type = 4; 
            cnd_ptr->parse();
        }   
    }
}

void Condition::print(){
    switch(type){
        case 1: 
            compare.print();
            break;
        case 2: 
            std::cout << " nay "<< std::endl;
            cnd_ptr->print();
            break;
        case 3: 
           compare.print();
           std::cout << " disjunction "<< std::endl;
           cnd_ptr->print();
        case 4: 
           compare.print();
           std::cout << " moreover "<< std::endl;
           cnd_ptr->print();     

    }
}