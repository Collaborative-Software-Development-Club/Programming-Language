#ifndef ASSIGN_H
#define ASSIGN_H

#include "expression.h"
#include <string>
#include <memory>

class Expression;
class Assign {
private:
    std::unique_ptr<Expression> expr;
    std::string name = "";
public:
    void parse();
    void print();
};

#endif // ASSIGN_H
