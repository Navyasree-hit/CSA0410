#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <sys/stat.h>
#include <windows.h>

int main() {

    int fd;
    char buffer[50];
    struct _stat fileStat;

    // 1. Open file using _open()
    fd = _open("sample.txt", _O_RDONLY);
    if (fd < 0) {
        printf("Cannot open sample.txt\n");
        return 1;
    }
    printf("File opened successfully.\n");

    // 2. _lseek()
    _lseek(fd, 5, SEEK_SET);
    _read(fd, buffer, 10);
    buffer[10] = '\0';

    printf("After seeking, 10 chars = %s\n", buffer);

    // 3. _stat()
    if (_stat("sample.txt", &fileStat) == 0) {
        printf("\nFile size  : %ld bytes\n", fileStat.st_size);
        printf("Permissions: %o\n", fileStat.st_mode & 0777);
    } else {
        printf("stat() failed.\n");
    }

    _close(fd);

    // 4. Directory reading in Windows (instead of opendir/readdir)
    printf("\nDirectory listing:\n");

    WIN32_FIND_DATA findFileData;
    HANDLE hFind = FindFirstFile("*.*", &findFileData);

    if (hFind == INVALID_HANDLE_VALUE) {
        printf("Could not open directory.\n");
        return 1;
    }

    do {
        printf("%s\n", findFileData.cFileName);
    } while (FindNextFile(hFind, &findFileData));

    FindClose(hFind);

    return 0;
}

