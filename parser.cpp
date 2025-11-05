#include "parser.h"
#include <iostream>
using namespace std;

bool parser(const vector<Token> &tokens) {
    size_t n = tokens.size();
    size_t i = 0;
    while (i < n) {
       
        if (i + 2 < n && tokens[i].type == "KEYWORD" && tokens[i].value == "int"
            && tokens[i+1].type == "IDENTIFIER" && tokens[i+2].type == "SYMBOL" && tokens[i+2].value == ";") {
            i += 3;
            continue;
        }

        if (i + 3 < n && tokens[i].type == "IDENTIFIER"
            && tokens[i+1].type == "SYMBOL" && tokens[i+1].value == "="
            && tokens[i+2].type == "NUMBER"
            && tokens[i+3].type == "SYMBOL" && tokens[i+3].value == ";") {
            i += 4;
            continue;
        }

        if (i + 3 < n && tokens[i].type == "IDENTIFIER"
            && tokens[i+1].type == "SYMBOL" && tokens[i+1].value == "="
            && tokens[i+2].type == "IDENTIFIER"
            && tokens[i+3].type == "SYMBOL" && tokens[i+3].value == ";") {
            i += 4;
            continue;
        }

        if (i + 5 < n && tokens[i].type == "IDENTIFIER"
            && tokens[i+1].type == "SYMBOL" && tokens[i+1].value == "="
            && tokens[i+2].type == "IDENTIFIER"
            && tokens[i+3].type == "SYMBOL" 
            && (tokens[i+3].value == "+" || tokens[i+3].value == "-" || tokens[i+3].value == "*" || tokens[i+3].value == "/")
            && tokens[i+4].type == "NUMBER"
            && tokens[i+5].type == "SYMBOL" && tokens[i+5].value == ";") {
            i += 6;
            continue;
        }

        cerr << "Syntax error near token: ";
        if (i < n) cerr << "<" << tokens[i].type << ", " << tokens[i].value << ">\n";
        else cerr << "end of input\n";
        return false;
    }

    cout << "Syntax Analysis Passed ✅\n";
    return true;
}
