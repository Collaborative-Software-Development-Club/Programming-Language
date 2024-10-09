#include "headers/statement.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>

void Statement::parse() {
    switch(global_parser.token_stream.value().current_token()) {
        case NAME:
        statementType = 0;
        assign.parse();
        break;
        case IF:
        statementType = 1;
        ifBlock.parse();
        break;
        case WHILE:
        statementType = 2;
        loop.parse();
        break;
        case PRINT:
        statementType = 3;
        printS.parse();
        break;
        case NUM:
        statementType = 4;
        declare.parse();
        break;
        default:
        break;
    }
}

void Statement::print() {
    switch(statementType) {
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
        printS.print();
        break;
        case 4:
        declare.print();
        break;
        default:
        break;
    }
}