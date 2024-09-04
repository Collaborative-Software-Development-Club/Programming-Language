#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>
#include "simple.cpp"

using namespace std;

#ifndef SCANNER_H
#define SCANNER_H

class Scanner {
private:
    vector<simple> tokens; // Stores all identified tokens
    vector<char> stream; // Stores the input character stream
    simple curr_token; // Current token being processed
    int curr_number; // Current number if the token is a number
    string curr_name; // Current name if the token is a name
    size_t stream_pos = 0; // Current position in the stream

    // Helper function to skip whitespace
    void skip_whitespace() {
        while (stream_pos < stream.size() && isspace(stream[stream_pos])) {
            stream_pos++;
        }
    }

    // Helper function to check for valid letters in names
    bool is_name_char(char c) {
        return isalpha(c) || c == '_';
    }

    // Helper function to read a name
    string read_name() {
        string name = "";
        while (stream_pos < stream.size() && is_name_char(stream[stream_pos])) {
            name += stream[stream_pos];
            stream_pos++;
        }
        return name;
    }

    // Helper function to read a number
    int read_number() {
        int num = 0;
        while (stream_pos < stream.size() && isdigit(stream[stream_pos])) {
            num = num * 10 + (stream[stream_pos] - '0');
            stream_pos++;
        }
        return num;
    }

public:
    Scanner(string filename) {
        ifstream file(filename);
        if (!file) {
            cerr << "ERROR: Cannot open file: " << filename << endl;
            exit(EXIT_FAILURE);
        }

        // Read file contents into stream
        char c;
        while (file.get(c)) {
            stream.push_back(c);
        }
        file.close();
    }

    // Returns the current token without advancing
    simple current_token() {
        return curr_token;
    }

    // Moves to the next token in the input stream
    void next_token() {
        skip_whitespace(); // Skip whitespace before reading the next token

        if (stream_pos >= stream.size()) {
            curr_token = EOS;
            return;
        }

        char c = stream[stream_pos];

        if (is_name_char(c)) {
            // Handle names (like PROGRAM, IF, ELSE, or user-defined variables)
            curr_name = read_name();
            if (curr_name == "PROGRAM") curr_token = PROGRAM;
            else if (curr_name == "PRINT") curr_token = PRINT;
            else if (curr_name == "IF") curr_token = IF;
            else if (curr_name == "ELSE") curr_token = ELSE;
            else if (curr_name == "WHILE") curr_token = WHILE;
            else if (curr_name == "NUM") curr_token = NUM;
            else curr_token = NAME;
        } else if (isdigit(c)) {
            // Handle numbers
            curr_number = read_number();
            curr_token = NUMBER;
        } else {
            // Handle single character tokens and operators
            switch (c) {
                case '=':
                    curr_token = ASSIGN;
                    stream_pos++;
                    break;
                case ';':
                    curr_token = SEMICOLON;
                    stream_pos++;
                    break;
                case '(':
                    curr_token = LPAREN;
                    stream_pos++;
                    break;
                case ')':
                    curr_token = RPAREN;
                    stream_pos++;
                    break;
                case '{':
                    curr_token = LCURL;
                    stream_pos++;
                    break;
                case '}':
                    curr_token = RCURL;
                    stream_pos++;
                    break;
                case '!':
                    curr_token = NOT;
                    stream_pos++;
                    break;
                case '|':
                    curr_token = OR;
                    stream_pos++;
                    break;
                case '&':
                    curr_token = AND;
                    stream_pos++;
                    break;
                case '<':
                    curr_token = LESS;
                    stream_pos++;
                    break;
                case '+':
                    curr_token = ADD;
                    stream_pos++;
                    break;
                case '-':
                    curr_token = SUBTRACT;
                    stream_pos++;
                    break;
                case '*':
                    curr_token = MULTIPLY;
                    stream_pos++;
                    break;
                case '/':
                    curr_token = DIVIDE;
                    stream_pos++;
                    break;
                default:
                    cerr << "ERROR: Unrecognized token: " << c << endl;
                    exit(EXIT_FAILURE);
            }
        }
    }

    // Get the current name token value
    string get_name() {
        if (curr_token == NAME) {
            return curr_name;
        }
        throw runtime_error("ERROR: Current token is not NAME");
    }

    // Get the current number token value
    int get_number() {
        if (curr_token == NUMBER) {
            return curr_number;
        }
        throw runtime_error("ERROR: Current token is not NUMBER");
    }
};

#endif
