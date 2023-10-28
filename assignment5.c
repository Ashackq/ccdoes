#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* createLinkedList() {
    struct Node* head = createNode(0);
    struct Node* current = head;
    int elements = 0;
    int choice = 0;
    
    do {
        elements++;
        int data;
        printf("Enter element %d: ", elements);
        scanf("%d", &data);

        struct Node* newNode = createNode(data);

        current->next = newNode;
        current = newNode;

        printf("Enter 1 for next element or else stop : ");
        scanf("%d", &choice);
    } while (choice == 1);

    head->data = elements;
    return head;
}

void displayLinkedList(struct Node* head) {
    struct Node* current = head->next; 

    if (current == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    printf("Linked list elements: \n");
    printf("Address\t\tData\tNext\t\t\n");
   
    while (current != NULL) {
        printf("%x\t%d\t", (void*)current, current->data);

        if (current->next != NULL)
            printf("%x\n", (void*)current->next);
        else
            printf("NULL\n");

        current = current->next;
    }
    printf("NULL\n");
}

void insertLinkedList(struct Node* head, int pos) {
    struct Node* current = head;
    int counter = 1;
    
    while (current != NULL) {
        if (counter == pos) {
            int data;
            printf("Enter element to insert: ");
            scanf("%d", &data);
            struct Node* newNode = createNode(data);
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        counter++;
        current = current->next;
    }

    printf("Invalid position for insertion.\n");
}

void deleteLinkedList(struct Node* head, int pos) {
    struct Node* current = head;
    struct Node* temp;
    int counter = 0;

    while (current != NULL && counter < pos - 1) {
        current = current->next;
        counter++;
    }

    if (current == NULL || current->next == NULL) {
        printf("Invalid position for deletion.\n");
        return;
    }

    temp = current->next;
    current->next = temp->next;
    temp->next = NULL;
    free(temp);
}

void bubbleSortLinkedList(struct Node* head) {
    int swapped;
    struct Node* current;
    if (head->data <= 1) {
        return;
    }

    do {
        swapped = 0;
        current = head->next;
        while (current->next != NULL) {
            if (current->data > current->next->data) {
                
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
    } while (swapped);
}

void freeLinkedList(struct Node* head) {
    printf("Freeing Linked List...\n");
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        temp->next = NULL;
        free(temp);
    }
    
}

int main() {
    struct Node* head = createLinkedList();
    int pos=0;
    displayLinkedList(head);
    int cho=0;
    do{
    printf("\nEnter \n1. To Insert Element \n2. To Delete Element \n3. To Sort the List \n4. To EXIT\n");
    scanf("%d",&cho);
    switch (cho) {
        case 1:
            printf("Enter where to insert: ");
            scanf("%d", &pos);
            insertLinkedList(head, pos);
            displayLinkedList(head);
            break;
        case 2:
            printf("Enter where to delete: ");
            scanf("%d", &pos);
            deleteLinkedList(head, pos);
            displayLinkedList(head);
            break;
        case 3:
            bubbleSortLinkedList(head);
            printf("Sorted list:\n");
            displayLinkedList(head);
            break;
        case 5: 
            freeLinkedList(head);
            printf("Exiting program.\n");
            break;
        case 4: 
            
            printf("Reversed List.\n");
            displayLinkedList(head);
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (cho != 4);
    return 0;
}
