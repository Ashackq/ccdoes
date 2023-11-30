#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_SIZE 20

char stack[MAX_SIZE][MAX_SIZE];
int top = -1;

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == MAX_SIZE - 1;
}

void push(const char* item) {
    if (isFull()) {
        printf("Stack is full. Cannot push %s.\n", item);
    } else {
        strcpy(stack[++top], item);
        printf("Pushed %s onto the stack.\n", item);
    }
}

void pop(char* item) {
    if (isEmpty()) {
        printf("Stack is empty. Cannot pop.\n");
    } else {
        strcpy(item, stack[top--]);
    }
}
 
void postfixToInfix(const char* postfix, char* infix) {
    for (int i = 0; postfix[i]; i++) {
        if (isalpha(postfix[i])) {
            char operand[2] = { postfix[i], '\0' };
            push(operand);
        } else {
            char operand2[MAX_SIZE], operand1[MAX_SIZE];
            pop(operand2);
            pop(operand1);
            sprintf(infix, "(%s%c%s)", operand1, postfix[i], operand2);
            push(infix);
        }
    }
}

int main() {
    char postfix[MAX_SIZE], infix[MAX_SIZE];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    postfixToInfix(postfix, infix);
    printf("Infix expression: %s\n", infix);

    return 0;
}
