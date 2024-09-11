#include <iostream>
#include <string>
#include <fstream>
#include "simple.cpp"

using namespace std;

#ifndef SCANNER_H
#define SCANNER_H

class Scanner {
    private:

        // you may either keep an array or a list of all characters in the stream, or...
        // ...keep the file stream open, and read only characters that you need at the moment!

        vector<char> charStream; // character stream
        int charPointer = 0; // a pointer to walk through the vector

        simple curr_token; // the current token
        int curr_number; // the int value of the most recent (or current) 'NUMBER' token
        string curr_name; // the string value of the most recent (or current) 'NAME' token

    public:
        Scanner(string f) {
            // use filename argument 'f' to open the file, read characters as needed, and eventually close
            // the file stream

            ifstream filestream(f);
            string currentLine;

            if(!filestream.is_open()){
                ceff << "FILE OPEN FAILED" << endl;
                return;
            } else{
                while(getline(filestream, currentLine)){
                    for(char c : currentLine){
                        charStream.push_back(c);
                    }
                }
                fstream.close();
            }
            // if we cannot find the specified file, gracefully return an error and exit
        }

        simple current_token() {
            // all you have to do here is return the currently stored token without going to the next one
            return curr_token;
        }

        void next_token() {
            // find the next available token in the scanning stream, covert it into a token, store it
            // if a character is an invalid symbol, throw an error
            // NOTE: this will be your longest method!
        }

        string get_name() {
            // if the current token is 'NAME', return the string value of the name, else throw an error
            if (curr_token == 'NAME') {
                return curr_name;
            } else {
                cout << "ERROR";
            }
            return 0;
        }

        int get_number() {
            // if the current token is 'NUMBER', return the int value of the number, else throw an error
            int result = 0; 
            if(curr_token == NUMBER){
                result = NUMBER;
            }else{
                cerr < "PRITHEE, THOU HADST NOT SPECIFIED A VALID NUMERAL." << endl;
                exit(-1);
            }   
        }
};

#endif
