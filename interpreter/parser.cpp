#include "classes/headers/parser.h"
#include <iostream>

// Define the global Parser object
Parser global_parser;

void Parser::initialize_parser(std::string f) {
    token_stream = Scanner(f);
    //std::cout << "HELLO" << std::endl;
}

void Parser::parse_all() {
    //p.parse(); // Call parse on the program object
}

void Parser::print_all() {
    //p.print(); // Print the program
}