#ifndef DECLARE_H
#define DECLARE_H
#include <memory>

#include "declarenum.h"

class DeclareNum;
class Declare {
private:
    std::unique_ptr<DeclareNum> dm;
public:
    void parse();
    void print();
};

#endif // DECLARE_H
