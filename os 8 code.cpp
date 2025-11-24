#include <stdio.h>

int main() {
    int n, i, tq;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], p[n], wt[n], tat[n], rem[n];
    
    // Input burst times
    for (i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &bt[i]);
        rem[i] = bt[i];  // Remaining time initially same
    }

    // Time quantum
    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int time = 0;  // Current time
    int done = 0;

    printf("\nGantt Chart:\n");

    while (done != n) {
        done = 0;
        for (i = 0; i < n; i++) {
            if (rem[i] > 0) {

                printf(" | P%d ", p[i]);

                if (rem[i] > tq) {
                    time += tq;
                    rem[i] -= tq;
                } else {
                    time += rem[i];
                    tat[i] = time;       // completion time
                    wt[i] = tat[i] - bt[i];
                    rem[i] = 0;
                }
            }

            if (rem[i] == 0)
                done++;
        }
    }
    printf("|\n");

    // Display results
    printf("\nRound Robin Scheduling Results:\n");
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

    float avgWT = 0, avgTAT = 0;
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
        avgWT += wt[i];
        avgTAT += tat[i];
    }

    printf("\nAverage Waiting Time: %.2f", avgWT / n);
    printf("\nAverage Turnaround Time: %.2f\n", avgTAT / n);

    return 0;
}

