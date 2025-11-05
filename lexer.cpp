#include "lexer.h"
#include <fstream>
#include <cctype>
#include <iostream>
#include <unordered_set>
using namespace std;

static unordered_set<string> keywords = {"int", "float", "if", "else", "while", "return"};
static unordered_set<char> symbols = {'{','}','(',')',';','=', '+','-','*','/','<','>',','};

static bool isIdentifierStart(char c) {
    return isalpha((unsigned char)c) || c == '_';
}
static bool isIdentifierPart(char c) {
    return isalnum((unsigned char)c) || c == '_';
}

vector<Token> lexer(const string &filename) {
    vector<Token> tokens;
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: cannot open file " << filename << endl;
        return tokens;
    }

    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    size_t i = 0;
    while (i < content.size()) {
        char c = content[i];

        if (isspace((unsigned char)c)) { i++; continue; }

        if (isIdentifierStart(c)) {
            string id;
            while (i < content.size() && isIdentifierPart(content[i])) {
                id.push_back(content[i++]);
            }
            if (keywords.count(id)) tokens.push_back({"KEYWORD", id});
            else tokens.push_back({"IDENTIFIER", id});
            continue;
        }

        if (isdigit((unsigned char)c)) {
            string num;
            while (i < content.size() && isdigit((unsigned char)content[i])) {
                num.push_back(content[i++]);
            }
            tokens.push_back({"NUMBER", num});
            continue;
        }

        if (symbols.count(c)) {
            string s(1, c);
            tokens.push_back({"SYMBOL", s});
            i++;
            continue;
        }

        string s(1, c);
        tokens.push_back({"UNKNOWN", s});
        i++;
    }

    return tokens;
}

void displayTokens(const vector<Token> &tokens) {
    cout << "\nTokens:\n";
    for (auto &t : tokens) {
        cout << "<" << t.type << ", " << t.value << ">\n";
    }
}
