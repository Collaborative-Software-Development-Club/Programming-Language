#ifndef FACTOR_H
#define FACTOR_H

#include <string>

class Expression; // Forward declaration

class Factor {
private:
    std::string name; // Variable name (if applicable)
    double value;     // Numeric value (if applicable)
    Expression* expression; // Pointer to hold expression in parentheses

public:
    void parse();
    void print();
};

#endif // FACTOR_H
