#include <stdio.h>

int main() {
    int AT[10], BT[10], BT1[10], CT[10], TAT[10], WT[10];
    int n, i, j, q, count = 0, sum = 0;
    int done;

    printf("Enter the number of processes ( less than 10 ) : ");
    scanf("%d", &n);

    printf("Enter the time quantum : ");
    scanf("%d", &q);

    for (i = 0; i < n; i++) {
        AT[i] = 0;
        BT[i] = 0;
        BT1[i] = 0;
        CT[i] = 0;
        TAT[i] = 0;
        WT[i] = 0;
    }

    printf("Enter the Burst time for each process : ");
    for (i = 0; i < n; i++) {
        scanf("%d", &BT[i]);
        BT1[i] = BT[i];
    }

    while (1) {
        done = 1;
        for (i = 0; i < n; i++) {
            if (BT[i] > 0) {
                done = 0;
                if (BT[i] > q) {
                    sum += q;
                    BT[i] -= q;
                } else {
                    sum += BT[i];
                    BT[i] = 0;
                }
                break;
            }
        }

        if (done == 1) break;
        if (count == n) {
            count = 0;
            sum = 0;
        }

        BT1[count] = BT[i];
        count++;
    }

    float avgTAT = 0, avgWT = 0;
    for (i = 0; i < n; i++) {
        CT[i] = sum;
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT1[i];
        avgTAT += TAT[i];
        avgWT += WT[i];
    }

    avgTAT /= n;
    avgWT /= n;

    printf("\nPROCESS\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, AT[i], BT1[i], CT[i], TAT[i], WT[i]);
    }

    printf("\nThe average turn around time of process is %f\n", avgTAT);
    printf("\nThe average waiting time of process is %f\n", avgWT);

    printf("\n\nTHE GANTT CHART \n");
    sum = 0;
    printf("0 ");
    for (i = 0; i < n; i++) {
        int execute_time = (BT1[i] > q) ? q : BT1[i];
        sum += execute_time;
        BT1[i] -= execute_time;
        printf("%d %d ", 1 + 1, sum);
        if (BT1[i] > 0) {
            sum += BT1[i];
            printf("%d %d ", 1 + 1, sum);
        }
    }

    return 0;
}