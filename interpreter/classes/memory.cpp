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
    if (!Memory::mem.empty()) {
        std::stack<std::map<std::string, int>> temp;
        bool found = false;

        // Traverse the stack
        while (!mem.empty()) {
            auto curr = mem.top(); // Copy to preserve stack structure
            mem.pop();

            if (curr.find(n) != curr.end()) {
                curr[n] = val;
                found = true;
            }
            temp.push(curr);
        }

        // Rebuild the original stack
        while (!temp.empty()) {
            mem.push(temp.top());
            temp.pop();
        }

        // If not found, add to the top scope
        if (!found) {
            mem.top()[n] = val; // Directly modify the top map
        }
    } else {
        std::cerr << "ERROR: No scope available to set value." << std::endl;
        exit(-1);
    }
}

int Memory::get_num(std::string n) {
    if (Memory::mem.empty()) {
        std::cerr << "ERROR: No scope available to retrieve value." << std::endl;
        exit(-1);
    }

    std::stack<std::map<std::string, int>> temp;
    int val = 0;
    bool found = false;

    // Traverse the stack
    while (!mem.empty()) {
        auto curr = mem.top(); // Copy to preserve stack structure
        mem.pop();

        if (curr.find(n) != curr.end()) {
            val = curr[n];
            found = true;
        }
        temp.push(curr);
    }

    // Rebuild the original stack
    while (!temp.empty()) {
        mem.push(temp.top());
        temp.pop();
    }

    if (found) return val;

    std::cerr << "ERROR: Key not found!" << std::endl;
    exit(-1);
}