#ifndef FACTOR_H
#define FACTOR_H

#include <string>

class Expression;

class Factor {
private:
    std::string name = ""; // Variable name (if applicable)
    int num = -1;     // Numeric value (if applicable)
    Expression* expression; // Pointer to hold expression in parentheses
    int factorType = -1;
public:
    void parse();
    void print();
};

#endif // FACTOR_H
