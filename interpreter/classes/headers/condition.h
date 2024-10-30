#ifndef CONDITION_H
#define CONDITION_H

#include "compare.h"
#include <memory>

class Compare;
class Condition {
private:
    std::unique_ptr<Compare> cpr;
    std::unique_ptr<Condition> cnd;
    int cndType = 0;
public:
    void parse();
    void print();
};

#endif // CONDITION_H
