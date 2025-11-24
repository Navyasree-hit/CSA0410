#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>   // For directory operations

int main() {
    DIR *d;
    struct dirent *dir;

    d = opendir(".");   // Open current directory

    if (d == NULL) {
        printf("Unable to open directory!\n");
        return 1;
    }

    printf("Files and Directories in current folder:\n\n");

    while ((dir = readdir(d)) != NULL) {
        printf("%s\n", dir->d_name);
    }

    closedir(d);
    return 0;
}

