#include "headers/condition.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>

void Condition::parse() {
    if (global_parser.token_stream.value().current_token() == NOT) {
        global_parser.check(NOT);
        global_parser.consume();
        cnd->parse();
    }
    else {
        
    }
}

void Condition::print() {
    
}