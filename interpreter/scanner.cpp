#include <iostream>
#include <string>
#include <fstream>
#include "simple.cpp"

using namespace std;

#ifndef SCANNER_H
#define SCANNER_H

class Scanner {
    private:
        simple curr_token; // the current token
        int curr_number; // the int value of the most recent (or current) 'NUMBER' token
        string curr_name; // the string value of the most recent (or current) 'NAME' token
        ifstream file;

    public:
        Scanner(string f) {
            file.open(f);
            if (!file.is_open()) {
                cerr << "Error: File not found: " << f << endl;
                exit(1);
            } else cout << "File successfully opened" << endl;
        }

        ~Scanner() {
            if (file.is_open()) file.close();
        }

        void handleIdentifier(char firstChar) {
            string name;
            name += firstChar;

            char ch;
            while (file.get(ch) && isalnum(ch)) name += ch;

            file.unget();

            if      (name == "print") curr_token = PRINT;
            else if (name == "while") curr_token = WHILE;
            else if (name == "if")    curr_token = IF;
            else if (name == "elif")  curr_token = ELIF;
            else if (name == "else")  curr_token = ELSE;
            else if (name == "not")   curr_token = NOT;
            else if (name == "and")   curr_token = AND;
            else if (name == "or")    curr_token = OR;
            else {
                curr_token = NAME;
                curr_name = name;
            }
        }

        void handleNumber(char firstDigit) {
            int num = firstDigit - '0';

            char ch;
            while (file.get(ch) && isdigit(ch)) num = num * 10 + (ch - '0');
            
            file.unget();

            curr_token = NUMBER;
            curr_number = num;
        }

        void handleMultiChar(char ch) {
            char nextCh;

            if (file.get(nextCh)) {
                if      (ch == '=' && nextCh == '=') curr_token = EQUAL;
                else if (ch == '*' && nextCh == '*') curr_token = POWER;
                else if (ch == '!' && nextCh == '=') curr_token = NOTEQUAL;
                else if (ch == '<' && nextCh == '=') curr_token = LTE;
                else if (ch == '>' && nextCh == '=') curr_token = GTE;
                else {
                    file.unget();
                    handleSingleChar(ch);
                }
            } else handleSingleChar(ch);
        }

        void handleSingleChar(char ch) {
            switch (ch) {
                case ';':
                    curr_token = SEMICOLON;
                    break;
                case '=':
                    curr_token = ASSIGN;
                    break;
                case '(':
                    curr_token = LPAREN;
                    break;
                case ')':
                    curr_token = RPAREN;
                    break;
                case '{':
                    curr_token = LCURL;
                    break;
                case '}':
                    curr_token = RCURL;
                    break;
                case '+':
                    curr_token = ADD;
                    break;
                case '-':
                    curr_token = SUBTRACT;
                    break;
                case '*':
                    curr_token = MULTIPLY;
                    break;
                case '/':
                    curr_token = DIVIDE;
                    break;
                case '%':
                    curr_token = MOD;
                    break;
                case '<':
                    curr_token = LT;
                    break;
                case '>':
                    curr_token = GT;
                    break;
                default:
                    cerr << "Invalid symbol: " << ch << endl;
                    exit(1);
            }
        }

        void next_token() {
            char ch;

            while (file.get(ch)) {
                if (isspace(ch)) continue;

                if (isalpha(ch)) {
                    handleIdentifier(ch);
                    return;
                }

                if (isdigit(ch)) {
                    handleNumber(ch);
                    return;
                }
                
                if (ch == '=' || ch == '*' || ch == '<' || ch == '>' || ch == '!') {
                    handleMultiChar(ch);
                    return;
                }

                handleSingleChar(ch);
                return;
            }

            curr_token = EOS;
        }

        simple current_token() {
            return curr_token;
        }

        string get_name() {
            if (curr_token == NAME) return curr_name;
            else {
                cerr << "Error: Current token is not a NAME" << endl;
                exit(1);
            }
        }

        int get_number() {
            if (curr_token == NUMBER) return curr_number;
            else {
                cerr << "Error: Current token is not a NUMBER" << endl;
                exit(1);
            }
        }
};

#endif