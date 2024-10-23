#include "headers/loop.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>

#include "headers/statementseq.h";

void Loop::parse(){
    global_parser.check(WHILE);
    global_parser.consume();

    condition.parse();

    global_parser.check(LCURL);
    global_parser.consume();

    statementSeq.parse();

    global_parser.check(RCURL);
    global_parser.consume();
}
//<loop> ::= WHILE <condition> LCURL <statement-seq> RCURL

void Loop::print(){
    std::cout << " midst "<< std::endl;
    condition.print();
    std::cout << " { "<< std::endl;
    statementSeq.print();
    std::cout << " } "<< std::endl;

}