#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include "keywords.h"

using namespace std;

extern std::string SOURCE_CODE;

bool is_operator(char c) {
    return string("+-=*/%<>!&|").find(c) != string::npos;
}

bool is_symbol(char c) {
    return string(";,(){}[]:").find(c) != string::npos;
}

int main(){
    int i = 0;
    while (i < SOURCE_CODE.length()) {
        char c = SOURCE_CODE[i];

        if (isspace(c)) {
            i++;
            continue;
        }

        if (c == '#') {
            string directive = "";
            while (i < SOURCE_CODE.length() && !isspace(SOURCE_CODE[i])) {
                directive += SOURCE_CODE[i];
                i++;
            }
            cout << "PREPROCESSOR: " << directive << endl;
            continue;
        }

        if (c == '"') {
            string str_literal = "\"";
            i++; 
            while (i < SOURCE_CODE.length() && SOURCE_CODE[i] != '"') {
                str_literal += SOURCE_CODE[i];
                i++;
            }
            if (i < SOURCE_CODE.length()) {
                str_literal += '"';
                i++;
            }
            cout << "STRING: " << str_literal << endl;
            continue;
        }

        if (isalpha(c) || c == '_') {
            string word = "";
            while (i < SOURCE_CODE.length() && (isalnum(SOURCE_CODE[i]) || SOURCE_CODE[i] == '_')) {
                word += SOURCE_CODE[i];
                i++;
            }
            if (is_keyword(word)) {
                cout << "KEYWORD: " << word << endl;
            } else {
                cout << "IDENTIFIER: " << word << endl;
            }
            continue;
        }

        if (isdigit(c)) {
            string num = "";
            while (i < SOURCE_CODE.length() && isdigit(SOURCE_CODE[i])) {
                num += SOURCE_CODE[i];
                i++;
            }
            cout << "NUMBER: " << num << endl;
            continue;
        }

        if (is_operator(c)) {
            cout << "OPERATOR: " << c << endl;
            i++;
            continue;
        }

        if (is_symbol(c)) {
            cout << "SYMBOL: " << c << endl;
            i++;
            continue;
        }

        i++; 
    }
    return 0;
}