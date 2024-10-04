#include "classes/headers/parser.h"
#include "classes/headers/program.h"
#include "simple.cpp"
#include <iostream>

using namespace std;

// Define the global Parser object
Parser global_parser;

void Parser::initialize_parser(std::string f) {
    token_stream = Scanner(f);
}

void Parser::parse_all() {
    p.parse(); // Call parse on the program object
}

void Parser::print_all() {
    p.print(); // Print the program
}

void Parser::check(simple check) {
    if (token_stream && token_stream.value().current_token() != check) {
        cerr << "ERROR: Expected " << check << ", " << " got " << token_stream.value().current_token() << endl;
        exit(-1);
    }
}

void Parser::consume() {
    if (token_stream) {
        token_stream.value().next_token();
    }
}

int Parser::get_num() {
    if (token_stream) {
        token_stream.value().get_number();
    }
}

string Parser::get_name() {
    if (token_stream) {
        token_stream.value().get_name();
    }
}