#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "term.h"

class Expression {
private:
    Term term; // Pointer to hold term
    Expression* e;
    int exprType = -1;
public:
    void parse();
    void print();
};

#endif // EXPRESSION_H
