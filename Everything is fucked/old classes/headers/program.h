#ifndef PROGRAM_H
#define PROGRAM_H

#include <string>
#include "statementseq.h"

class Program {
private:
    StatementSeq statementSeq; // Sequence of statements
    std::string programName;

public:
    void parse();
    void print();
};

#endif // PROGRAM_H
