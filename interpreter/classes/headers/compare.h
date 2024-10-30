#ifndef COMPARE_H
#define COMPARE_H

#include <memory>
#include "expression.h"

class Compare {
private:
    std::unique_ptr<Expression> expression; // Pointer to hold expression
    std::unique_ptr<Expression> expression2; // Pointer to hold expression2
    int type = 0; //0 for EQUALS, 1 for LESS.
public:
    void parse();
    void print();
};

#endif // COMPARE_H
