#include <iostream>
#include <string>
#include "../scanner.cpp"
#include <vector>
#include "../parser.cpp"
#include "factor.cpp"

class Term {
    public:
        Factor f;
        Term * t;
        int mOrD[2] = {0, 0};

        bool exists = false;
        void parse() {
            f.parse();
            
            simple current = Parser::token_stream.current_token();
            if(current == MULTIPLY){
                Parser::token_stream.next_token();
                t->parse();
                mOrD[0] = 1;
                t->exists = true;
            }else if(current == SUBTRACT){
                Parser::token_stream.next_token();
                t->parse();
                t->exists = true;
                mOrD[1] = 1;
            }
        }
        void print() {
            f.print();
            if(mOrD[0]){
                cout << " * ";
                t->print();
            }else if(mOrD[1]){
                cout << " / ";
                t->print();
            }
            cout << endl;
        }
};