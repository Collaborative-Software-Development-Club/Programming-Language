#ifndef MEMORY_H
#define MEMORY_H

#include <stack>
#include <map>
#include <string>

class Memory {
    public:
    std::stack<std::map<std::string, int>> mem;
    void make_scope();
    void demake_scope();
    void set_num(std::string n, int val);
    int get_num(std::string n);
};

extern Memory global_memory;

#endif