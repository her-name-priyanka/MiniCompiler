#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <string>
#include <vector>
using namespace std;

struct Symbol {
    string name;
    string type;
};

void addSymbol(const string &name, const string &type);
bool isDeclared(const string &name);
void displaySymbolTable();

#endif
