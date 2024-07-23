#include <stdio.h>
#include <string.h>

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

int linearSearch(struct Person stu[], int n, int rollno) {
    for (int i = 0; i < n; i++) {
        if (stu[i].rollno == rollno) {
            return i;
        }
    }
    return -1;
}


void bubbleSort(struct Person stu[], int n) {
        printf("Sorting elements by Bubble sort DONE!!\n-------------------------------------------\n");
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (stu[j].rollno > stu[j + 1].rollno) 
            {
                struct Person temp = stu[j]; //swap idar karo
                stu[j] = stu[j + 1];
                stu[j + 1] = temp;
            }
        }
        printf("Pass: %d\n",i);
        getstu(stu, n,0);
    }
        printf("Sorting elements by Bubble sort DONE!!\n-------------------------------------------\n");
}


int binarySearch(struct Person stu[], int n, int rollno) 
{
    bubbleSort(stu,n);
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (stu[mid].rollno == rollno) {
            return mid;
        }

        if (stu[mid].rollno < rollno) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;

}


void selectionSort(struct Person stu[], int n) {
        printf("Sorting elements by Selection sort!!\n-------------------------------------------\n");
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (stu[j].rollno < stu[minIndex].rollno) {
                minIndex = j;
            }
        }
        struct Person temp = stu[i];//swap idar karo
        stu[i] = stu[minIndex];
        stu[minIndex] = temp;
        printf("Pass: %d\n",i);
        getstu(stu, n,0);
    }
    printf("Sorting elements by Selection sort DONE!!\n-------------------------------------------\n");
}

void insertionSort(struct Person stu[], int n) {
        printf("Sorting elements by Insertion sort!!\n-------------------------------------------\n");
    int i, j;
    struct Person key;

    for (i = 1; i < n; i++) {
        key = stu[i];
        j = i - 1;

        
        while (j >= 0 && stu[j].rollno > key.rollno) {
            stu[j + 1] = stu[j];
            j = j - 1;
        }
        stu[j + 1] = key;
        printf("Pass: %d\n",i);
        getstu(stu, n,0);
    }
        printf("Sorting elements by Insertion sort DONE!!\n-------------------------------------------\n");
}

void shellSort(struct Person stu[], int n) {
    printf("Sorting elements by Shell sort\n-------------------------------------------\n");
    int gap, i, j,counter=0;
    struct Person temp;

    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = stu[i];

            for (j = i; j >= gap && stu[j - gap].rollno > temp.rollno; j -= gap) {
                stu[j] = stu[j - gap];
            }

            stu[j] = temp;
        }
        printf("Pass: %d\n",counter++);
        getstu(stu, n,0);
    }
    printf("Sorting elements by Shell sort DONE!!\n-------------------------------------------\n");
}

int main() {
    struct Person var1[10];
    int n;
      printf("Enter length of Class : ");
      scanf("%d", &n);  
  
     int choice;
    do {
        printf("Enter\n1. Search Student by linearsearch\n2. Search Student by binarysearch\n3. Sort by Bubble Sort\n4. Sort by Selection Sort\n5. Sort by Insertion Sort\n6. Sort by Shell Sort\n7. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
setstu(var1, n);
                int rn;
                printf("Enter the Rollno to search: ");
                scanf("%d", &rn);
                int in = linearSearch(var1, n, rn);
                if (in != -1) {
                    printf("Student found at index %d\n", in);
                    getstu(var1,in+1,in);
                } else {
                    printf("Student with Rollno %d not found.\n", rn);
                }
                break;
            }
            case 2:
setstu(var1, n);
                int rn;
                printf("Enter the Rollno to search: ");
                scanf("%d", &rn);

                int in = binarySearch(var1, n, rn);

                if (in != -1) {
                    printf("Student found at index %d\n", in);
                    getstu(var1,in+1,in);
                } else {
                    printf("Student with Rollno %d not found.\n", in);
                }
                break;

            case 3:
setstu(var1, n);
                bubbleSort(var1,n);
                printf("Sorted structure is- \n");
                getstu(var1, n,0);
                break;
                
            case 4:
setstu(var1, n);
                selectionSort(var1,n);
                printf("Sorted structure is- \n");
                getstu(var1, n,0);
                break;
            
            case 5:
setstu(var1, n);
                insertionSort(var1,n);
                printf("Sorted structure is- \n");
                getstu(var1, n,0);
                break;

            case 6:
setstu(var1, n);
                shellSort(var1,n);
                printf("Sorted structure is- \n");
                getstu(var1, n,0);
                break;

            case 7:
            
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 7);
    return 0;
}
