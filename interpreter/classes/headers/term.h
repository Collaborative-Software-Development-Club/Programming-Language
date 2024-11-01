#ifndef TERM_H
#define TERM_H

#include "factor.h"
#include <memory>

class Factor;
class Term {
private:
    std::unique_ptr<Factor> factor; // Pointer to hold factor
    std::unique_ptr<Term> term2; // Pointer to hold factor
    int type = 0;
public:
    void parse();
    void print();
};

#endif // TERM_H
