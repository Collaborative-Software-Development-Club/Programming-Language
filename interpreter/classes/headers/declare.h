#ifndef DECLARE_H
#define DECLARE_H

#include "declarenum.h"
#include <memory>

class DeclareNum;
class Declare {
private:
    std::unique_ptr<DeclareNum> dn;
public:
    void parse();
    void print();
    void execute();
};

#endif // DECLARE_H
