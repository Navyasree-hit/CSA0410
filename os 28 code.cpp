#include <stdio.h>
#include <string.h>

int main() {
    char filename[50], pattern[50], line[200];
    FILE *fp;
    int lineNumber = 1, found = 0;

    printf("Enter file name: ");
    scanf("%s", filename);

    printf("Enter pattern to search: ");
    scanf("%s", pattern);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found!\n");
        return 1;
    }

    printf("\nLines containing '%s':\n", pattern);

    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, pattern)) {   // Search for pattern in the line
            printf("Line %d: %s", lineNumber, line);
            found = 1;
        }
        lineNumber++;
    }

    if (!found) {
        printf("No match found!\n");
    }

    fclose(fp);
    return 0;
}

