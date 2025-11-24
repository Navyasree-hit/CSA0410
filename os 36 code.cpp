#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BLOCKS 100

// Structure for a disk block
typedef struct Block {
    int blockNumber;
    struct Block *next;
} Block;

// Structure for directory entry
typedef struct {
    char fileName[20];
    Block *start;
    Block *end;
} FileEntry;

// Function to create a new block
Block* createBlock(int num) {
    Block *newBlock = (Block*)malloc(sizeof(Block));
    newBlock->blockNumber = num;
    newBlock->next = NULL;
    return newBlock;
}

// Function to create a file with linked allocation
void createFile(FileEntry files[], int *fileCount) {
    char name[20];
    int numBlocks, blockNum;

    printf("\nEnter file name: ");
    scanf("%s", name);

    printf("Enter number of blocks to allocate: ");
    scanf("%d", &numBlocks);

    FileEntry newFile;
    strcpy(newFile.fileName, name);
    newFile.start = NULL;
    newFile.end = NULL;

    printf("Enter block numbers:\n");
    for (int i = 0; i < numBlocks; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockNum);

        Block *newBlock = createBlock(blockNum);

        if (newFile.start == NULL) {
            newFile.start = newFile.end = newBlock;
        } else {
            newFile.end->next = newBlock;
            newFile.end = newBlock;
        }
    }

    files[*fileCount] = newFile;
    (*fileCount)++;

    printf("\nFile created successfully!\n");
}

// Function to display file allocation
void displayFiles(FileEntry files[], int fileCount) {
    if (fileCount == 0) {
        printf("\nNo files to display.\n");
        return;
    }

    printf("\n----- File Allocation Table (Linked Allocation) -----\n");

    for (int i = 0; i < fileCount; i++) {
        printf("\nFile: %s\n", files[i].fileName);
        printf("Blocks: ");

        Block *temp = files[i].start;
        while (temp != NULL) {
            printf("%d -> ", temp->blockNumber);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Main
int main() {
    FileEntry files[MAX_BLOCKS];
    int fileCount = 0;
    int choice;

    while (1) {
        printf("\n===== LINKED FILE ALLOCATION SIMULATION =====");
        printf("\n1. Create File");
        printf("\n2. Display File Allocation");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createFile(files, &fileCount);
                break;
            case 2:
                displayFiles(files, fileCount);
                break;
            case 3:
                printf("\nExiting...\n");
                exit(0);
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}

