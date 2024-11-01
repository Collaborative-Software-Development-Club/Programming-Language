#ifndef STATEMENT_H
#define STATEMENT_H

#include "assign.h"
#include "if.h"
#include "loop.h"
#include "print.h"
#include "declare.h"
#include <memory>

class Assign;
class If;
class Loop;
class Print;
class Declare;
class Statement {
private:
    std::unique_ptr<Assign> assign;
    std::unique_ptr<If> ifBlock;
    std::unique_ptr<Loop> loop;
    std::unique_ptr<Print> prints;
    std::unique_ptr<Declare> declare;
    int statementype = -1;

public:
    void parse();
    void print();
};

#endif // STATEMENT_H
