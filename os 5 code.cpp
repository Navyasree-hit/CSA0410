#include <stdio.h>

int main() {
    int n, i, j;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], p[n], pr[n], wt[n], tat[n], temp;

    // Input burst time and priority
    for (i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("\nEnter Burst Time for Process %d: ", i + 1);
        scanf("%d", &bt[i]);

        printf("Enter Priority for Process %d (lower number = higher priority): ", i + 1);
        scanf("%d", &pr[i]);
    }

    // Sorting processes based on priority (lower number means higher priority)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (pr[j] < pr[i]) {
                // swap priority
                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;

                // swap burst time
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // swap process ID
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // First process has zero waiting time
    wt[0] = 0;

    // Calculate waiting time
    for (i = 1; i < n; i++) {
        wt[i] = 0;
        for (j = 0; j < i; j++)
            wt[i] += bt[j];
    }

    // Calculate turnaround time
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }

    // Display results
    printf("\nPriority Scheduling (Non-Preemptive)\n");
    printf("Process\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n",
               p[i], pr[i], bt[i], wt[i], tat[i]);
    }

    float avgwt = 0, avgtat = 0;
    for (i = 0; i < n; i++) {
        avgwt += wt[i];
        avgtat += tat[i];
    }

    printf("\nAverage Waiting Time: %.2f", avgwt / n);
    printf("\nAverage Turnaround Time: %.2f\n", avgtat / n);

    return 0;
}

