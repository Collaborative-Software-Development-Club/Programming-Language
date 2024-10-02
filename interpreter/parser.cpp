#include <iostream>
#include <string>
#include "scanner.cpp"
#include <vector>
#include "classes/headers/assign.h"

using namespace std;

#ifndef PARSER_H
#define PARSER_H

class Parser {
    public:

        //Static variables only exist for the parser!
        //Set up for only the timeline of the parser.
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
                //runs Parser.
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
    public:
        bool exists = false;

        Statement s;
        StatementSeq * ss; 
        bool extra = false;

        void parse() {
            // hint for parsing statementseq: we KNOW that in any case, statement will be parsed.
            // the trick is finding out if statementseq needs parsed again (check your statement code)

            s.parse();  //First token is a Statement!
            //Now check for a statementSequence!

            if(Parser::token_stream.current_token() == NAME || Parser::token_stream.current_token() == IF || Parser::token_stream.current_token() == WHILE ||Parser::token_stream.current_token() == PRINT || Parser::token_stream.current_token() == NUM){
                //Then we are in the case of another statement sequence! We recursively needed to check for the token type!
                extra = true;
                ss->exists = true;
            }
        }
        void print() {
            //print out the terminals in the prog... None in this program!
            //Just let Sequence do the work...
            s.print();
            if(ss->exists){
                ss->print();
            }
            
        }
};

class Declare {
    public:
        DeclareNum d;

        bool exists = false;
        void parse() {
            //Declare must have the declare non-term.
            //work?
            d.parse();
        }
        void print() {
            //No non-terminals here either!
            d.print();
        }
};

class DeclareNum {
    public:
        bool exists = false;
        string name = "";
        void parse() {
                //The first terminal should be num.
                ErrorThrow::throw_compile_exception(Parser::token_stream.current_token(), NUM);
                Parser::token_stream.next_token();

                //get the name next
                ErrorThrow::throw_compile_exception(Parser::token_stream.current_token(), NAME);
                name = Parser::token_stream.get_name();
                Parser::token_stream.next_token();

                //check for the ;
                ErrorThrow::throw_compile_exception(Parser::token_stream.current_token(), SEMICOLON);
                Parser::token_stream.next_token();
        }
        void print() {
            cout << "num " + name + " " + ";";
        }
};

class Statement {
    public:
        bool exists = false;
        Assign a;
        If i;
        Loop l;
        Print p;
        Declare d;

        void parse() {
            // hint for statement: there are 5 non-terminals here! how do we determine which we need?
            // (look at what the next terminal COULD be) 
           

            switch (Parser::token_stream.current_token()){
                case(NAME):
                    //THEN THE ASSIGN INST!
                    a.parse();
                    a.exists = true;
                    break;
                case(IF):
                    i.parse();
                    i.exists = true;
                    break;
                case(WHILE):
                    l.parse();
                    l.exists = true;
                    break;
                case(PRINT):
                    p.parse();
                    p.exists = true;
                    break;
                case(NUM):
                    d.parse();
                    d.exists = true;
                    break;
                default:
                    cout << "THE FILE COULD NOT BE PARSED!\nEXITING PROGRAM..." <<endl;
                    exit(1);
            }
        }
        void print() {
            //for the specific non terminal found for Statement, print!
            if(a.exists){
                a.print();
            }else if(i.exists){
                i.print();
            }else if(l.exists){
                l.print();
            }else if(p.exists){
                p.print();
            }else{
                d.print();
            }
        }
};

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

//SEEMS TO BE WRONG HERE>>>>> FIX???
class Condition {
    //<condition> ::= <compare> | NOT <condition> | <compare> OR <condition> | <compare> AND <condition>

    public:
        bool exists = false;
        Compare comp;
        bool isAnd = 0;
        bool isOr = 0;
        bool isNot = 0;
        Condition* c2;

        void parse() {
            simple current = Parser::token_stream.current_token();
            if(current == NAME){
                //then the token is a compare type!
                //Inside here, we have three options! 
                    //Compare and/or condition 
                    // compare only.
                comp.parse();
                current = Parser::token_stream.current_token(); //see if there's an AND/OR
                if(current == AND){
                    isAnd = 1;
                    c2->parse();
                }else if(current == OR){
                    isOr = 1;
                    c2->parse();
                }
            }else if(current == NOT){
                //not then condition!
                isNot = 1;
                c2->parse();
            }
        }
        void print() {
            if(isAnd){
                comp.print();
                cout << " and ";
                c2->print(); //This does NOT seem right....
            }

        }
};

class Compare {
    public:
        bool exists = false;
        Expression e1;
        Expression e2;
        int equalsOrNot = 0;

        void parse() {
            e1.parse();
            simple current = Parser::token_stream.current_token();
            if(current == EQUAL){
                Parser::token_stream.next_token();
                e2.parse();
                equalsOrNot = 1;
            }else{
                ErrorThrow::throw_compile_exception(Parser::token_stream.current_token(), LESS);
                Parser::token_stream.next_token();
                e2.parse();
            }

        }
        void print() {
            e1.print();
            if(equalsOrNot){
                cout<<" = ";
            }else{
                cout << " < ";
            }
            e2.print();
        }
};

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
 


#endif