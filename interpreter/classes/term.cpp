#include "headers/term.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>
#include <memory>

void Term::parse() {
    fcr = std::make_unique<Factor>();
    fcr->parse();
    if (global_parser.token_stream.value().current_token() == MULTIPLY) {
        global_parser.consume();
        termType = 1;
        trm = std::make_unique<Term>();
        trm->parse();
    }
    else if (global_parser.token_stream.value().current_token() == DIVIDE) {
        global_parser.consume();
        termType = 2;
        trm = std::make_unique<Term>();
        trm->parse();
    }
}

void Term::print() {
    fcr->print();
    if (termType == 1) {
        std::cout << " * ";
        trm->print();
    }
    else if (termType == 2) {
        std::cout << " / ";
        trm->print();
    }
}

int Term::execute() {
    if (termType == 0) {
        return fcr->execute();
    }
    else if (termType == 1) {
        return fcr->execute() * trm->execute();
    }
    else {
        return fcr->execute() / trm->execute();
    }
}