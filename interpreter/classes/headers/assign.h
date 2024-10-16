#ifndef ASSIGN_H
#define ASSIGN_H

#include "expression.h"
#include <string>

class Assign {
private:
    Expression expression; // Pointer to hold expression
    std::string name = "";
public:
    void parse();
    void print();
};

#endif // ASSIGN_H
