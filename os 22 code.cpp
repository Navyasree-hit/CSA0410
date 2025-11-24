#include <stdio.h>

int main() {
    int blockSize[20], processSize[20];
    int blockCount, processCount;
    int allocation[20];

    printf("Enter number of memory blocks: ");
    scanf("%d", &blockCount);

    printf("Enter size of each block:\n");
    for (int i = 0; i < blockCount; i++) {
        printf("Block %d size: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    printf("\nEnter number of processes: ");
    scanf("%d", &processCount);

    printf("Enter size of each process:\n");
    for (int i = 0; i < processCount; i++) {
        printf("Process %d size: ", i + 1);
        scanf("%d", &processSize[i]);
        allocation[i] = -1;   // Initially unallocated
    }

    // Best Fit Allocation
    for (int i = 0; i < processCount; i++) {
        int bestIndex = -1;

        for (int j = 0; j < blockCount; j++) {

            // Check if block can accommodate the process
            if (blockSize[j] >= processSize[i]) {

                // First suitable OR smaller than previous best
                if (bestIndex == -1 || blockSize[j] < blockSize[bestIndex]) {
                    bestIndex = j;
                }
            }
        }

        // Allocate if suitable block is found
        if (bestIndex != -1) {
            allocation[i] = bestIndex;
            blockSize[bestIndex] -= processSize[i];
        }
    }

    // Output
    printf("\nProcess No.\tProcess Size\tBlock Allocated\n");
    for (int i = 0; i < processCount; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}

