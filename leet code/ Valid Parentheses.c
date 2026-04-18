#include <stdbool.h>
#include <stdlib.h>

bool isValid(char* s) {
    char stack[10000];
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];

        // Push opening brackets
        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        }
        else {
            // If stack empty → invalid
            if (top == -1) return false;

            char topChar = stack[top--];

            // Check matching
            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                return false;
            }
        }
    }

    // Stack should be empty
    return top == -1;
}