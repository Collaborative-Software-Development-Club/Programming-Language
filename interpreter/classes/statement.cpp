#include "headers/statement.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>
#include <memory>

void Statement::parse() {
    int curr = global_parser.token_stream.value().current_token();
    if (curr == NAME) {
        asn = std::make_unique<Assign>();
        statementType = 0;
        asn->parse();
    }  
    else if (curr == IF) {
        ifst = std::make_unique<If>();
        statementType = 1;
        ifst->parse();
    }
    else if (curr == WHILE) {
        lp = std::make_unique<Loop>();
        statementType = 2;
        lp->parse();
    }
    else if (curr == PRINT) {
        prnt = std::make_unique<Print>();
        statementType = 3;
        prnt->parse();
    }
    else if (curr == NUM) {
        decl = std::make_unique<Declare>();
        statementType = 4;
        decl->parse();
    }
    else {
        std::cout << "ERROR: Expected NAME, IF, WHILE, PRINT, OR NUM!" << std::endl;
        exit(-1);
    }
}

void Statement::print() {
    switch(statementType) {
        case 0:
        asn->print();
        break;
        case 1:
        ifst->print();
        break;
        case 2:
        lp->print();
        break;
        case 3:
        prnt->print();
        break;
        case 4:
        decl->print();
        break;
        default:
        break;
    }
}