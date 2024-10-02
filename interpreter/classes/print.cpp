#include <iostream>
#include <string>
#include "../scanner.cpp"
#include <vector>
#include "../parser.cpp"
#include "expression.cpp"

class Print {
    public:
        bool exists = false;
        Expression e;
        void parse() {
            ErrorThrow::throw_compile_exception(Parser::token_stream.current_token(), PRINT);
            Parser::token_stream.next_token();
            ErrorThrow::throw_compile_exception(Parser::token_stream.current_token(), LPAREN);
            Parser::token_stream.next_token();
            e.parse();
            ErrorThrow::throw_compile_exception(Parser::token_stream.current_token(), RPAREN);
            Parser::token_stream.next_token();
        }
        void print() {
            cout << "(";
            e.print();
            cout << ")" << endl;
        }
};