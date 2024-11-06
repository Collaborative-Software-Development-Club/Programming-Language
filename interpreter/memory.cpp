#include "classes/headers/memory.h"
#include <iostream>

using namespace std;

Memory global_memory;

void Memory::make_scope() {
    std::map<std::string, int> temp;
    Memory::mem.push(temp);
}

void Memory::demake_scope() {
    Memory::mem.pop();
}

void Memory::set_num(std::string n, int val) {
    if (Memory::mem.size() > 0) {
        std::stack<std::map<std::string, int>> temp;
        bool found = false;
        while (!mem.empty()) {
            auto curr = mem.top();
            mem.pop();
            if (curr.find(n) != curr.end()) {
                curr[n] = val;
                found = true;
            }
            temp.push(curr);
        }
        while (!temp.empty()) {
            mem.push(temp.top());
            temp.pop();
        }
        if (!found) {
            auto curr = mem.top();
            curr[n] = val;
        }
    }
}

int Memory::get_num(std::string n) {
    int val = 0;
    bool found = false;
    if (Memory::mem.size() > 0) {
        std::stack<std::map<std::string, int>> temp;
        while (!mem.empty()) {
            auto curr = mem.top();
            mem.pop();
            if (curr.find(n) != curr.end()) {
                val = curr[n];
                found = true;
            }
            temp.push(curr);
        }
        while (!temp.empty()) {
            mem.push(temp.top());
            temp.pop();
        }
    }
    if (found) return val;
    else {
        std::cerr << "ERROR: Key not found!" << std::endl;
        exit(-1);
    }
}