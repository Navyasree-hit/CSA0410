#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
    int fileSize, startBlock, disk[MAX];
    int i, record, choice;

    // Initialize disk blocks (0 = free, 1 = allocated)
    for (i = 0; i < MAX; i++) {
        disk[i] = 0;
    }

    printf("---- Sequential File Allocation Simulation ----\n");

    // Take file size
    printf("Enter number of blocks required for the file: ");
    scanf("%d", &fileSize);

    // Starting block
    printf("Enter the starting block number (0 - 99): ");
    scanf("%d", &startBlock);

    // Check if enough sequence of free blocks is available
    int freeBlocks = 1;
    for (i = startBlock; i < startBlock + fileSize; i++) {
        if (i >= MAX || disk[i] == 1) {
            freeBlocks = 0;
            break;
        }
    }

    if (!freeBlocks) {
        printf("\nFile cannot be allocated sequentially!\n");
        printf("Reason: Required contiguous blocks are NOT free.\n");
        return 0;
    }

    // Allocate the file
    printf("\nAllocating file...\n");
    for (i = startBlock; i < startBlock + fileSize; i++) {
        disk[i] = 1;
    }

    printf("File allocated from block %d to block %d.\n",
           startBlock, startBlock + fileSize - 1);

    // Menu to access records
    while (1) {
        printf("\n1. Read a Record");
        printf("\n2. Display Allocated Blocks");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter record number to access (1 to %d): ", fileSize);
                scanf("%d", &record);

                if (record < 1 || record > fileSize) {
                    printf("Invalid record number!\n");
                } else {
                    printf("\nAccessing record %d...\n", record);
                    printf("Reading previous %d record(s)... ", record - 1);
                    printf("Record %d accessed successfully.\n", record);
                }
                break;

            case 2:
                printf("\nAllocated Blocks: ");
                for (i = startBlock; i < startBlock + fileSize; i++) {
                    printf("%d ", i);
                }
                printf("\n");
                break;

            case 3:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

