#include <stdio.h>
#include <stdlib.h>

int main() {
    int queue[50], n, head, i, j, temp, size;
    int total = 0;

    printf("Enter total number of cylinders: ");
    scanf("%d", &size);

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter the request queue: ");
    for(i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    // Sort the request queue
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(queue[i] > queue[j]) {
                temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }

    // Find position to start scanning
    int start = 0;
    for(i = 0; i < n; i++) {
        if(head < queue[i]) {
            start = i;
            break;
        }
    }

    printf("\nC-SCAN Disk Scheduling Order:\n");

    // Move right from head to end
    for(i = start; i < n; i++) {
        printf("%d -> ", queue[i]);
        total += abs(head - queue[i]);
        head = queue[i];
    }

    // Jump to start (0)
    total += abs(head - (size - 1));
    head = 0;
    total += (size - 1);

    // Move from beginning to left section
    for(i = 0; i < start; i++) {
        printf("%d -> ", queue[i]);
        total += abs(head - queue[i]);
        head = queue[i];
    }

    printf("END");
    printf("\n\nTotal Head Movement = %d cylinders\n", total);

    return 0;
}

