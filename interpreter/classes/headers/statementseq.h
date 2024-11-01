#ifndef STATEMENTSEQ_H
#define STATEMENTSEQ_H

#include "statement.h"
#include <memory>

class Statement;
class StatementSeq {
private:
    std::unique_ptr<Statement> statement; // Pointer to individual statement object
    std::unique_ptr<StatementSeq> ss2;
public:
    void parse();
    void print();
};

#endif // STATEMENTSEQ_H