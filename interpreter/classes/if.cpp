#include <iostream>
#include <string>
#include "../scanner.cpp"
#include <vector>
#include "../parser.cpp"
#include "condition.cpp"
#include "statementseq.cpp"

class If {
    public:
        Condition c;
        StatementSeq ss; 
        StatementSeq ss2;

        bool exists = false;
        void parse() {
            ErrorThrow::throw_compile_exception(Parser::token_stream.current_token(), IF);
            Parser::token_stream.next_token();
            c.parse();
            ErrorThrow::throw_compile_exception(Parser::token_stream.current_token(), LCURL);
            Parser::token_stream.next_token();
            ss.parse();
            ErrorThrow::throw_compile_exception(Parser::token_stream.current_token(), RCURL);
            Parser::token_stream.next_token();

            //THEN WE HAVE AN IF-ELSE RATHER THAN AN IF!
            //guess we don't have else-ifs here... --> to be implemented later?
            if(Parser::token_stream.current_token() == ELSE){
                Parser::token_stream.next_token();
                ErrorThrow::throw_compile_exception(Parser::token_stream.current_token(), LCURL);
                Parser::token_stream.next_token();
                ss2.parse(); //parse through our second StatementSeq.
                ss2.exists = true; //Set to true for our printing to be done for an if-else.
                ErrorThrow::throw_compile_exception(Parser::token_stream.current_token(), RCURL);
                Parser::token_stream.next_token();
            }
        
        }
        void print() {
            cout << "if ";
            c.print();
            cout << "(";
            ss.print();
            cout << ")";
            if(ss2.exists){
                //then there was an else statement!
                cout<<"else (";
                ss2.print();
                cout << ")" << endl;
            }
        }
};