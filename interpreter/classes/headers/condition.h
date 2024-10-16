#ifndef CONDITION_H
#define CONDITION_H

#include "compare.h"

class Condition {
private:
    int caseType = 1;
    Compare compare; // Pointer to hold comparison
    Condition* cond2;
    std::string name = "";
public:
    void parse();
    void print();
};

#endif // CONDITION_H
