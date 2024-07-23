#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 20

char stack[MAX_SIZE];
int top = -1;

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == MAX_SIZE - 1;
}

void push(char item) {
    if (isFull()) {
        printf("Stack is full. Cannot push %c.\n", item);
    } else {
        stack[++top] = item;
        printf("Pushed %c onto the stack.\n", item);
    }
}

char pop() {
    if (isEmpty()) {
        printf("Stack is empty. Cannot pop.\n");
        exit(EXIT_FAILURE);
    } else {
        return stack[top--];
    }
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack contents:\n");
        for (int i = top; i >= 0; i--) {
            printf("%c\n", stack[i]);
        }
    }
}

int precedence(char operator) {
    if (operator == '+' || operator == '-') {
        return 1;
    } else if (operator == '*' || operator == '/') {
        return 2;
    }
    return 0;
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int applyOperator(char operator, int right, int left) {
    switch (operator) {
        case '+':
            return left + right;
        case '-':
            return left - right;
        case '*':
            return left * right;
        case '/':
            return left / right;
        case '^':
            // Assuming ^ represents exponentiation
            int result = 1;
            for (int i = 0; i < right; ++i) {
                result *= left;
            }
            return result;
        default:
            printf("Invalid operator: %c\n", operator);
            exit(EXIT_FAILURE);
    }
}

int evaluateExpression(const char *expression) {
    int values[MAX_SIZE];
    int topValues = -1;

    for (int i = 0; expression[i] != '\0'; ++i) {
        if (isdigit(expression[i])) {
            int num = expression[i] - '0';
            values[++topValues] = num;
        } else if (isOperator(expression[i])) {
            int right = values[topValues--];
            int left = values[topValues--];
            values[++topValues] = applyOperator(expression[i], right, left);
        }
    }

    return values[topValues];
}


void postfixtoinfix(const char *expression, char *infix) {
    char temp[MAX_SIZE];
    int topTemp = -1;

    for (int i = 0; expression[i] != '\0'; ++i) {
        if (isdigit(expression[i])) {
            int num = 0;
            while (isdigit(expression[i])) {
                temp[++topTemp] = expression[i++];
            }
            temp[++topTemp] = '\0';
            strcat(infix, temp);
            strcat(infix, " ");
        } else if (isOperator(expression[i])) {
            temp[++topTemp] = expression[i];
            temp[++topTemp] = '\0';
            strcat(infix, temp);
            strcat(infix, " ");
        }
    }


    infix[strlen(infix) - 1] = '\0';
}

void printMenu() {
    printf("\nStack Menu:\n");
    printf("1. Evaluation\n");
    printf("2. Display Stack\n");
    printf("3. Exit\n");
}

int main() {
    char postfix[MAX_SIZE];
    char infix[MAX_SIZE * 2];

    while (1) {
        printMenu();
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a postfix expression: ");
                scanf("%s", postfix);
                infix[0] = '\0'; 
                postfixtoinfix(postfix, infix);
                printf("Infix expression: %s\n", infix);
                int result = evaluateExpression(postfix);
                printf("Evaluation result: %d\n", result);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
