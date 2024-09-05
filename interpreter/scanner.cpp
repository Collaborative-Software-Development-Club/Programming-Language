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
        int char_pointer = 0;

        simple curr_token; // the current token
        int curr_number; // the int value of the most recent (or current) 'NUMBER' token
        string curr_name; // the string value of the most recent (or current) 'NAME' token

        // helper functions
        bool is_number(string s) {
            for (char c : s) {
                if (!isdigit(c)) return false;
            }
            return true;
        }
        bool is_letter(string s) {
            for (char c : s) {
                if (!isalpha(c)) return false;
            }
            return true;
        }

    public:
        Scanner(string f) {
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

        simple current_token() {
            return curr_token;
        }

        void next_token() {
            string token_string = "" + char_stream[char_pointer];
            char_pointer++;
            if (char_stream[char_pointer] == ' ' || char_stream[char_pointer] == '\n' || char_stream[char_pointer] == '\0') { // not valid input
                if (!is_number(token_string) && !is_letter(token_string)) { // must be symbolic
                    if (token_string.compare("==") == 0) {
                        curr_token = EQUAL;
                    }
                    else if (token_string.compare("==") == 0)
                }
            }
        }

        string get_name() {
            if (curr_token == NAME) {
                return curr_name;
            }
            else {
                cerr << "ERROR: Token is not of type NAME!" << endl;
                return "";
            }
        }

        int get_number() {
            if (curr_token == NUMBER) {
                return curr_number;
            }
            else {
                cerr << "ERROR: Token is not of type NUMBER!" << endl;
                return -1;
            }
        }
};

#endif
