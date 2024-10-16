#include "classes/headers/parser.h"
#include "classes/headers/program.h"
#include "simple.cpp"
#include <iostream>

using namespace std;

// Define the global Parser object
Parser global_parser; //class defined in the class headers file.

//these functions actually initialize the functions declared in the header file...
//define the functions for the Parser class...
void Parser::initialize_parser(std::string f) { //f is the file to be scanned.
    token_stream = Scanner(f); //defines the token_stream from the header file.
}

void Parser::parse_all() {
    p.parse(); // Call parse on the program object
    //called on program as its the start of the parseTree!
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
    }else{
        cout <<"OUT OF TOKENS!" << endl;
    }
}

int Parser::get_num() {
    if (token_stream) {
        return token_stream.value().get_number();
    }
    else return -1;
}

string Parser::get_name() {
    if (token_stream) {
        return token_stream.value().get_name();
    }
    else return "";
}