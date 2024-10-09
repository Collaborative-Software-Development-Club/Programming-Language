#include <iostream>
#include <string>
#include "simple.cpp"
#include <fstream>
#include <queue>

using namespace std;

#ifndef SCANNER_H
#define SCANNER_H

class Scanner {
    private:

        // you may either keep an array or a list of all characters in the stream, or...
        // ...keep the file stream open, and read only characters that you need at the moment!

        simple curr_token; // the current token
        int curr_number; // the int value of the most recent (or current) 'NUMBER' token
        string curr_name; // the string value of the most recent (or current) 'NAME' token
        queue<string> q;


    public:
        Scanner(string f) {
            // use filename argument 'f' to open the file, read characters as needed, and eventually close
            // the file stream

            ifstream file(f);

            if(file.is_open()){
                cout << "Whoopie it opened!" << endl;
                queue<string> q;    //Make a new queue. Parently this is it....
                
                //now read in any available input.
                string line;
                string token = "";
                int tokenSize = 0;
                while(getline(file, line)){
                    //line now holds a line of input from the file.

                    //go over each character in the line.
                    for(int i = 0; i < line.length(); i++){
                        char c = line[i];

                        //check if the character is part of the current token.
                        //TODO check this
                        if(c != ' '){
                            if((c == '(') || (c == '{')){
                                //this is the case of a special circ. token!
                                q.push(""+c); //Push the (/{ as it's own token!
                            }else if((c == ')') || (c == '}')){
                                //the }/) came at the end of something else...
                                if(token.size() > 0){
                                    q.push(token);
                                    token = "";
                                    tokenSize = 0;
                                }
                                q.push(""+c); //end of the token...
                            }else{
                                token += c;
                                tokenSize++;
                            }
                            
                        }else{
                            //if not, we have a new token to get!
                            q.push(token);
                            token = "";
                            tokenSize = 0;
                        }
                    }
                }

                //By here all words in the file have been turned to tokens...

                //check for leftover tokens if the file ended.
                if(token != ""){
                    q.push(token);
                }

            }else{
                cerr << "Sucks to suck, the file didn't open." << endl;
                exit(1);
            }

            // if we cannot find the specified file, gracefully return an error and exit
        }

        simple current_token() {
            // all you have to do here is return the currently stored token without going to the next one
            return curr_token;
        }

        int is_num(string token){
            int num = 1;
            string numbers = "0123456789";
                for(char c : token){
                    if (!numbers.find(c)){
                        num = 0;
                        break;
                    }
                }
                if(num){
                    curr_token = NUMBER;
                    curr_number = stoi(token);
                }
            return num;
        }

        void next_token() {
            // find the next available token in the scanning stream, covert it into a token, store it
            // if a character is an invalid symbol, throw an error
            // NOTE: this will be your longest method!

            if(q.size() > 0){
                
                //in c, one must look at the item first to get the ref, then pop it off the front!
                string token = q.front();
                q.pop();

                //first, check if the token is a number...
                int num = is_num(token);

                if(!num){
                    //next, check for the keywords...
                    if(token == "PROGRAM"){
                        curr_token = PROGRAM;
                    }else if(token == "="){
                        curr_token = ASSIGN;
                    }else if(token == ";"){
                        curr_token = SEMICOLON;
                    }else if(token == "say"){
                        curr_token = PRINT;
                    }else if(token == "if"){
                        curr_token = IF;
                    }else if(token == "else"){
                        curr_token = ELSE;
                    }else if(token == "while"){
                        curr_token = WHILE;
                    }else if(token == "("){
                        curr_token = LPAREN;
                    }else if(token == ")"){
                        curr_token = RPAREN;
                    }else if(token == "{"){
                        curr_token = LCURL;
                    }else if(token == "}"){
                        curr_token = RCURL;
                    }else if(token == "!"){
                        curr_token = NOT;
                    }else if(token == "||"){
                        curr_token = OR;
                    }else if(token == "&&"){
                        curr_token = AND;
                    }else if(token == "-"){
                        curr_token = SUBTRACT;
                    }else if(token == "*"){
                        curr_token = MULTIPLY;
                    }else if(token == "/"){
                        curr_token = DIVIDE;
                    } else if(token == "num") {
                        curr_token = NUM;
                        //cmon
                    } else {
                        //TODO -- add more checks for these later...
                        curr_token = NAME;
                        curr_name = token;
                    }
                }
                
                
            }else{
                cerr<< "The number of tokens is 0!" << endl;
                exit(0);
            }
        }

        string get_name() {
            // if the current token is 'NAME', return the string value of the name, else throw an error
            if(current_token() == NAME){
                return curr_name;
            }else{
                printf("THE CURRENT TOKEN WAS NOT A NAME.\nEXITING PROGRAM...\n");
                exit(0);
            }
        }

        int get_number() {
            // if the current token is 'NUMBER', return the int value of the number, else throw an error
            if(current_token() == NUMBER){
                return curr_number;
            }else{
                printf("THE CURRENT TOKEN WAS NOT A NUMBER.\nEXITING PROGRAM...\n");
                exit(0);
            }
        }
        int main(){
            Scanner s("test01.txt");
            return 0;
        }
};

#endif