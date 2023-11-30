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

char* push(const char* item) {
    if (isFull()) {
        printf("Stack is full. Cannot push %s.\n", item);
        return NULL;
    } else {
        char* newItem = strdup(item);
        strcpy(stack[++top], newItem);
        printf("Pushed %s onto the stack.\n", item);
        return newItem;
    }
}

char* pop() {
    if (isEmpty()) {
        printf("Stack is empty. Cannot pop.\n");
        return NULL;
    } else {
        char* poppedItem = strdup(stack[top]);
        top--;
        return poppedItem;
    }
}

void postfixToInfix(const char* postfix ) {
    char infix[MAX_SIZE];
    for (int i = 0; postfix[i]; i++) {
        if (isalpha(postfix[i])) {
            char operand[2] = { postfix[i], '\0' };
            push(operand);
        } else {
            char* operand2 = pop();
            char* operand1 = pop();
            sprintf(infix, "(%s%c%s)", operand1, postfix[i], operand2);
            push(infix);
            free(operand1);
            free(operand2);
        }
    }
    char* result = pop();
    printf("Infix expression:\n");
    printf("%s", result);
    free(result);
}

int main() {
    char postfix[MAX_SIZE];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);
    postfixToInfix(postfix);
    return 0;
}
