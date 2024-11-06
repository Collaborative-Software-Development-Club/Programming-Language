#ifndef FACTOR_H
#define FACTOR_H

#include <string>
#include <memory>

class Expression;
class Factor {
private:
    std::unique_ptr<Expression> expr;
    std::string name = "";
    int num = -1;
    int factorType = -1;
public:
    void parse();
    void print();
    int execute();
};

#endif // FACTOR_H
