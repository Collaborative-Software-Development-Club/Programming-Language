#include "headers/statement.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>

void Statement::parse(){
    switch(global_parser.token_stream.value().current_token()){
        case NAME: 
            assign.parse();
            type = 0;
            break; 
        case IF: 
            ifBlock.parse();
            type = 1; 
            break; 
        case WHILE: 
            loop.parse(); 
            type = 2; 
            break; 
        case PRINT: 
            print1.parse(); 
            type = 3; 
            break; 
        case NUM: 
            declare.parse(); 
            type = 4; 
            break; 
        default: 
            break;
    }   
}

void Statement::print(){
    switch(type){
        case 0: 
            assign.print();
            break; 
        case 1: 
            ifBlock.print();
            break; 
        case 2: 
            loop.print(); 
            break; 
        case 3: 
            print1.print(); 
            break; 
        case 4: 
            declare.print(); 
            break; 
        default: 
            break;

    }
}