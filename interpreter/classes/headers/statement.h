#ifndef STATEMENT_H
#define STATEMENT_H

#include "assign.h"
#include "if.h"
#include "loop.h"
#include "print.h"
#include "declare.h"

class Statement {
    Assign assign;
    If ifBlock;
    Loop loop;
    Print print1;
    Declare declare;
    int type; 


public:
    void parse();
    void print();
};

#endif // STATEMENT_H
