
#include <iostream>
#include <string>
#include "../scanner.cpp"
#include <vector>
#include "../parser.cpp"

class Expression {
    public:
        bool exists = false;
        Term t;
        Expression* e;
        int addOrSub[2] = {0, 0};

        void parse() {
            t.parse();
            simple current = Parser::token_stream.current_token();

            if(current == ADD){
                Parser::token_stream.next_token();
                e->parse();
                addOrSub[0] = 1;
            }else if(current == SUBTRACT){
                Parser::token_stream.next_token();
                e->parse();
                addOrSub[1] = 1;
            }

        }
        void print() {
            t.print();
            if(addOrSub[0]){
                cout << " + ";
                e->print();
            }else if(addOrSub[1]){
                cout << " - ";
                e->print();
            }
            cout << endl;
        }
}; 
