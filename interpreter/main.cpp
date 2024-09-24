#include <iostream>
#include "scanner.cpp" // Include the Scanner class
#include "parser.cpp" // Include the Parser class

using namespace std;

int main(int argc, char* argv[]) {
    // Check if a filename is provided as a command line argument
    if (argc > 1) {
        Parser parser(argv[1]);
        parser.parse();
        cout << "Parsing completed successfully!" << endl;
        
        return 0;
    } else {
        // Error message if no filename is provided
        cerr << "ERROR: No file argument specified!" << endl;
        return -1;
    }
}
