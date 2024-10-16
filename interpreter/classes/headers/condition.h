#ifndef CONDITION_H
#define CONDITION_H

#include "compare.h"

class Condition {
private:
    Compare compare; // Pointer to hold comparison
    Condition* cnd;
    int cndType = -1;
public:
    void parse();
    void print();
};

#endif // CONDITION_H
