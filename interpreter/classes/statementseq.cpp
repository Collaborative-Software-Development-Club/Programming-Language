#include "headers/statementseq.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>

void StatementSeq::parse() {
    statement.parse(); //know there must be a statement.
    
    //check if the next token is a statement-sequence or not...
    simple currentToken = global_parser.token_stream.value().current_token();
    if(currentToken == NAME || currentToken == IF || currentToken == WHILE || currentToken == PRINT || currentToken == NUM){
        //Then we have a statement sequence!
        StatementSeq::parse();
    }

}

void StatementSeq::print() {
    statement.print();
}