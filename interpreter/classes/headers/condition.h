#ifndef CONDITION_H
#define CONDITION_H
#include <memory>

#include "compare.h"

class Compare;
class Condition {
private:
    int caseType = 1;
    std::unique_ptr<Compare> compare; // Pointer to hold comparison
    std::unique_ptr<Condition> cond2;
    std::string name = "";
public:
    void parse();
    void print();
};

#endif // CONDITION_H
