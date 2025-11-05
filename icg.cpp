#include "icg.h"
#include <iostream>
using namespace std;

static int tempCount = 1;
static string newTemp() {
    return "t" + to_string(tempCount++);
}

void generateICG(const vector<Token> &tokens) {
    size_t n = tokens.size();
    size_t i = 0;
    while (i < n) {
        if (i + 2 < n && tokens[i].type == "KEYWORD" && tokens[i].value == "int") {
            i += 3;
            continue;
        }

        if (i + 3 < n && tokens[i].type == "IDENTIFIER" && tokens[i+1].value == "=" && tokens[i+2].type == "NUMBER" && tokens[i+3].value == ";") {
            cout << tokens[i].value << " = " << tokens[i+2].value << "\n";
            i += 4;
            continue;
        }

        if (i + 3 < n && tokens[i].type == "IDENTIFIER" && tokens[i+1].value == "=" && tokens[i+2].type == "IDENTIFIER" && tokens[i+3].value == ";") {
            cout << tokens[i].value << " = " << tokens[i+2].value << "\n";
            i += 4;
            continue;
        }

        if (i + 5 < n && tokens[i].type == "IDENTIFIER" && tokens[i+1].value == "=" && tokens[i+2].type == "IDENTIFIER"
            && (tokens[i+3].value == "+" || tokens[i+3].value == "-" || tokens[i+3].value == "*" || tokens[i+3].value == "/")
            && tokens[i+4].type == "NUMBER" && tokens[i+5].value == ";") {

            string t = newTemp();
            cout << t << " = " << tokens[i+2].value << " " << tokens[i+3].value << " " << tokens[i+4].value << "\n";
            cout << tokens[i].value << " = " << t << "\n";
            i += 6;
            continue;
        }

        i++;
    }
}
