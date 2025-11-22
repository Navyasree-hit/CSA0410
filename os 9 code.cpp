#include <windows.h>
#include <stdio.h>
#include <string.h>

#define SHM_SIZE 1024

int main() {
    HANDLE hMapFile;
    LPVOID pBuf;

    hMapFile = CreateFileMapping(
        INVALID_HANDLE_VALUE,
        NULL,
        PAGE_READWRITE,
        0,
        SHM_SIZE,
        "MySharedMemory");

    if (hMapFile == NULL) {
        printf("CreateFileMapping failed\n");
        return 1;
    }

    pBuf = MapViewOfFile(
        hMapFile,
        FILE_MAP_ALL_ACCESS,
        0,
        0,
        SHM_SIZE);

    if (pBuf == NULL) {
        printf("MapViewOfFile failed\n");
        CloseHandle(hMapFile);
        return 1;
    }

    strcpy((char*)pBuf, "Hello, shared memory!");

    printf("Data written to shared memory: %s\n", (char*)pBuf);

    UnmapViewOfFile(pBuf);
    CloseHandle(hMapFile);

    return 0;
}
