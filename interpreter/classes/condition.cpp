#include "headers/condition.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>

void Condition::parse() {
    //<condition> ::= <compare> | NOT <condition> | <compare> OR <condition> 
    //| <compare> AND <condition>
    simple token = global_parser.token_stream.value().current_token();
    if(token != NOT){
        compare.parse();
        if(token == OR){
            global_parser.consume();
            condition2->parse();
            conditionType = 1;// OR type needs to be printed...
        }else if(token == AND){
            global_parser.consume();
            condition2->parse();
            conditionType = 2;// AND type needs to be printed... 
        }//else if was just a compare...
    }else{  //not case
        global_parser.consume();
        condition2->parse();
    }

}

void Condition::print() {
    if(conditionType==3){
        std::cout << "!";
        condition2->print();
    }else if(conditionType == 1){
        compare.print();
        std::cout << " || ";
        condition2->print();
    }else if(conditionType == 2){
        compare.print();
        std::cout << " && ";
        condition2->print();
    }else{
        compare.print();
    }
}