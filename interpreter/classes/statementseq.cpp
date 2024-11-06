#include "headers/statementseq.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>

void StatementSeq::parse() {
    s = std::make_unique<Statement>();
    s->parse();
    int curr = global_parser.token_stream.value().current_token();
    if (curr == NAME || curr == IF || curr == WHILE || curr == PRINT || curr == NUM) {
        ss = std::make_unique<StatementSeq>();
        ss->parse();
    }
}

void StatementSeq::print() {
    s->print();
    if (ss != nullptr) ss->print();
}

void StatementSeq::execute() {
    s->execute();
    if (ss != nullptr) ss->execute();
}