#include <iostream>
#include <string>
#include "../scanner.cpp"
#include <vector>
#include "../parser.cpp"
#include "condition.cpp"
#include "statementseq.cpp"

class Loop {
    public:
        bool exists = false;

        Condition c;
        StatementSeq ss;

        void parse() {
            //<loop> ::= WHILE <condition> LCURL <statement-seq> RCURL
            ErrorThrow::throw_compile_exception(Parser::token_stream.current_token(), WHILE);
            Parser::token_stream.next_token();
            c.parse();
            ErrorThrow::throw_compile_exception(Parser::token_stream.current_token(), LCURL);
            Parser::token_stream.next_token();
            ss.parse();
            ErrorThrow::throw_compile_exception(Parser::token_stream.current_token(), RCURL);
            Parser::token_stream.next_token();
            
        }
        void print() {
            cout << "while ";
            c.print();
            cout << "(";
            ss.print();
            cout << ")" << endl;
        }
};