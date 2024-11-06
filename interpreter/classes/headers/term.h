#ifndef TERM_H
#define TERM_H

#include "factor.h"
#include <memory>

class Factor;
class Term {
private:
    std::unique_ptr<Factor> fcr;
    std::unique_ptr<Term> trm;
    int termType = 0;
public:
    void parse();
    void print();
    int execute();
};

#endif // TERM_H
