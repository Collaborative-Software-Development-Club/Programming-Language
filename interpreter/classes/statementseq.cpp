#include "headers/statementseq.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>

void StatementSeq::parse() {
    s.parse();
    simple candidate = global_parser.token_stream.value().current_token();
    if (candidate ==  NAME || candidate == IF || candidate == WHILE || candidate == PRINT || candidate == NUM) {
        ss->parse();
    }
}

void StatementSeq::print() {
    s.print();
    if (ss != nullptr) ss->print();
}