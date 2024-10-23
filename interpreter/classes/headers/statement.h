#ifndef STATEMENT_H
#define STATEMENT_H

#include "assign.h"
#include "if.h"
#include "loop.h"
#include "print.h"
#include "declare.h"

class If;
class Loop;
class Statement {
private:
    Assign assign;
    If* ifBlock;
    Loop* loop;
    Print printS;
    Declare declare;
    int statementType;
public:
    void parse();
    void print();
};

#endif // STATEMENT_H
