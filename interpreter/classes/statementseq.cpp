#incldue ""

class Statement;

class StatementSeq {
    private:
    Statement s;
    public:
        bool exists = false;
        void parse() {
            // hint for parsing statementseq: we KNOW that in any case, statement will be parsed.
            // the trick is finding out if statementseq needs parsed again (check your statement code)
        }
        void print() {

        }
};