#include <stdio.h>

void bucketSort(int arr[], int n) {
    if (n <= 0) {
        return;
    }

    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    int buckets[max_val + 1];
    for (int i = 0; i <= max_val; i++) {
        buckets[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        buckets[arr[i]]++;
    }

    int index = 0;
    for (int i = 0; i <= max_val; i++) {
        while (buckets[i] > 0) {
            arr[index++] = i;
            buckets[i]--;
        }
    }
}

void radixSort(int arr[], int n) {
    if (n <= 0) {
        return;
    }

    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    for (int place = 1; max_val / place > 0; place *= 10) {
        int output[n];
        int count[10] = {0};

        for (int i = 0; i < n; i++) {
            count[(arr[i] / place) % 10]++;
        }

        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / place) % 10] - 1] = arr[i];
            count[(arr[i] / place) % 10]--;
        }

        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }
        printf("Pass - %d",place);
    }
}

int main() {
    int n, choice;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        printf("Enter %d element: ", i);
        scanf("%d", &arr[i]);
    }

    do {
        printf("Enter\n1. Sort by Bucket Sort \n2. Sort by Radix Sort \n3. Exit\n");
        scanf("%d", &choice);
    printf("\n");
        switch (choice) {
            case 1:
                bucketSort(arr, n);
                printf("Sorted array using Bucket Sort is:\n");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                printf("\n");
                break;

            case 2:
                radixSort(arr, n);
                printf("Sorted array using Radix Sort is:\n");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                printf("\n");
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
