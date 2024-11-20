#include "headers/expression.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>
#include <memory>

void Expression::parse() {
    trm = std::make_unique<Term>();
    trm->parse();
    if (global_parser.token_stream.value().current_token() == ADD) {
        global_parser.consume();
        exprType = 1;
        expr = std::make_unique<Expression>();
        expr->parse();
    }
    else if (global_parser.token_stream.value().current_token() == SUBTRACT) {
        global_parser.consume();
        exprType = 2;
        expr = std::make_unique<Expression>();
        expr->parse();
    }
}

void Expression::print() {
    trm->print();
    if (exprType == 1) {
        std::cout << " + ";
        expr->print();
    }
    else if (exprType == 2) {
        std::cout << " - ";
        expr->print();
    }
}

int Expression::execute(){
    if(exprType == 0){
        return trm->execute();
    }
    else if(exprType == 1){
        return trm->execute() + expr -> execute();
    }
    else{
        return trm->execute() - expr->execute();
    }
}