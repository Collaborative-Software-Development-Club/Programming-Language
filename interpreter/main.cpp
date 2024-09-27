#include <iostream>
#include <string>
#include "scanner.cpp"
#include "simple.cpp"

using namespace std;

// Helper function to convert token to string
// Added this so that it prints the detected tokens in string form to be understandable.
string tokenToString(simple token) {
    switch(token) {
        case PROGRAM: return "PROGRAM";
        case NAME: return "NAME";
        case ASSIGN: return "ASSIGN";
        case SEMICOLON: return "SEMICOLON";
        case PRINT: return "PRINT";
        case IF: return "IF";
        case ELSE: return "ELSE";
        case WHILE: return "WHILE";
        case LPAREN: return "LPAREN";
        case RPAREN: return "RPAREN";
        case LCURL: return "LCURL";
        case RCURL: return "RCURL";
        case NOT: return "NOT";
        case OR: return "OR";
        case AND: return "AND";
        case EQUAL: return "EQUAL";
        case LESS: return "LESS";
        case ADD: return "ADD";
        case SUBTRACT: return "SUBTRACT";
        case MULTIPLY: return "MULTIPLY";
        case DIVIDE: return "DIVIDE";
        case NUMBER: return "NUMBER";
        case NUM: return "NUM";
        case EOS: return "EOS";
        default: return "UNKNOWN";
    }
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        Scanner s (argv[1]);
        s.next_token();
        while (s.current_token() != EOS) {
            cout << tokenToString(s.current_token()) << endl;
            if (s.current_token() == NAME) {
                cout << s.get_name() << endl;
            }
            s.next_token();
        }

        return 0;
    } else { // in case our code has no arguments
        cerr << "ERROR: No file argument specified!" << endl;
        return -1;
    }
}
