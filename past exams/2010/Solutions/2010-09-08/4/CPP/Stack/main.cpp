#include <iostream>
#include "stack/Stack.h"

bool checkBalancedParentheses(const std::string &expression) {
    Stack<char> *s = new Stack<char>();

    for (char c: expression) {
        if (c == '(') {
            s->push(c);
        } else if (c == ')') {
            if (s->is_empty() || s->peek() != '(') {
                return false;
            } else {
                s->pop();
            }
        }
    }

    return s->is_empty();
}

int main() {
    Stack<char> *s = new Stack<char>();

    std::string *valid_expressions[]{
            new std::string(""),
            new std::string("(a+b).c"),
            new std::string("(((a+b).c).d).e+f.(g+h)"),
            new std::string("1+(2+(3+4)+((5+6)+(7+8)+9))")
    };

    std::string *invalid_expressions[]{
            new std::string("("),
            new std::string("a+b.c)"),
            new std::string("(((a+b)).c).d).e+f.(g+h)"),
            new std::string("()()())))()))")
    };

    for (std::string *str: valid_expressions) {
        std::cout << (checkBalancedParentheses(*str) ? "true" : "false") << std::endl;
    }

    for (std::string *str: invalid_expressions) {
        std::cout << (checkBalancedParentheses(*str) ? "true" : "false") << std::endl;
    }

    return 0;
}
