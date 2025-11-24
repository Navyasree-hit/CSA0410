#include <stdio.h>
#include <string.h>

struct File {
    char fname[20];
};

struct Dir {
    char dname[20];
    int file_count;
    struct File files[20];
};

int main() {
    struct Dir dirs[20];
    int dir_count = 0;
    int choice;
    char dname[20], fname[20];
    int i, j;

    while (1) {
        printf("\n\n--- TWO LEVEL DIRECTORY STRUCTURE ---\n");
        printf("1. Create Directory (User)\n");
        printf("2. Create File inside Directory\n");
        printf("3. Display All Directories and Files\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:  // Create Directory
            printf("Enter directory (user) name: ");
            scanf("%s", dname);

            strcpy(dirs[dir_count].dname, dname);
            dirs[dir_count].file_count = 0;
            dir_count++;

            printf("Directory created.\n");
            break;

        case 2:  // Create File in a Directory
            printf("Enter directory name: ");
            scanf("%s", dname);

            // search directory
            for (i = 0; i < dir_count; i++) {
                if (strcmp(dname, dirs[i].dname) == 0)
                    break;
            }

            if (i == dir_count) {
                printf("Directory not found!\n");
                break;
            }

            printf("Enter file name: ");
            scanf("%s", fname);

            strcpy(dirs[i].files[dirs[i].file_count].fname, fname);
            dirs[i].file_count++;

            printf("File created inside directory.\n");
            break;

        case 3:  // Display all
            printf("\n--- DIRECTORY STRUCTURE ---\n");
            for (i = 0; i < dir_count; i++) {
                printf("\nDirectory: %s\n", dirs[i].dname);
                for (j = 0; j < dirs[i].file_count; j++) {
                    printf("   File: %s\n", dirs[i].files[j].fname);
                }
            }
            break;

        case 4:
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}

