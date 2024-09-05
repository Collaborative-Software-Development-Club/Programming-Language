#include <iostream>
#include <fstream>
#include <string>
#include "simple.cpp"
#include <vector>

using namespace std;

#ifndef SCANNER_H
#define SCANNER_H

class Scanner {
    private:

        vector<char> char_stream; // character stream
        int char_pointer = 0; // a pointer to walk through the vector

        simple curr_token; // the current token
        int curr_number; // the int value of the most recent (or current) 'NUMBER' token
        string curr_name; // the string value of the most recent (or current) 'NAME' token

        // helper functions
        bool is_number(string s) { // determines if the string is a number
            for (char c : s) {
                if (!isdigit(c)) return false;
            }
            return true;
        }
        bool is_letter(string s) { // determines if the string is a word
            for (char c : s) {
                if (!isalpha(c)) return false;
            }
            return true;
        }
        bool is_symbol(string s) { // determines if the string is a symbol or not
            for (char c : s) {
                if (!isalpha(c) && !isdigit(c)) return true;
            }
            return false;
        }
        void symbol_check(string s) { // helper function for getting symbols
            if (s.compare("=") == 0) {
                curr_token = ASSIGN;
            }
            else if (s.compare(";") == 0) {
                curr_token = SEMICOLON;
            }
            else if (s.compare("(") == 0) {
                curr_token = LPAREN;
            }
            else if (s.compare(")") == 0) {
                curr_token = RPAREN;
            }
            else if (s.compare("{") == 0) {
                curr_token = LCURL;
            }
            else if (s.compare("}") == 0) {
                curr_token = RCURL;
            }
            else if (s.compare("!") == 0) {
                curr_token = NOT;
            }
            else if (s.compare("|") == 0) {
                curr_token = OR;
            }
            else if (s.compare("&") == 0) {
                curr_token = AND;
            }
            else if (s.compare("<") == 0) {
                curr_token = LESS;
            }
            else if (s.compare("+") == 0) {
                curr_token = ADD;
            }
            else if (s.compare("-") == 0) {
                curr_token = SUBTRACT;
            }
            else if (s.compare("*") == 0) {
                curr_token = MULTIPLY;
            }
            else if (s.compare("/") == 0) {
                curr_token = DIVIDE;
            }
            else {
                cerr << "ERROR: Invalid syntax error!" << endl;
                exit(-1);
            }
        }
        bool keyword_check(string s) { // check if there are any valid keywords, return false if not
            bool found = true;
            if (s.compare("program") == 0) {
                curr_token = PROGRAM;
            }
            else if (s.compare("out") == 0) {
                curr_token = PRINT;
            }
            else if (s.compare("if") == 0) {
                curr_token = IF;
            }
            else if (s.compare("else") == 0) {
                curr_token = ELSE;
            }
            else if (s.compare("while") == 0) {
                curr_token = WHILE;
            }
            else if (s.compare("num") == 0) {
                curr_token = NUM;
            }
            else found = false;
            return found;
        }

    public:
        Scanner(string f) { // constructor for scanner
            ifstream fstrm(f);
            string line;
            if (!fstrm.is_open()) {
                cerr << "ERROR: File failed to open!" << endl;
                return;
            }
            else {
                while (getline(fstrm, line)) { // get all characters from the stream
                    for (char c : line) {
                        char_stream.push_back(c);
                    }
                }
                fstrm.close();
            }
        }

        simple current_token() { // returns current token
            return curr_token;
        }

        void next_token() { // finds next valid token
            string token_string = "";
            char token_c;
            while (curr_token != EOS) {
                token_c = char_stream[char_pointer];
                if (char_pointer != char_stream.size() && token_c != ' ' && token_c != '\n' && token_c != '\0' && token_c != '\t') { // checking for any potential whitespace
                    token_string += token_c; // if not whitespace, append to string
                    if (!isdigit(char_stream[char_pointer + 1]) && !isalpha(char_stream[char_pointer + 1]) && keyword_check(token_string)) {
                        // if the current word looks like a keyword and has nothing leading it, it's a keyword
                        char_pointer++;
                        break;
                    }
                    else if ((!isdigit(char_stream[char_pointer + 1]) && !isalpha(char_stream[char_pointer + 1])) || is_symbol(token_string)) { // check if we still have valid chars ahead
                        if (is_number(token_string)) { // check if a full number
                            curr_token = NUMBER;
                            curr_number = stoi(token_string);
                            if (curr_number < 0 || curr_number > 1000000) { // check for too big
                                cerr << "ERROR: NUMBER value too large!" << endl;
                                exit(-1);
                            }
                            char_pointer++;
                            break;
                        }
                        else if (is_symbol(token_string)) {
                            if (token_c == '=' && char_stream[char_pointer + 1] == '=') { // i only need to check '==', otherwise it's one character symbol
                                curr_token = EQUAL;
                                char_pointer += 2;
                                break;
                            }
                            else {
                                symbol_check(token_string);
                                char_pointer++;
                                break;
                            }
                        }
                        else { // anything else is a variable name
                            curr_token = NAME;
                            curr_name = token_string;
                            char_pointer++;
                            break;
                        }
                    }
                }
                else if (char_pointer >= char_stream.size() - 1) { // get eos token here
                    curr_token = EOS;
                }
                char_pointer++;
            }
        }

        string get_name() { // get the name of the token, otherwise return an error
            if (curr_token == NAME) {
                return curr_name;
            }
            else {
                cerr << "ERROR: Token is not of type NAME!" << endl;
                exit(-1);
                return "";
            }
        }

        int get_number() { // get the number of a num token, otherwise return an error
            if (curr_token == NUMBER) {
                return curr_number;
            }
            else {
                cerr << "ERROR: Token is not of type NUMBER!" << endl;
                exit(-1);
                return -1;
            }
        }
};

#endif
