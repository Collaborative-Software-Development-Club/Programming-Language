#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "term.h"

class Expression {
private:
    Term term; // Pointer to hold term
    Expression * ex_ptr;
    int t;
public:
    void parse();
    void print();
};

#endif // EXPRESSION_H
