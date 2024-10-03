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