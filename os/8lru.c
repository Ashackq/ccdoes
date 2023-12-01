#include <stdio.h>

int main() {
    int n=14, frames=4, faults = 0, i, j, k, lru;

    // printf("Enter the number of pages in the process stream: ");
    // scanf("%d", &n);

    int pages[15]={7,0,1,2,0,3,0,4,2,3,0,3,2,3};
    // printf("Enter the process stream: ");
    // for (i = 0; i < n; i++) {
    //     scanf("%d", &pages[i]);
    // }

    // printf("Enter the number of frames: ");
    // scanf("%d", &frames);

    int buffer[frames];
    int counter[frames];

    for (i = 0; i < frames; i++) {
        buffer[i] = -1;
        counter[i] = -1;
    }

    printf("\nPage\tFrames\tFaults\n");

    for (i = 0; i < n; i++) {
        printf("%d\t", pages[i]);

        int pageFound = 0;

        for (k = 0; k < frames; k++) {
            if (buffer[k] == pages[i]) {
                pageFound = 1;
                counter[k] = i;
                break;
            }
        }

        if (!pageFound) {
            lru = 0;
            // lru
            for (k = 1; k < frames; k++) {
                if (counter[k] < counter[lru]) {
                    lru = k;
                }
            }

            buffer[lru] = pages[i];
            counter[lru] = i;
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
