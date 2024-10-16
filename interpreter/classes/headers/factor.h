#ifndef FACTOR_H
#define FACTOR_H

#include <string>

class Expression;

class Factor {
private:
    std::string name; // Variable name (if applicable)
    double value;     // Numeric value (if applicable)
    Expression* expression; // Pointer to hold expression in parentheses
    bool isParen = false;
    int type = 0; //0 for name, 1 for number, 2 for parenthesis...
public:
    void parse();
    void print();
};

#endif // FACTOR_H
