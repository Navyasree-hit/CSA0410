#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, i;
    int requests[100];
    int totalHeadMovement = 0;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the disk request queue:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("\nFCFS Disk Scheduling Order:\n");
    printf("%d", head);

    // FCFS processing
    for(i = 0; i < n; i++) {
        totalHeadMovement += abs(requests[i] - head);
        head = requests[i];
        printf(" -> %d", head);
    }

    printf("\n\nTotal Head Movement = %d cylinders\n", totalHeadMovement);

    return 0;
}

