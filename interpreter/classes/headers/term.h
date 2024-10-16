#ifndef TERM_H
#define TERM_H

#include "factor.h"

class Term {
private:
    Factor factor; // Pointer to hold factor
    int type = 0;
    Term* term2;
public:
    void parse();
    void print();
};

#endif // TERM_H
