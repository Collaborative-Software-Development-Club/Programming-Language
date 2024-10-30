#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "term.h"
#include <memory>

class Term;
class Expression {
private:
    std::unique_ptr<Term> trm;
    std::unique_ptr<Expression> expr;
    int exprType = 0;
public:
    void parse();
    void print();
};

#endif // EXPRESSION_H
