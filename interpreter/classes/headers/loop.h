#ifndef LOOP_H
#define LOOP_H

#include "condition.h"
#include "statementseq.h"
#include <memory>   //used to allow for pointers...

class StatementSeq; //DEFINE CLASSES BEFOREHAND TO AVOID CIRCULAR DEPENDENCIES...
class Condition; 

class Loop {
private:
    std::unique_ptr<Condition> condition; // Pointer to hold condition
    std::unique_ptr<StatementSeq> statementSeq; // Pointer to sequence of statements

public:
    void parse();
    void print();
};

#endif // LOOP_H
