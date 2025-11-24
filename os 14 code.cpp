#include <stdio.h>
#include <string.h>

#define MAX_FILES 50
#define NAME_LEN 50

int main() {
    char directory[MAX_FILES][NAME_LEN];
    int fileCount = 0;
    int choice;
    char filename[NAME_LEN];
    int i, found;

    while (1) {
        printf("\n=== SINGLE LEVEL DIRECTORY ===\n");
        printf("1. Create File\n");
        printf("2. Delete File\n");
        printf("3. Search File\n");
        printf("4. List Files\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            if (fileCount >= MAX_FILES) {
                printf("Directory is full. Cannot add more files.\n");
                break;
            }
            printf("Enter file name to create: ");
            scanf("%s", filename);

            // Check duplicate
            found = 0;
            for (i = 0; i < fileCount; i++) {
                if (strcmp(directory[i], filename) == 0) {
                    found = 1;
                    break;
                }
            }

            if (found) {
                printf("File already exists!\n");
            } else {
                strcpy(directory[fileCount], filename);
                fileCount++;
                printf("File created successfully.\n");
            }
            break;

        case 2:
            printf("Enter file name to delete: ");
            scanf("%s", filename);
            found = -1;

            for (i = 0; i < fileCount; i++) {
                if (strcmp(directory[i], filename) == 0) {
                    found = i;
                    break;
                }
            }

            if (found == -1) {
                printf("File not found.\n");
            } else {
                for (i = found; i < fileCount - 1; i++) {
                    strcpy(directory[i], directory[i + 1]);
                }
                fileCount--;
                printf("File deleted successfully.\n");
            }
            break;

        case 3:
            printf("Enter file name to search: ");
            scanf("%s", filename);
            found = 0;

            for (i = 0; i < fileCount; i++) {
                if (strcmp(directory[i], filename) == 0) {
                    found = 1;
                    break;
                }
            }

            if (found)
                printf("File found in directory.\n");
            else
                printf("File not found.\n");

            break;

        case 4:
            printf("\nFiles in Directory:\n");
            if (fileCount == 0) {
                printf("No files present.\n");
            } else {
                for (i = 0; i < fileCount; i++) {
                    printf("%s\n", directory[i]);
                }
            }
            break;

        case 5:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

