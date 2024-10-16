#ifndef STATEMENTSEQ_H
#define STATEMENTSEQ_H

#include "statement.h"

class StatementSeq {
private:
    Statement statement; // Pointer to individual statement object
    StatementSeq * ss;
public:
    void parse();
    void print();
    bool recursive; 
};

#endif // STATEMENTSEQ_H