#ifndef STATEMENTSEQ_H
#define STATEMENTSEQ_H

#include "statement.h"
#include <memory>

class Statement;
class StatementSeq {
private:
    std::unique_ptr<StatementSeq> ss;
    std::unique_ptr<Statement> s;
public:
    void parse();
    void print();
    void execute();
};

#endif // STATEMENTSEQ_H