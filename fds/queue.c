#include <stdio.h>
#include <stdlib.h>

struct Job {
    int jobId;
    struct Job* next;
};

struct JobQueue {
    struct Job* front;
    struct Job* rear;
};

struct Job* createJob(int jobId) {
    struct Job* newJob = (struct Job*)malloc(sizeof(struct Job));
    if (newJob != NULL) {
        newJob->jobId = jobId;
        newJob->next = NULL;
    }
    return newJob;
}

struct JobQueue* initializeQueue() {
    struct JobQueue* queue = (struct JobQueue*)malloc(sizeof(struct JobQueue));
    if (queue != NULL) {
        queue->front = NULL;
        queue->rear = NULL;
    }
    return queue;
}

void addJob(struct JobQueue* queue, int jobId) {
    struct Job* newJob = createJob(jobId);
    if (newJob == NULL) {
        printf("Failed to create a new job. Memory allocation error.\n");
        return;
    }

    if (queue->rear == NULL) {
        queue->front = newJob;
        queue->rear = newJob;
    } else {
        queue->rear->next = newJob;
        queue->rear = newJob;
    }

    printf("Job %d added to the queue.\n", jobId);
}

void deleteJob(struct JobQueue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty. No job to delete.\n");
        return;
    }

    struct Job* temp = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    printf("Job %d deleted from the queue.\n", temp->jobId);
    free(temp);
}

void displayQueue(struct JobQueue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct Job* current = queue->front;
    printf("Jobs in the queue: ");
    while (current != NULL) {
        printf("%d ", current->jobId);
        current = current->next;
    }
    printf("\n");
}

void freeQueue(struct JobQueue* queue) {
    struct Job* current = queue->front;
    while (current != NULL) {
        struct Job* next = current->next;
        free(current);
        current = next;
    }
    free(queue);
}

int main() {
    struct JobQueue* jobQueue = initializeQueue();
    int choice, jobId;

    do {
        printf("\nMenu:\n");
        printf("1. Add Job\n");
        printf("2. Delete Job\n");
        printf("3. Display Jobs\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Job ID: ");
                scanf("%d", &jobId);
                addJob(jobQueue, jobId);
                break;

            case 2:
                deleteJob(jobQueue);
                break;

            case 3:
                displayQueue(jobQueue);
                break;

            case 4:
                printf("Exiting program. Freeing memory...\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    freeQueue(jobQueue);

    return 0;
}
