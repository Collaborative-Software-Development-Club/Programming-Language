#include "headers/compare.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream> 

void Compare::parse(){
    expression.parse();
    
    if(global_parser.token_stream.value().current_token() == LESS){
        isLess = true; 
        global_parser.consume();
    }else if(global_parser.token_stream.value().current_token() == EQUAL){
        global_parser.consume();
    }
    expression2.parse();
}


void Compare::print(){
    expression.print();

    if(isLess){
        std::cout<<" beneath "<<std::endl;
    }else{
        std::cout<<" commensurate "<<std::endl;
    }

    expression2.print();
}


//<compare> ::= <expression> EQUALS <expression> | <expression> LESS <expression>
