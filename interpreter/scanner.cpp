#include <iostream>
#include <string>
#include <fstream>
#include "simple.cpp" // Include simple types for token representation

using namespace std;

#ifndef SCANNER_H
#define SCANNER_H

class Scanner {
    private:
        simple currToken; // The current token
        int currNumber; // The value of the most recent NUMBER token
        string currName; // The name of the most recent NAME token
        ifstream file; // Input file stream

    public:
        // Constructor: Opens the specified file
        Scanner(string f) {
            file.open(f);
            if (!file.is_open()) {
                // Error if the file can't be opened
                cerr << "Error: File not found: " << f << endl;
                exit(1);
            } else cout << "File successfully opened" << endl;
        }

        // Deconstructor: Closes the file if it's open
        ~Scanner() {
            if (file.is_open()) file.close();
        }

        // Handles identifiers and keywords
        void handleIdentifier(char firstChar) {
            string name;

            // Start building the name
            name += firstChar;

            char ch;

            // Read until non-alphanumeric character
            while (file.get(ch) && isalnum(ch)) name += ch;

            // Put the last character back
            file.unget();

            // Match against known keywords
            if      (name == "program")   currToken = PROGRAM;
            else if (name == "print")     currToken = PRINT;
            else if (name == "int")       currToken = INT;
            else if (name == "while")     currToken = WHILE;
            else if (name == "if")        currToken = IF;
            else if (name == "elif")      currToken = ELIF;
            else if (name == "else")      currToken = ELSE;
            else if (name == "not")       currToken = NOT;
            else if (name == "and")       currToken = AND;
            else if (name == "or")        currToken = OR;
            else {
                // If it's not a keyword, treat as a NAME
                currToken = NAME;

                // Store the name
                currName = name;
            }
        }

        // Handles number tokens
        void handleNumber(char firstDigit) {
            // Start building the number
            int num = firstDigit - '0';

            char ch;

            // Read until non-digit
            while (file.get(ch) && isdigit(ch)) num = num * 10 + (ch - '0');
            
            // Put the last character back
            file.unget();

            // Set the current token as NUMBER
            currToken = NUMBER;

            // Store the value of the number
            currNumber = num;
        }

        // Handles multi-character operators
        void handleMultiChar(char ch) {
            char nextCh;

            if (file.get(nextCh)) {
                if      (ch == '=' && nextCh == '=') currToken = EQUAL;
                else if (ch == '*' && nextCh == '*') currToken = POWER;
                else if (ch == '!' && nextCh == '=') currToken = NOTEQUAL;
                else if (ch == '<' && nextCh == '=') currToken = LTE;
                else if (ch == '>' && nextCh == '=') currToken = GTE;
                else {
                    // Put the last character back
                    file.unget();

                    // If not a multi-character, treat it as a single-character
                    handleSingleChar(ch);
                }
            } else handleSingleChar(ch);
        }

        // Handles single-character tokens
        void handleSingleChar(char ch) {
            if      (ch == ';') currToken = SEMICOLON;
            else if (ch == '=') currToken = ASSIGN;
            else if (ch == '(') currToken = LPAREN;
            else if (ch == ')') currToken = RPAREN;
            else if (ch == '{') currToken = LCURL;
            else if (ch == '}') currToken = RCURL;
            else if (ch == '+') currToken = ADD;
            else if (ch == '-') currToken = SUBTRACT;
            else if (ch == '*') currToken = MULTIPLY;
            else if (ch == '/') currToken = DIVIDE;
            else if (ch == '%') currToken = MOD;
            else if (ch == '<') currToken = LT;
            else if (ch == '>') currToken = GT;
            else {
                // Error for invalid symbols
                cerr << "Invalid symbol: " << ch << endl;
                exit(1);
            }
        }

        // Advances to the next token
        void nextToken() {
            char ch;

            while (file.get(ch)) {
                // Slip whitespace
                if (isspace(ch)) continue;

                if (isalpha(ch)) {
                    // Handle identifiers
                    handleIdentifier(ch);
                    return;
                }

                if (isdigit(ch)) {
                    // Handle numbers
                    handleNumber(ch);
                    return;
                }
                
                if (ch == '=' || ch == '*' || ch == '<' || ch == '>' || ch == '!') {
                    // Handle multi-character tokens
                    handleMultiChar(ch);
                    return;
                }

                // Handle single-character tokens
                handleSingleChar(ch);
                return;
            }

            // End of file reached
            currToken = EOS;
        }

        // Returns the current token
        simple currentToken() {
            return currToken;
        }

        // Gets the current name value
        string getName() {
            if (currToken == NAME) return currName;
            else {
                cerr << "Error: Current token is not a NAME" << endl;
                exit(1);
            }
        }

        // Gets the current number value
        int getNumber() {
            if (currToken == NUMBER) return currNumber;
            else {
                cerr << "Error: Current token is not a NUMBER" << endl;
                exit(1);
            }
        }
};

#endif