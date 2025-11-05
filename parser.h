#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>
#include "lexer.h"
using namespace std;

// Very simple parser that checks a small subset grammar
// Returns true if syntax seems OK, false otherwise
bool parser(const vector<Token> &tokens);

#endif
