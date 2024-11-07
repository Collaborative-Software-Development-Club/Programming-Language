#ifndef SCANNER_H
#define SCANNER_H

#include <string>
#include "../../simple.cpp" // Assuming you have this file for simple tokens
#include <vector>
#include <queue>
#include <fstream>
#include <iostream>


class Scanner {
    private:
        std::vector<char> char_stream; // character stream
        int char_pointer; // a pointer to walk through the vector
        simple curr_token; // the current token
        int curr_number; // the int value of the most recent (or current) 'NUMBER' token
        std::string curr_name; // the string value of the most recent (or current) 'NAME' token
        std::queue<std::string> q;

    public:
        // Constructor to initialize the Scanner with a file
        Scanner(std::string f);
        int is_num(std::string t);
        // Returns the current token without advancing to the next one
        simple current_token();

        // Advances to the next token in the stream
        void next_token();


        // Returns the name if the current token is 'NAME', otherwise throws an error
        std::string get_name();

        // Returns the number if the current token is 'NUMBER', otherwise throws an error
        int get_number();
};

#endif // SCANNER_H
