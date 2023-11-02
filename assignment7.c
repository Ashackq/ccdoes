#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 20

int stack[MAX_SIZE];
int top = -1;

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == MAX_SIZE - 1;
}

void display() {
    if (!isEmpty()) {
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    } else {
        printf("Stack is empty. Please Push first.\n");
    }
}


void push(int item) {
    if (isFull()) {
        printf("Stack is full. Cannot push %d.\n", item);
    } else {
        stack[++top] = item;
        printf("Pushed %d onto the stack.\n", item);
    }
}


int pop() {
    if (isEmpty()) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    } else {
        int item = stack[top--];
        printf("Popped %d from the stack.\n", item);
        return item;
    }
}



int main() {
    int choice, item;
    
    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Check if Stack is Empty\n");
        printf("4. Check if Stack is Full\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the item to push: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                item = pop();
                if (item != -1) {
                    printf("Popped item: %d\n", item);
                }
                break;
            case 3:
                if (isEmpty()) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Stack is not empty.\n");
                }
                break;
            case 4:
                if (isFull()) {
                    printf("Stack is full.\n");
                } else {
                    printf("Stack is not full.\n");
                }
                break;
            case 5:
                printf("Displaying Stack.\n");
                display();
                break;
            case 6:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
}
