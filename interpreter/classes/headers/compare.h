#ifndef COMPARE_H
#define COMPARE_H

#include "expression.h"
#include <memory>

class Compare {
private:
    std::unique_ptr<Expression> expr1;
    std::unique_ptr<Expression> expr2;
    bool equal = false;
public:
    void parse();
    void print();
};

#endif // COMPARE_H
