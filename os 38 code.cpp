#include <stdio.h>
#include <stdlib.h>

int main() {
    int queue[50], n, head, i, j, temp, size, direction;
    int total = 0;

    printf("Enter total number of cylinders: ");
    scanf("%d", &size);

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the request queue: ");
    for (i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter direction (0 = left, 1 = right): ");
    scanf("%d", &direction);

    // Sort the request queue
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (queue[i] > queue[j]) {
                temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }

    // Find the split index
    int index = 0;
    for (i = 0; i < n; i++) {
        if (queue[i] > head) {
            index = i;
            break;
        }
    }

    printf("\nSCAN Disk Scheduling Order:\n");

    if (direction == 1) {  
        /* Moving right (towards higher cylinder numbers) */
        for (i = index; i < n; i++) {
            printf("%d -> ", queue[i]);
            total += abs(head - queue[i]);
            head = queue[i];
        }

        // Move to the end (size-1)
        total += abs(head - (size - 1));
        head = size - 1;

        // Reverse direction
        for (i = index - 1; i >= 0; i--) {
            printf("%d -> ", queue[i]);
            total += abs(head - queue[i]);
            head = queue[i];
        }

    } else {  
        /* Moving left (towards lower cylinder numbers) */
        for (i = index - 1; i >= 0; i--) {
            printf("%d -> ", queue[i]);
            total += abs(head - queue[i]);
            head = queue[i];
        }

        // Move to the beginning (0)
        total += abs(head - 0);
        head = 0;

        // Reverse direction
        for (i = index; i < n; i++) {
            printf("%d -> ", queue[i]);
            total += abs(head - queue[i]);
            head = queue[i];
        }
    }

    printf("END");
    printf("\n\nTotal Head Movement = %d cylinders\n", total);

    return 0;
}

