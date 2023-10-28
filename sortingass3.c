#include <stdio.h>
#include <string.h>

void bucketSort(struct Student students[], int n, int maxRollNumber) {
    const int numBuckets = maxRollNumber + 1;
    struct Student* buckets[numBuckets];

    for (int i = 0; i < numBuckets; i++) {
        buckets[i] = NULL;
    }


    for (int i = 0; i < n; i++) {
        int roll = students[i].rollNumber;
        if (buckets[roll] == NULL) {
            buckets[roll] = &students[i];
        } else {

            struct Student* current = buckets[roll];
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = &students[i];
        }
    }

        for (int i = 0; i < numBuckets; i++) {
        struct Student* current = buckets[i];
        struct Student* prev = NULL;
        while (current != NULL) {
            struct Student* next = current->next;
            struct Student* temp = current;

            
            while (temp != NULL && temp->rollNumber < i) {
                prev = temp;
                temp = temp->next;
            }

            if (temp == current) {
                prev = current;
            } else {
                prev->next = current->next;
                if (temp == NULL) {
                    students[i].next = NULL;
                } else {
                    students[i].next = temp;
                }
                if (prev == NULL) {
                    buckets[i] = &students[i];
                } else {
                    prev->next = &students[i];
                }
            }

            current = next;
        }
    }
}

struct Person {
    char name[50];
    int rollno;
    int marks;
    char div;
};

void setstu(struct Person stu[], int n) 
{
    for (int i = 0; i < n; i++) {
    //    printf("Enter Name of student %d\n", i);
    //    scanf("%s", stu[i].name);
        printf("Enter Rollno of student %d\n", i);
        scanf("%d", &stu[i].rollno);
        // printf("Enter Marks of student %d\n", i);
        // scanf("%d", &stu[i].marks);
        // printf("Enter Div of student %d\n", i);
        // scanf(" %c", &stu[i].div);
        printf("\n");
    }
    printf("\n");
}

void getstu(struct Person stu[], int n,int i) 
{
    printf("Name \tRollno \tMarks \tDiv");
    printf("\n");
    for (i; i<=n-1; i++) 
    {
        // printf("%s \t", stu[i].name);
        printf("%d \t", stu[i].rollno);
        // printf("%d \t", stu[i].marks);
        // printf("%c \t", stu[i].div);
        printf("\n");
    }
    printf("\n");
}

void bucketSort(struct Person stu[], int n) {
    struct Node* buckets[NUM_BUCKETS] = { NULL };

    // Distribute elements into buckets based on roll numbers
    for (int i = 0; i < n; i++) {
        int rollno = stu[i].rollno;
        insert(&buckets[rollno], stu[i]);
    }

    // Collect elements from buckets back into the original array
    int index = 0;
    for (int i = 0; i < NUM_BUCKETS; i++) {
        struct Node* current = buckets[i];
        while (current != NULL) {
            stu[index] = current->student;
            index++;
            current = current->next;
        }
    }

    // Free memory used by the buckets
    for (int i = 0; i < NUM_BUCKETS; i++) {
        struct Node* current = buckets[i];
        while (current != NULL) {
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
}

int main() {
    struct Person var1[10];
    int n;
      printf("Enter length of Class : ");
      scanf("%d", &n);  
  
     int choice;
    do {
        printf("Enter\n1. Sort by Bucket Sort \n2. Sort by Radix Sort\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            
            case 1:
                setstu(var1, n);
                bubbleSort(var1,n);
                printf("Sorted structure is- \n");
                getstu(var1, n,0);
                break;
                
            case 2:
                setstu(var1, n);
                selectionSort(var1,n);
                printf("Sorted structure is- \n");
                getstu(var1, n,0);
                break;
            
           

            case 3:
            
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);
    return 0;
}
