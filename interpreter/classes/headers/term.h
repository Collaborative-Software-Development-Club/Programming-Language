#ifndef TERM_H
#define TERM_H

#include "factor.h"

class Term {
private:
    Factor factor; // Pointer to hold factor
    Term* t;
    int termType = -1;
public:
    void parse();
    void print();
};

#endif // TERM_H
