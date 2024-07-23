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

void push(const char item) {
    if (isFull()) {
        printf("Stack is full. Cannot push %c.\n", item);
    } else {
        stack[++top] = item;
        printf("Pushed %c onto the stack.\n", item);
    }
}

void pop(char* item) {
    if (isEmpty()) {
        printf("Stack is empty. Cannot pop.\n");
    } else {
        *item = stack[top--];
        item[1] = '\0';
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

int getISP(char op) {
    switch (op) {
        case '^':
            return 4;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        case '(':
            return 0;
        default:
            return -1;
    }
}

int getICP(char op) {
    switch (op) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        case '(':
            return 4;
        default:
            return -1;
    }
}



void InfixToPostfix(const char* infix, char* postfix) {
    int i = 0, j = 0;
    char item;

    while (infix[i] != '\0') {
        if (isalnum(infix[i])) {
            postfix[j] = infix[i];
            j=j+1;
        } else if (infix[i] == '(') {
            push(infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty() && stack[top] != '(') {
                pop(&item);
                postfix[j] = item;
                j=j+1;
            }
            if (!isEmpty() && stack[top] == '(') {
                pop(&item);
            }
           
        } else {
            while (!isEmpty() && getISP(stack[top]) >= getICP(infix[i])) {
                pop(&item);
                j=j+1;
                postfix[j] = item;
            }
            push(infix[i]);
        }
        i=i+1;
    }

    while (!isEmpty()) {
        pop(&item);
        printf("i = %d, j = %d\n",i,j);
        postfix[j] = item;
        j=j+1;
    }
    j=j+1;
    postfix[j] = '\0';
}



void printMenu() {
    printf("\nStack Menu:\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Infix to Postfix Conversion\n");
    printf("4. Evaluation\n")
    printf("5. Display Stack\n");    
    printf("6. Exit\n");
}

int main() {
    char postfix[MAX_SIZE], infix[MAX_SIZE];

    while (1) {
        printMenu();
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                {
                    char item;
                    printf("Enter the item to push: ");
                    scanf(" %c", &item);
                    push(item);
                    break;
                }
            case 2:
                {
                    char item;
                    pop(&item);
                    printf("Popped %c from the stack.\n", item);
                    break;
                }
            case 3:
                {
                    printf("Enter a infix expression: ");
                    scanf("%s", infix);
                    InfixToPostfix(infix, postfix);
                    printf("Postfix expression: %s\n", postfix);
                    break;
                }
            case 4:
                printf("Enter a infix expression: ");
                scanf("%s", infix);
                int ans=0;
                ans = eval(infix);
                printf("Postfix expression: %d\n", ans);
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
