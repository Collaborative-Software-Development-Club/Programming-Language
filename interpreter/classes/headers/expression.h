#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "term.h"

class Expression {
private:
    Term term; // Pointer to hold term

public:
    void parse();
    void print();
};

#endif // EXPRESSION_H
