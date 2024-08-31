#include <iostream>
#include <string>
#include "simple.cpp"

using namespace std;

#ifndef SCANNER_H
#define SCANNER_H

class Scanner {
    private:

        // you may either keep an array or a list of all characters in the stream, or...
        // ...keep the file stream open, and read only characters that you need at the moment!

        simple curr_token; // the current token
        int curr_number; // the int value of the most recent (or current) 'NUMBER' token
        string curr_name; // the string value of the most recent (or current) 'NAME' token

    public:
        Scanner(string f) {
            // use filename argument 'f' to open the file, read characters as needed, and eventually close
            // the file stream

            // if we cannot find the specified file, gracefully return an error and exit
        }

        simple current_token() {
            // all you have to do here is return the currently stored token without going to the next one
            return EOS;
        }

        void next_token() {
            // find the next available token in the scanning stream, covert it into a token, store it
            // NOTE: this will be your longest method!
        }

        string get_name() {
            // if the current token is 'NAME', return the string value of the name, else throw an error
            return "";
        }

        int get_number() {
            // if the current token is 'NUMBER', return the int value of the number, else throw an error
            return 0;
        }
};

#endif