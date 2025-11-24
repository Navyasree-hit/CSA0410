#include <stdio.h>

int main() {
    int n, i, time = 0, smallest;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], remaining[n], p[n], pr[n], wt[n], tat[n], completed = 0;

    // Input burst time and priority
    for (i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("\nEnter Burst Time for Process %d: ", i + 1);
        scanf("%d", &bt[i]);

        printf("Enter Priority for Process %d (lower number = higher priority): ", i + 1);
        scanf("%d", &pr[i]);

        remaining[i] = bt[i];
    }

    int prev = -1; // For Gantt chart printing

    printf("\nGantt Chart:\n");

    while (completed < n) {
        smallest = -1;

        // Find process with highest priority that still has remaining time
        for (i = 0; i < n; i++) {
            if (remaining[i] > 0) {
                if (smallest == -1 || pr[i] < pr[smallest])
                    smallest = i;
            }
        }

        // Print Gantt chart only when process changes
        if (prev != smallest) {
            printf(" | P%d ", p[smallest]);
            prev = smallest;
        }

        // Execute the chosen process for 1 unit time
        remaining[smallest]--;
        time++;

        // If process finishes
        if (remaining[smallest] == 0) {
            completed++;
            tat[smallest] = time;              // Completion time
            wt[smallest] = tat[smallest] - bt[smallest];  // Waiting time
        }
    }

    printf("|\n");

    // Display results
    printf("\nPreemptive Priority Scheduling Results:\n");
    printf("Process\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");

    float avgWT = 0, avgTAT = 0;

    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n",
               p[i], pr[i], bt[i], wt[i], tat[i]);

        avgWT += wt[i];
        avgTAT += tat[i];
    }

    printf("\nAverage Waiting Time: %.2f", avgWT / n);
    printf("\nAverage Turnaround Time: %.2f\n", avgTAT / n);

    return 0;
}

