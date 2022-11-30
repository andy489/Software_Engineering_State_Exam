package com.fmi.state.exam;

import com.fmi.state.exam.stack.Stack;

public class Main {
    public static boolean checkBalancedParentheses(String expression) {
        Stack<Character> s = new Stack<>();

        for (Character c : expression.toCharArray()) {
            if (c == '(') {
                s.push(c);
            } else if (c == ')') {
                if (s.isEmpty() || s.peek() != '(') {
                    return false;
                } else {
                    s.pop();
                }
            }
        }

        return s.isEmpty();
    }

    public static void main(String... args) {
        Stack<Character> s = new Stack<>();

        String[] validExpressions = {
                "",
                "(a+b).c",
                "(((a+b).c).d).e+f.(g+h)",
                "1+(2+(3+4)+((5+6)+(7+8)+9))"
        };

        String[] invalidExpressions = {
                "(",
                "a+b.c)",
                "(((a+b)).c).d).e+f.(g+h)",
                "()()())))()))"
        };

        for (String str : validExpressions) {
            System.out.println(checkBalancedParentheses(str));
        }

        for (String str : invalidExpressions) {
            System.out.println(checkBalancedParentheses(str));
        }
    }
}
