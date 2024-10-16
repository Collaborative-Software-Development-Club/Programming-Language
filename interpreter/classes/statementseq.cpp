#include "headers/statementseq.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>

void StatementSeq::parse() { 
    statement.parse(); 
    recursive = false; 
    simple iden = global_parser.token_stream.value().current_token();
    if(iden == NAME ||iden == IF || iden == WHILE || iden == PRINT) {
        ss->parse();
        recursive = true; 
    }
}

void StatementSeq::print(){
    statement.print();
    if(recursive){
        ss->print();
    }
}