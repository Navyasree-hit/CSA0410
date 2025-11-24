#include <windows.h>
#include <stdio.h>
#include <string.h>

int main() {
    HANDLE hSlot, hFile;
    char buffer[100];
    DWORD bytesRead, bytesWritten;

    hSlot = CreateMailslot("\\\\.\\mailslot\\MyMsgQueue", 0, MAILSLOT_WAIT_FOREVER, NULL);
    if (hSlot == INVALID_HANDLE_VALUE) return 1;

    hFile = CreateFile("\\\\.\\mailslot\\MyMsgQueue",
                       GENERIC_WRITE,
                       FILE_SHARE_READ,
                       NULL,
                       OPEN_EXISTING,
                       FILE_ATTRIBUTE_NORMAL,
                       NULL);
    if (hFile == INVALID_HANDLE_VALUE) return 1;

    strcpy(buffer, "Hello, message queue!");
    WriteFile(hFile, buffer, strlen(buffer), &bytesWritten, NULL);
    printf("Producer: Data sent to message queue: %s\n", buffer);

    if (ReadFile(hSlot, buffer, sizeof(buffer), &bytesRead, NULL)) {
        buffer[bytesRead] = '\0';
        printf("Consumer: Data received from message queue: %s\n", buffer);
    }

    CloseHandle(hFile);
    CloseHandle(hSlot);

    return 0;
}
