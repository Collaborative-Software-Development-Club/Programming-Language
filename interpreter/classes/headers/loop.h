#ifndef LOOP_H
#define LOOP_H

#include "condition.h"
#include "statementseq.h"
#include <memory>

class StatementSeq;
class Condition;
class Loop {
private:
    std::unique_ptr<Condition> cnd;
    std::unique_ptr<StatementSeq> ss;
public:
    void parse();
    void print();
};

#endif // LOOP_H
