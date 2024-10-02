class Factor {
    public:
        bool exists = false;
        Expression e;
        simple current; 

        void parse() {
            current = Parser::token_stream.current_token();
            switch(current){
                case NAME:
                    Parser::token_stream.next_token();
                    break;
                case NUMBER:
                    Parser::token_stream.next_token();
                    break;
                case LPAREN:
                    Parser::token_stream.next_token();
                    e.parse();
                    e.exists = true;
                    ErrorThrow::throw_compile_exception(Parser::token_stream.current_token(), RPAREN);
                    Parser::token_stream.next_token();
                    break;
                case default:
                    cout << "The token was not a NAME, NUMBER, or LPAREN..." << endl;
                    ErrorThrow::throw_compile_exception(EOS, ADD);
                    break;
            }

            
        }
        void print() {
            if(!e.exists){
                cout<< current << endl;
            }else{
                cout << "( ";
                e.parse();
                cout << " )" << endl;
            }
        }
};