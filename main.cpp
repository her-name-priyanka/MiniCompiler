#include <iostream>
#include "lexer.h"
#include "parser.h"
#include "semantic.h"
#include "icg.h"
#include "symbol_table.h"
using namespace std;

int main() {
    cout << "===== MINI C++ COMPILER (Advanced) =====\n\n";

    string filename = "test_input.cpp";
    cout << "Reading file: " << filename << endl;

    vector<Token> tokens = lexer(filename);
    displayTokens(tokens);

    cout << "\n--- Syntax Analysis ---\n";
    bool syntaxOK = parser(tokens);
    if (!syntaxOK) {
        cout << "\nSyntax Error! Compilation halted.\n";
        return 0;
    }

    cout << "\n--- Semantic Analysis ---\n";
    bool semanticOK = semanticAnalyzer(tokens);
    if (!semanticOK) {
        cout << "\nSemantic Error! Compilation halted.\n";
        return 0;
    }

    cout << "\n--- Intermediate Code Generation ---\n";
    generateICG(tokens);
    cout << "\n--- Symbol Table ---\n";
    displaySymbolTable();

    cout << "\nCompilation successful! ✅\n";
    return 0;
}
