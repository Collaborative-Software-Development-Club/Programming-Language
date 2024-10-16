#include "headers/if.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>

void If::parse() {
    isElseToo = 0;
    global_parser.check(IF);
    global_parser.consume();
    condition.parse();

    global_parser.check(LCURL);
    global_parser.consume();

    statementSeq.parse();
    
    global_parser.check(RCURL);
    global_parser.consume();

    if(global_parser.token_stream.value().current_token() == ELSE){
        isElseToo = 1;
        global_parser.consume(); //know the token is else...
        global_parser.check(LCURL);
        global_parser.consume();
        statementSeq2.parse();
        global_parser.check(RCURL);
        global_parser.consume();
    }

}

void If::print() {
    std::cout << "If ";
    condition.print();
    std::cout << "( ";
    statementSeq.print();
    std::cout << ")";
    if(isElseToo){
        std::cout << "else (";
        statementSeq2.print();
        std::cout << ")" << std::endl;
    }
}