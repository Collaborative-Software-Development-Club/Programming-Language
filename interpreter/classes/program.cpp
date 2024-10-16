#include "headers/program.h"
#include "../simple.cpp"
#include "headers/globals.h"
#include <iostream>

using namespace std;

void Program::parse(){
    global_parser.consume();
    global_parser.check(PROGRAM);
    global_parser.consume();

    global_parser.check(NAME);
    programName = global_parser.get_name();
    global_parser.consume();

    global_parser.check(LCURL);
    global_parser.consume();

    statementSeq.parse();

    global_parser.check(RCURL);
    global_parser.consume();
}

void Program::print(){
    cout << "program " << programName << " {" << endl;
    statementSeq.print();
    cout << "}" << endl;
}
