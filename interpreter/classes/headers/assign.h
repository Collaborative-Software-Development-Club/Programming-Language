#ifndef ASSIGN_H
#define ASSIGN_H

#include "expression.h"

class Assign {
private:
    Expression expression; // Pointer to hold expression

public:
    void parse();
    void print();
};

#endif // ASSIGN_H