#include <iostream>
#include <string>
#include "scanner.cpp"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc > 1) {
        Scanner s (argv[1]);

        // write code here to ensure your tokens are being processed correctly!

        return 0;
    } else { // in case our code has no arguments
        cerr << "ERROR: No file argument specified!" << endl;
        return -1;
    }
}