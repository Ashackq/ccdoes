#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

pid_t num_pid;



void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int arr[], int n,int a)
{	
	if (a==0)
	{
		int i, j, min_idx;
		for (i = 0; i < n-1; i++)
		{
			min_idx = i;
			for (j = i+1; j < n; j++)
			{
				if (arr[j] > arr[min_idx])
					{min_idx = j;}
				
			}
		
			if(min_idx != i)
					{swap(&arr[min_idx], &arr[i]);}
		}
		
	}
	else
	{
		int i, j, min_idx;
		for (i = 0; i < n-1; i++)
		{
			min_idx = i;
			for (j = i+1; j < n; j++)
			{
				if (arr[j] < arr[min_idx])
					min_idx = j;
			}
			if(min_idx != i)
				swap(&arr[min_idx], &arr[i]);
		}
	}
}

void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}



int main()
{
	int arr[] = {64, 25, 12, 22, 11};
	int n = sizeof(arr)/sizeof(arr[0]);
	num_pid=fork();
	if(num_pid<0)
		printf("Error in fork execution");
	else
		if(num_pid==0)
		{
			printf("This is the child process id %d\n",getpid());
			selectionSort(arr, n,1);
			printArray(arr, n);
			
		}
		else
		{	
			printf("This is the parent process id %d\n",getpid());
			selectionSort(arr, n,0);
			printArray(arr, n);
			
			wait(NULL);
		}	
	return 0;
}
