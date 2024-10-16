#ifndef STATEMENTSEQ_H
#define STATEMENTSEQ_H

#include "statement.h"

class StatementSeq {
private:
    Statement statement; // Pointer to individual statement object
    StatementSeq * ss;
    bool recursive; 

public:
    void parse();
    void print();
};

#endif // STATEMENTSEQ_H