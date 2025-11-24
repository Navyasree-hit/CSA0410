#include <stdio.h>

int main() {
    int n, i;
    int burst[20], waiting[20], turnaround[20];
    float avg_wait = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("\nEnter Burst Time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d Burst Time: ", i + 1);
        scanf("%d", &burst[i]);
    }

 
    waiting[0] = 0; 

    for (i = 1; i < n; i++) {
        waiting[i] = waiting[i - 1] + burst[i - 1];
    }

    for (i = 0; i < n; i++) {
        turnaround[i] = waiting[i] + burst[i];
    }

    for (i = 0; i < n; i++) {
        avg_wait += waiting[i];
        avg_tat += turnaround[i];
    }

    avg_wait /= n;
    avg_tat /= n;

  
    printf("\nFCFS Scheduling Results:\n");
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n",
               i + 1, burst[i], waiting[i], turnaround[i]);
    }

    printf("\nAverage Waiting Time: %.2f", avg_wait);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat);

    return 0;
}

