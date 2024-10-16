#ifndef STATEMENT_H
#define STATEMENT_H

#include "assign.h"
#include "if.h"
#include "loop.h"
#include "print.h"
#include "declare.h"

class Statement {
private:
    Assign assign;
    If ifBlock;
    Loop loop;
    Print prints;
    Declare declare;
    int statementype = -1;

public:
    void parse();
    void print();
};

#endif // STATEMENT_H
