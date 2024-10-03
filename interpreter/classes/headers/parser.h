#ifndef PARSER_H
#define PARSER_H

#include <string>
#include "program.h"
#include "scanner.h"
#include <optional>

class Parser {
public:
     std::optional<Scanner> token_stream;
    // Initializes the parser with a file name
    void initialize_parser(std::string f);

    // Parse the entire program
    void parse_all();

    // Print the parsed program
    void print_all();
};

// Declare a global Parser object that will be defined elsewhere.
extern Parser global_parser; 

#endif // PARSER_H