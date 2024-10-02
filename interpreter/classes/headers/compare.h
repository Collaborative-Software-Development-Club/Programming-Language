#ifndef COMPARE_H
#define COMPARE_H

#include "expression.h"

class Compare {
private:
    Expression expression; // Pointer to hold expression

public:
    void parse();
    void print();
};

#endif // COMPARE_H
