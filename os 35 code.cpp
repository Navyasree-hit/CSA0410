#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
    int disk[MAX] = {0};
    int indexBlock, fileSize, i;

    printf("---- Indexed File Allocation Simulation ----\n");

    // Take index block
    printf("Enter the index block number (0 - 99): ");
    scanf("%d", &indexBlock);

    if (indexBlock < 0 || indexBlock >= MAX) {
        printf("Invalid index block!\n");
        return 0;
    }

    // Check if index block is free
    if (disk[indexBlock] == 1) {
        printf("Index block already allocated!\n");
        return 0;
    }
    disk[indexBlock] = 1;   // Reserve index block

    // Take file size
    printf("Enter number of blocks required for the file: ");
    scanf("%d", &fileSize);

    int fileBlocks[fileSize];

    printf("\nEnter block numbers for each file block:\n");

    for (i = 0; i < fileSize; i++) {
        printf("Block for file[%d]: ", i);
        scanf("%d", &fileBlocks[i]);

        // Validate block number
        if (fileBlocks[i] < 0 || fileBlocks[i] >= MAX) {
            printf("Invalid block number!\n");
            return 0;
        }

        // Check if block already allocated
        if (disk[fileBlocks[i]] == 1) {
            printf("Block %d already allocated! Allocation failed.\n", fileBlocks[i]);
            return 0;
        }
    }

    // Allocate the blocks
    for (i = 0; i < fileSize; i++) {
        disk[fileBlocks[i]] = 1;
    }

    printf("\nFile successfully allocated using INDEXED ALLOCATION.\n");
    printf("Index Block: %d\n", indexBlock);

    printf("\nFile Block List (Index Block ? Data Blocks):\n");
    printf("%d -> ", indexBlock);
    for (i = 0; i < fileSize; i++) {
        printf("%d ", fileBlocks[i]);
    }
    printf("\n");

    return 0;
}

