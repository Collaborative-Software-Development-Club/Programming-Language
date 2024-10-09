#ifndef IF_H
#define IF_H

#include "condition.h"
#include "statementseq.h"

class If {
private:
    Condition condition; // Pointer to hold condition
    StatementSeq statementSeq; // Pointer to sequence of statements
    StatementSeq statementSeq2;
    bool hasElse = false;

public:
    void parse();
    void print();
};

#endif // IF_H
