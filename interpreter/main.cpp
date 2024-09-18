#include <iostream>
#include <string>
#include "scanner.cpp"
#include "parser.cpp"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc > 1) {
        Parser::initialize_parser(argv[1]);
        Parser::parse_all();
        Parser::print_all();
    }
    else { // in case our code has no arguments
        cerr << "ERROR: No file argument specified!" << endl;
        return -1;
    }
}