#include <iostream>
#include <string>
#include "scanner.cpp"

using namespace std;

// Helper function to display the name of the token for debugging
string token_to_string(simple token) {
    switch (token) {
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
        Scanner scanner(argv[1]);

        // Scan through tokens in the file
        scanner.next_token();
        while (scanner.current_token() != EOS) {
            // Display the token type
            cout << "Token: " << token_to_string(scanner.current_token()) << endl;

            // If the token is NAME or NUMBER, display the corresponding value
            if (scanner.current_token() == NAME) {
                cout << "Name: " << scanner.get_name() << endl;
            } else if (scanner.current_token() == NUMBER) {
                cout << "Number: " << scanner.get_number() << endl;
            }

            // Move to the next token
            scanner.next_token();
        }

        return 0;
    } else {
        cerr << "ERROR: No file argument specified!" << endl;
        return -1;
    }
}
