#include <iostream>
#include <string>
#include "scanner.cpp"
#include <vector>
#include "expression.h"
#include "../parser.cpp"

class Assign {
    public:
    string name = "";
    Expression e;
        bool exists = false;
        void parse() {
            ErrorThrow::throw_compile_exception(Parser::token_stream.current_token(), NAME);
            name = Parser::token_stream.get_name();
            Parser::token_stream.next_token(); //go on!

            ErrorThrow::throw_compile_exception(Parser::token_stream.current_token(), ASSIGN);
            Parser::token_stream.next_token(); //go on!
            //The next token goes to the non-terminal expression!

            e.parse();

            //lastly, there should be a semicolon!
            ErrorThrow::throw_compile_exception(Parser::token_stream.current_token(), SEMICOLON);
            Parser::token_stream.next_token(); //go on!
        }
        void print() {
            cout << name + " = ";
            e.print();
            cout << ";" << endl; 
        }
};