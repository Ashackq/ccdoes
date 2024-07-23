#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>


pid_t num_pid;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubble(int arr[], int n, int a){
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}


void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    num_pid = fork();
    if (num_pid < 0)
        printf("Error in fork execution");
    else if (num_pid == 0)
    {
        printf("This is the child process id %d\n", getpid());
        bubble(arr, n, 1);
        printArray(arr, n);
    }
    else
    {
        printf("This is the parent process id %d\n", getpid());
        bubble(arr, n, 0);
        printArray(arr, n);
        wait(NULL);
    }
    return 0;
}
