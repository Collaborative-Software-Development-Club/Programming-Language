#include <iostream>
#include <string>
#include "simple.cpp"
#include "classes/headers/scanner.h"

using namespace std;

    Scanner::Scanner(string f) {
        // use filename argument 'f' to open the file, read characters as needed, and eventually close
        // the file stream

        // if we cannot find the specified file, gracefully return an error and exit
    }

    simple Scanner::current_token() {
        // all you have to do here is return the currently stored token without going to the next one
        return EOS;
    }

    void Scanner::next_token() {
        // find the next available token in the scanning stream, covert it into a token, store it
        // if a character is an invalid symbol, throw an error
        // NOTE: this will be your longest method!
    }

    string Scanner::get_name() {
        // if the current token is 'NAME', return the string value of the name, else throw an error
        return "";
    }

    int Scanner::get_number() {
        // if the current token is 'NUMBER', return the int value of the number, else throw an error
        return 0;
    }
