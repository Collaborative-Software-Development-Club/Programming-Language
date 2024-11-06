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
    std::unique_ptr<Assign> asn;
    std::unique_ptr<If> ifst;
    std::unique_ptr<Loop> lp;
    std::unique_ptr<Print> prnt;
    std::unique_ptr<Declare> decl;
    int statementType = -1;
public:
    void parse();
    void print();
    void execute();
};

#endif // STATEMENT_H
