#include <iostream>
#include "scanner.cpp"

using namespace std;

const string tokenNames[] = {
    "PROGRAM", "NAME", "ASSIGN", "SEMICOLON", "PRINT", "IF", "ELIF", "ELSE", "WHILE",
    "LPAREN", "RPAREN", "LCURL", "RCURL", "NOT", "OR", "AND", "EQUAL", "NOTEQUAL", 
    "LT", "GT", "LTE", "GTE", "ADD", "SUBTRACT", "MULTIPLY", "DIVIDE", "POWER", "MOD", "NUMBER", "NUM", "EOS"
};

int main(int argc, char* argv[]) {
    if (argc > 1) {
        Scanner scanner(argv[1]);

        while (scanner.current_token() != EOS) {
            scanner.next_token();
            simple token = scanner.current_token();
            
            cout << tokenNames[token];

            if (token == NAME) {
                cout << " : " << scanner.get_name();
            } else if (token == NUMBER) {
                cout << " : " << scanner.get_number();
            }

            cout << endl;
        }

        return 0;
    }
    else {
        cerr << "ERROR: No file argument specified!" << endl;
        return -1;
    }
}
