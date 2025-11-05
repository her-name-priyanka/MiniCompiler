#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>
using namespace std;

struct Token {
    string type;  
    string value;
};

vector<Token> lexer(const string &filename);

void displayTokens(const vector<Token> &tokens);

#endif
