#include <iostream>
#include <string>
#include "classes/headers/globals.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc > 1) {
        global_parser.initialize_parser(argv[1]);
        //global_parser.parse_all();
        //global_parser.print_all();
    }
    else { // in case our code has no arguments
        cerr << "ERROR: No file argument specified!" << endl;
        return -1;
    }
}