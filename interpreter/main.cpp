#include <iostream>
#include <string>
#include "scanner.cpp"

using namespace std;

int main(int argc, char* argv[]) {

    vector<string> enum_strings = { // enums represented as strings. for debugging only!
        "PROGRAM",
        "NAME",
        "ASSIGN",
        "SEMICOLON",
        "PRINT",
        "IF",
        "ELSE",
        "WHILE",
        "LPAREN",
        "RPAREN",
        "LCURL",
        "RCURL",
        "NOT",
        "OR",
        "AND",
        "EQUAL",
        "LESS",
        "ADD",
        "SUBTRACT",
        "MULTIPLY",
        "DIVIDE",
        "NUMBER",
        "NUM",
        "EOS"
    };

    if (argc > 1) {
        Scanner s (argv[1]);
        s.next_token();
        while (s.current_token() != EOS) { // get tokens till end of stream
            cout << enum_strings[s.current_token()];
            if (s.current_token() == NAME) {
                cout << "[" << s.get_name() << "]";
            }
            else if (s.current_token() == NUMBER) {
                cout << "[" << s.get_number() << "]";
            }
            cout << endl;
            s.next_token();
        }
        return 0;
    }
    else { // in case our code has no arguments
        cerr << "ERROR: No file argument specified!" << endl;
        return -1;
    }
}