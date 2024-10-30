#ifndef PRINT_H
#define PRINT_H

#include "expression.h"
#include <memory>

class Expression;
class Print {
private:
    std::unique_ptr<Expression> expression; // Pointer to hold expression

public:
    void parse();
    void print();
};

#endif // PRINT_H
