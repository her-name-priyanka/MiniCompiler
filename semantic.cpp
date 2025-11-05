#include "semantic.h"
#include "symbol_table.h"
#include <iostream>
using namespace std;

bool semanticAnalyzer(const vector<Token> &tokens) {
    size_t n = tokens.size();
    size_t i = 0;
    bool ok = true;

    while (i < n) {
        if (i + 2 < n && tokens[i].type == "KEYWORD" && tokens[i].value == "int"
            && tokens[i+1].type == "IDENTIFIER" && tokens[i+2].type == "SYMBOL" && tokens[i+2].value == ";") {
            addSymbol(tokens[i+1].value, "int");
            i += 3;
            continue;
        }

        if (i + 3 < n && tokens[i].type == "IDENTIFIER"
            && tokens[i+1].type == "SYMBOL" && tokens[i+1].value == "=") {

            string lhs = tokens[i].value;
            if (!isDeclared(lhs)) {
                cerr << "Semantic Error: variable '" << lhs << "' used before declaration.\n";
                ok = false;
            }

            if (tokens[i+2].type == "IDENTIFIER") {
                if (!isDeclared(tokens[i+2].value)) {
                    cerr << "Semantic Error: variable '" << tokens[i+2].value << "' used before declaration.\n";
                    ok = false;
                }
            }
            if (i + 4 < n && tokens[i+3].type == "SYMBOL" && (tokens[i+3].value == "+" || tokens[i+3].value == "-" || tokens[i+3].value == "*" || tokens[i+3].value == "/")) {
                if (tokens[i+4].type == "IDENTIFIER" && !isDeclared(tokens[i+4].value)) {
                    cerr << "Semantic Error: variable '" << tokens[i+4].value << "' used before declaration.\n";
                    ok = false;
                }
            }

            i += 4;
            if (i < n && tokens[i].type == "SYMBOL" && (tokens[i].value == "+" || tokens[i].value == "-" || tokens[i].value == "*" || tokens[i].value == "/")) {
                i += 2;
            }
            continue;
        }

        i++;
    }

    if (ok) cout << "Semantic Analysis Passed ✅\n";
    return ok;
}
