#ifndef ASSIGN_H
#define ASSIGN_H

#include "expression.h"
#include <memory>

class Assign {
private:
    std::string name = "";
    std::unique_ptr<Expression> expression; // Pointer to hold expression

public:
    void parse();
    void print();
};

#endif // ASSIGN_H
