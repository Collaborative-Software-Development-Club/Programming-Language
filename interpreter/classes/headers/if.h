#ifndef IF_H
#define IF_H

#include "condition.h"
#include "statementseq.h"
#include <memory>

class StatementSeq;
class Condition;

class If {
private:
    std::unique_ptr<Condition> condition; // Pointer to hold condition
    std::unique_ptr<StatementSeq> statementSeq; // Pointer to sequence of statements
    std::unique_ptr<StatementSeq> statementSeq2;
    int isElseToo = 0;
public:
    void parse();
    void print();
};

#endif // IF_H
