#ifndef DECLARE_H
#define DECLARE_H

#include "declarenum.h"

class Declare {
private:
    DeclareNum dn;
public:
    void parse();
    void print();
};

#endif // DECLARE_H