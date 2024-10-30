#ifndef IF_H
#define IF_H

#include "condition.h"
#include "statementseq.h"

class StatementSeq;
class Condition;
class If {
private:
    std::unique_ptr<Condition> cnd;
    std::unique_ptr<StatementSeq> ss1;
    std::unique_ptr<StatementSeq> ss2;
    bool hasElse = false;

public:
    void parse();
    void print();
};

#endif // IF_H
