#ifndef PARSER_H
#define PARSER_H

#include <string>
#include "program.h"
#include "scanner.h"
#include <optional>

class Parser {
public:
     std::optional<Scanner> token_stream;
     Program p;
    // initializes the parser with a file name
    void initialize_parser(std::string f);

    // parse the entire program
    void parse_all();

    // print the parsed program
    void print_all();

    // check for grammatical error
    void check(simple check);

    // consume value
    void consume();

    // get the int/num value
    int get_num();

    // get the name/string value
    std::string get_name();
};

extern Parser global_parser; 

#endif