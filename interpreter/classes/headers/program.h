#ifndef PROGRAM_H
#define PROGRAM_H

#include <string>
#include "statementseq.h"

class Program {
private:
    StatementSeq ss; // Sequence of statements
    std::string program_name;

public:
    void parse();
    void print();
};

#endif // PROGRAM_H
