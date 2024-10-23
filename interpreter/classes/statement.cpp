#include "headers/statement.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>

void Statement::parse() {
    std::cout << "entered s" << std::endl;
    int curr = global_parser.token_stream.value().current_token();
    if (curr == NAME) {
        Assign a;
        a.parse();
        std::cout << "done assign" << std::endl;
        
    }  
    else if (curr == IF) {
        If i;
        i.parse();
    }
    else if (curr == WHILE) {
        Loop l;
        l.parse();
    }
    else if (curr == PRINT) {
        Print p;
        p.parse();
    }
    else if (curr == NUM) {
        Declare d;
        d.parse();
    }
    else {
        std::cout << "ERROR: Expected NAME, IF, WHILE, PRINT, OR NUM!" << std::endl;
        exit(-1);
    }
    // switch(curr) {
    //     case NAME:
        
    //     break;
    //     case IF:
    //     statementType = 1;
    //     ifBlock->parse();
    //     break;
    //     case WHILE:
    //     statementType = 2;
    //     loop->parse();
    //     break;
    //     case PRINT:
    //     statementType = 3;
    //     printS.parse();
    //     break;
    //     case NUM:
    //     statementType = 4;
    //     declare.parse();
    //     break;
    //     default:
    //     std::cout << "ERROR: Expected NAME, IF, WHILE, PRINT, OR NUM!" << std::endl;
    //     exit(-1);
    //     break;
    // }
}

void Statement::print() {
    // switch(statementType) {
    //     case 0:
    //     assign->print();
    //     break;
    //     case 1:
    //     ifBlock->print();
    //     break;
    //     case 2:
    //     loop->print();
    //     break;
    //     case 3:
    //     printS.print();
    //     break;
    //     case 4:
    //     declare.print();
    //     break;
    //     default:
    //     break;
    // }
}