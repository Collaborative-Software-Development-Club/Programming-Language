#include "headers/statement.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>

void Statement::parse() {
    statementype = -1;
    //statement type keeps track of what is used for printing...

    simple token = global_parser.token_stream.value().current_token();
    if(token == NAME){
        assign.parse();
        statementype = 1;
    }else if(token == IF){
        ifBlock.parse();
        statementype = 2;
    }else if(token == WHILE){
        loop.parse();
        statementype = 3;
    }else if(token == PRINT){
        prints.parse();
        statementype = 4;
    }else if(token == NUM){
        declare.parse();
        statementype = 5;
    }
}

void Statement::print() {
    switch(statementype){
        case 1:
            assign.print();
            break;
        case 2:
            ifBlock.print();
            break;
        case 3:
            loop.parse();
            break;
        case 4:
            prints.parse();
            break;
        case 5:
            declare.parse();
            break;
        default:
            std::cerr << "statement type print was called, however did not parse the tokens correctly..." << endl;
            //do nothing...
            break;
    }
}