#include <stdio.h>

#define NUM_PROCESSES 5
#define NUM_RESOURCES 3

int available[NUM_RESOURCES];
int maximum[NUM_PROCESSES][NUM_RESOURCES];
int allocation[NUM_PROCESSES][NUM_RESOURCES];
int need[NUM_PROCESSES][NUM_RESOURCES];


//request access algo
int reqacc(int process,int request[]){
        for (int i = 0; i < NUM_RESOURCES; i++) {
		if (request[i] > need[process][i]) {
		    printf("Request is less than the need...please request less resources///\n");
		    return 0;
		}
        }
	for (int i = 0; i < NUM_RESOURCES; i++)  {
		if(request[i] > available[i]){
		    printf("There are less resourses available...please request less resources///\n");
		    return 0;
		}
        }
		
	for (int i = 0; i < NUM_RESOURCES; i++) {
		available[i] -= request[i];
		allocation[process][i] += request[i];
		need[process][i] -= request[i];
	}
	printf("Temporary changes are done///\n");
	return 1;
}
	

//safety algo
int isSafe() {
	printf("Checking for safety.....\n");
    int work[NUM_RESOURCES];
    int finish[NUM_PROCESSES] = {0};
	int safeseq[NUM_PROCESSES];
	int index =0;
    //work = available
    for (int i = 0; i < NUM_RESOURCES; i++) {
        work[i] = available[i];
    }

 

    //safe state check
    int count = 0;
    while (count < NUM_PROCESSES) {
        int found = 0;
        for (int i = 0; i < NUM_PROCESSES; i++) {
            if (finish[i] == 0) {
                int j;
                for (j = 0; j < NUM_RESOURCES; j++) {
                    if (need[i][j] > work[j]) {
                        break;
                    }
                }
                if (j == NUM_RESOURCES) {
                    for (j = 0; j < NUM_RESOURCES; j++) {
                        work[j] += allocation[i][j];
                    }
                    finish[i] = 1;
                    found = 1;
                    safeseq[index] =i;
                    index +=1;
                }
            }
        }
        if (found == 0) {
            break;
        }
        count++;
    }

    //true if all the process are finished
    for (int i = 0; i < NUM_PROCESSES; i++) {
        if (finish[i] == 0) {
        	printf("System will not be safe///\n");
            return 0;
        }
    }
    printf("Safe sqeuence is - ");
    for (int i = 0; i < NUM_PROCESSES; i++) {
        	
        	if (i==(NUM_PROCESSES-1)){
        		printf("P%d",safeseq[i]);
        	}else{
        		printf("P%d->",safeseq[i]);
        	}
    }
    printf("\n");
    return 1;
}
int main() {
    // Initialize the available, maximum, allocation, and need matrices
    int process, request[NUM_RESOURCES];
    printf("Enter the available resources:\n");
    for (int i = 0; i < NUM_RESOURCES; i++) {
        scanf("%d", &available[i]);
    }

    printf("Enter the maximum resource allocation for each process:\n");
    for (int i = 0; i < NUM_PROCESSES; i++) {
        for (int j = 0; j < NUM_RESOURCES; j++) {
            scanf("%d", &maximum[i][j]);
        }
    }
    printf("Enter the resource allocation for each process:\n");
    for (int i = 0; i < NUM_PROCESSES; i++) {
        for (int j = 0; j < NUM_RESOURCES; j++) {
            scanf("%d", &allocation[i][j]);
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }
    printf("Need Matrix - :\n");
    for (int i = 0; i < NUM_PROCESSES; i++) {
        for (int j = 0; j < NUM_RESOURCES; j++) {
            printf("%d ",need[i][j]);
        }
        printf("\n");
    }
    int cho =0;
	printf("\nEnter 1 to continue to request and 0 to stop :\n");
	scanf("%d", &cho);
    while(cho == 1){
	    printf("\nEnter the process that is requesting resources :\nP");
	    scanf("%d", &process);
	    printf("Enter the resources requested (1 0 2):\n");
	    for (int i = 0; i < NUM_RESOURCES; i++) {
		scanf("%d", &request[i]);
	    }
	    
	    if (reqacc(process,request)){
		    if (isSafe() == 1) {
			printf("Request can be granted. System is in a safe state.\n");
			printf("Commiting the changes///\n");
		    } else{
		    	for (int i = 0; i < NUM_RESOURCES; i++) {
				available[i] += request[i];
				allocation[process][i] -= request[i];
				need[process][i] += request[i];
				}
			printf("Request cannot be granted. System remains in a safe state.\n");
		    }
	    }
	    else{
	    	printf("Request cannot be granted. Due to above reason\n");
	    }
	printf("\nEnter 1 to continue to request and 0 to stop :\n");
	scanf("%d", &cho);
    }

    return 0;
}
