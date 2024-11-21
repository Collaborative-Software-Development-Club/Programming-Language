#include "headers/condition.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>
#include <memory>

void Condition::parse() {
    if (global_parser.token_stream.value().current_token() == NOT) {
        global_parser.check(NOT);
        global_parser.consume();
        cndType = 1;
        cnd = std::make_unique<Condition>();
        cnd->parse();
    }
    else {
        cpr = std::make_unique<Compare>();
        cpr->parse();
        if (global_parser.token_stream.value().current_token() == OR) {
            global_parser.consume();
            cndType = 2;
            cnd = std::make_unique<Condition>();
            cnd->parse();
        }
        else if (global_parser.token_stream.value().current_token() == AND) {
            global_parser.consume();
            cndType = 3;
            cnd = std::make_unique<Condition>();
            cnd->parse();
        }
    }
}

void Condition::print() {
    switch (cndType) {
        case 0:
        cpr->print();
        break;
        case 1:
        std::cout << " ! ";
        cnd->print();
        break;
        case 2:
        cpr->print();
        std::cout << " | ";
        cnd->print();
        break;
        case 3:
        cpr->print();
        std::cout << " & ";
        cnd->print();
        break;
        default:
        break;
    }
}

bool Condition::execute(){
    switch(cndType){
        case 0:
        return cpr->execute();
        break; 
        case 1:
        return !cpr->execute();
        break;
        case 2:
        return cpr->execute() || cnd->execute();
        case 3:
        return cpr->execute() && cnd->execute();
        break;
        default:
        return false;
        break;
    }
}