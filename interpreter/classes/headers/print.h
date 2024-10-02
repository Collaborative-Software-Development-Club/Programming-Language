#ifndef PRINT_H
#define PRINT_H

#include "expression.h"

class Print {
private:
    Expression expression; // Pointer to hold expression

public:
    void parse();
    void print();
};

#endif // PRINT_H
