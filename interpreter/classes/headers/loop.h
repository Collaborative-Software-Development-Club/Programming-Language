#ifndef LOOP_H
#define LOOP_H

#include "condition.h"
#include "statementseq.h"

class StatementSeq;
class Loop {
private:
    Condition condition; // Pointer to hold condition
    StatementSeq* statementSeq; // Pointer to sequence of statements

public:
    void parse();
    void print();
};

#endif // LOOP_H
