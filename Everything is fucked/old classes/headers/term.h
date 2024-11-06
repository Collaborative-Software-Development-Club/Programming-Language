#ifndef TERM_H
#define TERM_H

#include "factor.h"

class Term {
private:
    Factor factor; // Pointer to hold factor
    int type; 
    Term * term_ptr; 
public:
    void parse();
    void print();
};

#endif // TERM_H
