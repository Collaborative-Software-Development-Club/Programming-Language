#include "headers/program.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>

using namespace std;

void Program::parse() {
    //global_parser.consume(); 
    //FOR DEBUG IF THERE'S AN EXTRA TOKEN!
    
    //know there must be a program token.
    global_parser.check(PROGRAM);
    global_parser.consume();

    global_parser.check(NAME);
    program_name = global_parser.get_name();
    global_parser.consume();

    global_parser.check(LCURL);
    global_parser.consume();

    ss.parse(); //defined in the Program header record...

    global_parser.check(RCURL);
    global_parser.consume();
}
void Program::print() {
    cout << "program " << program_name << " { " << endl;
    ss.print();
    cout << "}" << endl;
}