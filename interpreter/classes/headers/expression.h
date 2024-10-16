#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "term.h"

class Expression {
//<expression> ::= <term> | <term> ADD <expression> | <term> SUBTRACT <expression>

private:
    Term term; // Pointer to hold term
    int type = 0; // 1 means add, 2 means subtract.
    Expression* e;
public:
    void parse();
    void print();
};

#endif // EXPRESSION_H
