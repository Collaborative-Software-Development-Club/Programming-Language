#ifndef PROGRAM_H
#define PROGRAM_H

#include <string>
#include <memory>
#include "statementseq.h"

class StatementSeq;
class Program {
private:
    std::unique_ptr<StatementSeq> ss; // Sequence of statements
    std::string program_name;

public:
    void parse();
    void print();
};

#endif // PROGRAM_H
