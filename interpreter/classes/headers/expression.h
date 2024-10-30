#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "term.h"
#include <memory>

class Term;
class Expression {
//<expression> ::= <term> | <term> ADD <expression> | <term> SUBTRACT <expression>

private:
    std::unique_ptr<Term> term; // Pointer to hold term
    int type = 0; // 1 means add, 2 means subtract.
    std::unique_ptr<Expression> e;
public:
    void parse();
    void print();
};

#endif // EXPRESSION_H
