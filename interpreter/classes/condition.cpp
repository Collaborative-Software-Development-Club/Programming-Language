#include "headers/condition.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>

void Condition::parse() {
    simple token = global_parser.token_stream.value().current_token();
    if(token == NAME){ //Compare case
        name = global_parser.token_stream.value().get_name();
        compare.parse();
        caseType = 1;
        token = global_parser.token_stream.value().current_token();
        
        if(token == OR){// compare or condition case!
            global_parser.consume();
            cond2->parse();
            caseType = 3;
        }else if (token == AND){
            global_parser.consume();
            cond2->parse();
            caseType = 4;
        }

    }else if(token == NOT){
        global_parser.consume();
        cond2->parse();
        caseType = 2;
    }
}

void Condition::print() {
    //caseType 1 == Compare only
    //2 == Not condition
    //3 == OR case
    //4 == and case
    if(caseType == 2){
        std::cout << "!";
        cond2->print();
    }else{
        compare.print();

        if(caseType == 3){
            std::cout << " or ";
            cond2->print();
        }else if(caseType == 4){
            std::cout << " and ";
            cond2->print();
        }
    }
    
}