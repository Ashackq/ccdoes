#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Stack structure
#define MAX_SIZE 100

typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, char item) {
    if (!isFull(stack)) {
        stack->items[++stack->top] = item;
    } else {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
}

char pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->items[stack->top--];
    } else {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
}

char peek(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->items[stack->top];
    } else {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }
}

// Helper function to determine precedence of operators
int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char infix[], char postfix[]) {
    Stack stack;
    initialize(&stack);

    int i = 0, j = 0;

    while (infix[i] != '\0') {
        char symbol = infix[i];

        if (isalnum(symbol)) {
            postfix[j++] = symbol;
        } else if (symbol == '(') {
            push(&stack, symbol);
        } else if (symbol == ')') {
            while (peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack); // Discard the '('
        } else {
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(symbol)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, symbol);
        }

        i++;
    }

    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
}

// Function to convert infix expression to prefix expression
void infixToPrefix(char infix[], char prefix[]) {
    Stack stack;
    initialize(&stack);

    int i = strlen(infix) - 1, j = 0;

    while (i >= 0) {
        char symbol = infix[i];

        if (isalnum(symbol)) {
            prefix[j++] = symbol;
        } else if (symbol == ')') {
            push(&stack, symbol);
        } else if (symbol == '(') {
            while (peek(&stack) != ')') {
                prefix[j++] = pop(&stack);
            }
            pop(&stack); // Discard the ')'
        } else {
            while (!isEmpty(&stack) && precedence(peek(&stack)) > precedence(symbol)) {
                prefix[j++] = pop(&stack);
            }
            push(&stack, symbol);
        }

        i--;
    }

    while (!isEmpty(&stack)) {
        prefix[j++] = pop(&stack);
    }

    // Reverse the prefix expression
    for (i = 0; i < j / 2; i++) {
        char temp = prefix[i];
        prefix[i] = prefix[j - i - 1];
        prefix[j - i - 1] = temp;
    }

    prefix[j] = '\0';
}

// Function to convert postfix expression to infix expression
void postfixToInfix(char postfix[], char infix[]) {
    Stack stack;
    initialize(&stack);

    int i = 0, j = 0;

    while (postfix[i] != '\0') {
        char symbol = postfix[i];

        if (isalnum(symbol)) {
            push(&stack, symbol);
        } else {
            char operand2 = pop(&stack);
            char operand1 = pop(&stack);

            infix[j++] = '(';
            infix[j++] = operand1;
            infix[j++] = symbol;
            infix[j++] = operand2;
            infix[j++] = ')';
            infix[j] = '\0';

            push(&stack, infix[j - 1]);
        }

        i++;
    }
}

// Function to convert prefix expression to infix expression
void prefixToInfix(char prefix[], char infix[]) {
    Stack stack;
    initialize(&stack);

    int i = strlen(prefix) - 1, j = 0;

    while (i >= 0) {
        char symbol = prefix[i];

        if (isalnum(symbol)) {
            push(&stack, symbol);
        } else {
            char operand1 = pop(&stack);
            char operand2 = pop(&stack);

            infix[j++] = '(';
            infix[j++] = operand1;
            infix[j++] = symbol;
            infix[j++] = operand2;
            infix[j++] = ')';
            infix[j] = '\0';

            push(&stack, infix[j - 1]);
        }

        i--;
    }
}

// Function to convert postfix expression to prefix expression
void postfixToPrefix(char postfix[], char prefix[]) {
    Stack stack;
    initialize(&stack);

    int i = 0, j = 0;

    while (postfix[i] != '\0') {
        char symbol = postfix[i];

        if (isalnum(symbol)) {
            push(&stack, symbol);
        } else {
            char operand2 = pop(&stack);
            char operand1 = pop(&stack);

            prefix[j++] = symbol;
            prefix[j++] = operand1;
            prefix[j++] = operand2;
            prefix[j] = '\0';

            push(&stack, prefix[j - 1]);
        }

        i++;
    }
}

// Function to convert prefix expression to postfix expression
void prefixToPostfix(char prefix[], char postfix[]) {
    Stack stack;
    initialize(&stack);

    int i = strlen(prefix) - 1, j = 0;

    while (i >= 0) {
        char symbol = prefix[i];

        if (isalnum(symbol)) {
            postfix[j++] = symbol;
        } else {
            char operand1 = pop(&stack);
            char operand2 = pop(&stack);

            postfix[j++] = operand1;
            postfix[j++] = operand2;
            postfix[j++] = symbol;
            postfix[j] = '\0';

            push(&stack, postfix[j - 1]);
        }

        i--;
    }

    // Reverse the postfix expression
    for (i = 0; i < j / 2; i++) {
        char temp = postfix[i];
        postfix[i] = postfix[j - i - 1];
        postfix[j - i - 1] = temp;
    }
}

// Function to evaluate postfix expression
int evaluatePostfix(char postfix[]) {
    Stack stack;
    initialize(&stack);

    int i = 0;

    while (postfix[i] != '\0') {
        char symbol = postfix[i];

        if (isdigit(symbol)) {
            push(&stack, symbol - '0'); // Convert character to integer
        } else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);

            switch (symbol) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator\n");
                    exit(EXIT_FAILURE);
            }
        }

        i++;
    }

    return pop(&stack);
}

// Function to evaluate prefix expression
int evaluatePrefix(char prefix[]) {
    Stack stack;
    initialize(&stack);

    int i = strlen(prefix) - 1;

    while (i >= 0) {
        char symbol = prefix[i];

        if (isdigit(symbol)) {
            push(&stack, symbol - '0'); // Convert character to integer
        } else {
            int operand1 = pop(&stack);
            int operand2 = pop(&stack);

            switch (symbol) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator\n");
                    exit(EXIT_FAILURE);
            }
        }

        i--;
    }

    return pop(&stack);
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE], prefix[MAX_SIZE];
    int result;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Infix to Postfix\n");
        printf("2. Infix to Prefix\n");
        printf("3. Postfix to Infix\n");
        printf("4. Prefix to Infix\n");
        printf("5. Postfix to Prefix\n");
        printf("6. Prefix to Postfix\n");
        printf("7. Evaluate Postfix Expression\n");
        printf("8. Evaluate Prefix Expression\n");
        printf("9. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Infix Expression: ");
                scanf("%s", infix);
                infixToPostfix(infix, postfix);
                printf("Postfix Expression: %s\n", postfix);
                break;
            case 2:
                printf("Enter Infix Expression: ");
                scanf("%s", infix);
                infixToPrefix(infix, prefix);
                printf("Prefix Expression: %s\n", prefix);
                break;
            case 3:
                printf("Enter Postfix Expression: ");
                scanf("%s", postfix);
                postfixToInfix(postfix, infix);
                printf("Infix Expression: %s\n", infix);
                break;
            case 4:
                printf("Enter Prefix Expression: ");
                scanf("%s", prefix);
                prefixToInfix(prefix, infix);
                printf("Infix Expression: %s\n", infix);
                break;
            case 5:
                printf("Enter Postfix Expression: ");
                scanf("%s", postfix);
                postfixToPrefix(postfix, prefix);
                printf("Prefix Expression: %s\n", prefix);
                break;
            case 6:
                printf("Enter Prefix Expression: ");
                scanf("%s", prefix);
                prefixToPostfix(prefix, postfix);
                printf("Postfix Expression: %s\n", postfix);
                break;
            case 7:
                printf("Enter Postfix Expression: ");
                scanf("%s", postfix);
                result = evaluatePostfix(postfix);
                printf("Result: %d\n", result);
                break;
            case 8:
                printf("Enter Prefix Expression: ");
                scanf("%s", prefix);
                result = evaluatePrefix(prefix);
                printf("Result: %d\n", result);
                break;
            case 9:
                printf("Exiting program\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice. Please enter a number between 1 and 9.\n");
        }
    }

    return 0;
}
