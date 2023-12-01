#include <stdio.h>

int main() {
    int n, frames, faults = 0, i, j, k;

    printf("Enter the number of pages in the process stream: ");
    scanf("%d", &n);

    int pages[n];
    printf("Enter the process stream: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    int buffer[frames];
    
    
    for (i = 0; i < frames; i++) {
        buffer[i] = -1; //-1 for empty
    }


    j = 0; 

    printf("\nPage\tFrames\tFaults\n");

    for (i = 0; i < n; i++) {
        printf("%d\t", pages[i]);
        int pageFound = 0;

        for (k = 0; k < frames; k++) {
            if (buffer[k] == pages[i]) {
                pageFound = 1;
                break;
            }
        }

        if (!pageFound) {
            buffer[j] = pages[i];
            j = (j + 1) % frames;
            faults++;
        }

        for (k = 0; k < frames; k++) {
            printf("%d ", buffer[k]);
        }

        printf("\t%d\n", faults);
    }

    printf("\nTotal Page Faults: %d\n", faults);

    return 0;
}
