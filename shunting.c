#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if (top == -1) return -1;
    return stack[top--];
}

// Function to define operator precedence
int precedence(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}

int main() {
    char exp[] = "a+b*(c-d)"; 
    char *e, x;
    
    printf("Infix Expression: %s\n", exp);
    printf("Postfix Output: ");
    
    e = exp;
    
    while (*e != '\0') {
        if (isalnum(*e)) {
            // Rule 1: Operands go to output
            printf("%c", *e);
        } else if (*e == '(') {
            // Rule 2: Left parenthesis to stack
            push(*e);
        } else if (*e == ')') {
            // Rule 3: Pop until '('
            while ((x = pop()) != '(')
                printf("%c", x);
        } else {
            // Rule 4: Check precedence
            while (top != -1 && precedence(stack[top]) >= precedence(*e)) {
                printf("%c", pop());
            }
            push(*e);
        }
        e++;
    }

    // Pop remaining operators from stack
    while (top != -1) {
        printf("%c", pop());
    }
    
    printf("\n");
    return 0;
}