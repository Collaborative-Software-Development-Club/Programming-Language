#include <iostream>
#include <string>
#include "scanner.cpp"
#include <vector>

using namespace std;

#ifndef PARSER_H
#define PARSER_H

class Parser {
    public:
        static Scanner token_stream;
        static Program p;
        static void initialize_parser(string f) {
            token_stream = Scanner(f);
        }
        static void parse_all() {
            p.parse(); // time to go through our tree...
        }   
        static void print_all() {
            p.print();
        }
};

class ErrorThrow {
    public:
    static constexpr const char* enum_strings[] = {
        "PROGRAM",
        "NAME",
        "ASSIGN",
        "SEMICOLON",
        "PRINT",
        "IF",
        "ELSE",
        "WHILE",
        "LPAREN",
        "RPAREN",
        "LCURL",
        "RCURL",
        "NOT",
        "OR",
        "AND",
        "EQUAL",
        "LESS",
        "ADD",
        "SUBTRACT",
        "MULTIPLY",
        "DIVIDE",
        "NUMBER",
        "NUM",
        "EOS"
    };
    static void throw_compile_exception(simple actual, simple expected) { // throw an error if a token isn't right
        if (actual != expected) {
            cerr << "ERROR: Expected token " << enum_strings[expected] << ", got " << enum_strings[actual] << endl;
            exit(-1);
        }
    }
};

class Program { // the first non-terminal of Simple. it has been done for you to help demonstrate the
    // recursive descent parsing process :-)
    // NOTE: assuming your language uses the same tokens as Simple, you will not need to change anything here!
    bool exists = false;
    StatementSeq ss; // according to our parse tree, the only non-terminal we could have is statement-seq!
    string program_name;
    public:
        void parse() {
            exists = true; // ensure that we actually parsed an instance of this class
            
            // 1. first we check that the program token is the very first token
            ErrorThrow::throw_compile_exception(Parser::token_stream.current_token(), PROGRAM);
            // 2. if it is, we no longer need it! so move on
            Parser::token_stream.next_token();
            // 3. now we check if the program has a name. an unnamed program is definitely bad
            ErrorThrow::throw_compile_exception(Parser::token_stream.current_token(), NAME);
            // 4. if so, get the name of the program for later, move on
            program_name = Parser::token_stream.get_name();
            Parser::token_stream.next_token();
            // 5. check if our program is blocked off with curly braces, if so, move on
            ErrorThrow::throw_compile_exception(Parser::token_stream.current_token(), LCURL);
            Parser::token_stream.next_token();
            // 6. now we know from our tree that statement-seq will be parsed next, so parse it
            ss.parse();
            // 7. we now assume that statement-seq was parsed successfully (otherwise it or some
            // other non-terminal would have caught it and exited) so we check for the last curly brace
            ErrorThrow::throw_compile_exception(Parser::token_stream.current_token(), RCURL);
            // 8. we should now be at EOS after we do next_token
            Parser::token_stream.next_token();
        }
        void print() {
            // for the print method, we assume that the program was parsed successfully, so we just
            // print out the terminals in Program and move on to the statement-seq printing
            cout << "program " << program_name << " {" << endl; // replace relevant strings with your syntax!
            ss.print();
            cout << "} " << endl;
        }
};

class StatementSeq {
    Statement s; 
    StatementSeq * ss; 
    bool recursive = false;
    public:
        bool exists = false;
        void parse() {
            exists = true;
            // hint for parsing statementseq: we KNOW that in any case, statement will be parsed.
            s.parse();
            if(Parser::token_stream.current_token() == NAME || Parser::token_stream.current_token() == IF || Parser::token_stream.current_token() == WHILE || Parser::token_stream.current_token() == PRINT) {
                (*ss).parse();
                recursive = true;
                
            }
            // the trick is finding out if statementseq needs parsed again (check your statement code)
        }
        void print() {
            s.print();
            if(recursive){
                (*ss).print();
            }
        }
};

class Declare {
    DeclareNum dm;
    public:
        bool exists = false;
        void parse() {
            exists = true; 
            dm.parse();
        }
        void print() {
            dm.print();
        }
};

class DeclareNum {
    string var_name;
    public:
        bool exists = false;
        void parse() {
            exists = true;

            ErrorThrow::throw_compile_exception(Parser::token_stream.current_token(), NUM);
            Parser::token_stream.next_token();
            ErrorThrow::throw_compile_exception(Parser::token_stream.current_token(), NAME);
            var_name = Parser::token_stream.get_name();
            Parser::token_stream.next_token();
            ErrorThrow::throw_compile_exception(Parser::token_stream.current_token(), SEMICOLON);
            Parser::token_stream.next_token();


        }   
        void print() {
            cout << "Tally " << var_name << "." << endl; // replace relevant strings with your syntax!
        }
};

class Statement {
    public:
        bool exists = false;
        void parse() {
            // hint for statement: there are 5 non-terminals here! how do we determine which we need?
            // (look at what the next terminal COULD be) 
        }
        void print() {

        }
};

class Assign {
    public:
        bool exists = false;
        void parse() {

        }
        void print() {

        }
};

class Print {
    public:
        bool exists = false;
        void parse() {

        }
        void print() {

        }
};

class If {
    public:
        bool exists = false;
        void parse() {

        }
        void print() {

        }
};

class Loop {
    public:
        bool exists = false;
        void parse() {

        }
        void print() {

        }
};

class Condition {
    public:
        bool exists = false;
        void parse() {

        }
        void print() {

        }
};

class Compare {
    public:
        bool exists = false;
        void parse() {

        }
        void print() {

        }
};

class Expression {
    public:
        bool exists = false;
        void parse() {

        }
        void print() {

        }
};

class Term {
    public:
        bool exists = false;
        void parse() {

        }
        void print() {

        }
};

class Factor {
    public:
        bool exists = false;
        void parse() {

        }
        void print() {

        }
};

#endif