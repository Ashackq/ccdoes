#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int prn;
    char name[50];
    struct Student* next;
};

struct Student* createStudent(int prn, const char* name) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    if (newStudent == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newStudent->prn = prn;
    strcpy(newStudent->name, name);
    newStudent->next = NULL;
    return newStudent;
}

struct Student* createClub() {
    printf("Creating Pinnacle Club...\n");
    struct Student* president = createStudent(0, "President");
    struct Student* secretary = createStudent(0, "Secretary");
    president->next = secretary;
    return president;
}

void displayClub(struct Student* president) {
    struct Student* current = president->next;
    
    if (current == NULL) {
        printf("Pinnacle Club is empty.\n");
        return;
    }

    printf("Pinnacle Club members: \n");
    printf("PRN\tName\tNext\t\t\n");
   
    while (current != NULL) {
        printf("%d\t%s\t", current->prn, current->name);

        if (current->next != NULL)
            printf("%p\n", (void*)current->next);
        else
            printf("NULL\n");

        current = current->next;
    }
    printf("NULL\n");
}

void addMember(struct Student* president, int prn, const char* name) {
    struct Student* newMember = createStudent(prn, name);
    newMember->next = president->next;
    president->next = newMember;
}

void deleteMember(struct Student* president, int prn) {
    struct Student* current = president;
    
    while (current->next != NULL) {
        if (current->next->prn == prn) {
            struct Student* temp = current->next;
            current->next = temp->next;
            temp->next = NULL;
            free(temp);
            return;
        }
        current = current->next;
    }

    printf("Member with PRN %d not found.\n", prn);
}

int countMembers(struct Student* president) {
    int count = 0;
    struct Student* current = president->next;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

void reverseClub(struct Student** president) {
    struct Student* prev = NULL;
    struct Student* current = *president;
    struct Student* next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *president = prev;
}

void freeClub(struct Student* president) {
    printf("Freeing Pinnacle Club...\n");
    struct Student* current = president;
    while (current != NULL) {
        struct Student* temp = current;
        current = current->next;
        temp->next = NULL;
        free(temp);
    }
}

int main() {
    struct Student* president = createClub();
    int prn, choice;
    char name[50];
    
    do {
        printf("\nEnter \n1. Add Member \n2. Delete Member \n3. Display Members \n4. Count Members \n5. Reverse Club \n6. Free Club\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter PRN of the new member: ");
                scanf("%d", &prn);
                printf("Enter name of the new member: ");
                scanf("%s", name);
                addMember(president, prn, name);
                break;
            case 2:
                printf("Enter PRN of the member to delete: ");
                scanf("%d", &prn);
                deleteMember(president, prn);
                break;
            case 3:
                displayClub(president);
                break;
            case 4:
                printf("Total number of members in Pinnacle Club: %d\n", countMembers(president));
                break;
            case 5:
                reverseClub(&president);
                printf("Pinnacle Club has been reversed.\n");
                break;
            case 6:
                freeClub(president);
                printf("Freeing Pinnacle Club.\n");
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 6);

    return 0;
}
