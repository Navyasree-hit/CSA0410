#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void createFile();
void writeFile();
void readFile();
void appendFile();
void deleteFile();

int main() {
    int choice;

    while (1) {
        printf("\n===== FILE MANAGEMENT OPERATIONS =====\n");
        printf("1. Create a File\n");
        printf("2. Write to a File\n");
        printf("3. Read a File\n");
        printf("4. Append to File\n");
        printf("5. Delete a File\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: createFile(); break;
            case 2: writeFile(); break;
            case 3: readFile(); break;
            case 4: appendFile(); break;
            case 5: deleteFile(); break;
            case 6: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

void createFile() {
    char filename[50];
    FILE *fp;

    printf("Enter file name to create: ");
    scanf("%s", filename);

    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error creating file!\n");
        return;
    }
    printf("File '%s' created successfully!\n", filename);
    fclose(fp);
}

void writeFile() {
    char filename[50], data[200];
    FILE *fp;

    printf("Enter file name to write: ");
    scanf("%s", filename);

    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("File does not exist!\n");
        return;
    }

    printf("Enter text to write: ");
    fflush(stdin);
    fgets(data, sizeof(data), stdin);

    fputs(data, fp);
    printf("Data written successfully!\n");
    fclose(fp);
}

void readFile() {
    char filename[50], ch;
    FILE *fp;

    printf("Enter file name to read: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File not found!\n");
        return;
    }

    printf("\n--- File Content ---\n");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    printf("\n--- End of File ---\n");
    fclose(fp);
}

void appendFile() {
    char filename[50], data[200];
    FILE *fp;

    printf("Enter file name to append: ");
    scanf("%s", filename);

    fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("File not found!\n");
        return;
    }

    printf("Enter text to append: ");
    fflush(stdin);
    fgets(data, sizeof(data), stdin);

    fputs(data, fp);
    printf("Data appended successfully!\n");
    fclose(fp);
}

void deleteFile() {
    char filename[50];

    printf("Enter file name to delete: ");
    scanf("%s", filename);

    if (remove(filename) == 0)
        printf("File '%s' deleted successfully!\n", filename);
    else
        printf("Error deleting file or file not found!\n");
}

