#include "symbol_table.h"
#include <vector>
#include <iostream>
using namespace std;

static vector<Symbol> table;

void addSymbol(const string &name, const string &type) {
    for (auto &s : table) if (s.name == name) return;
    table.push_back({name, type});
}

bool isDeclared(const string &name) {
    for (auto &s : table) if (s.name == name) return true;
    return false;
}

void displaySymbolTable() {
    cout << "Name\tType\n";
    for (auto &s : table) {
        cout << s.name << "\t" << s.type << "\n";
    }
}
