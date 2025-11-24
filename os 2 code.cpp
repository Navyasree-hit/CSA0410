#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <sys/stat.h>

int main() {
    int source, destination;
    char buffer[1024];
    int bytesRead;

    // Open source file for reading
    source = _open("source.txt", _O_RDONLY);
    if (source < 0) {
        printf("Error: Could not open source.txt\n");
        return 1;
    }

    // Create destination file (write-only, create if not exists)
    destination = _open("copy.txt", _O_WRONLY | _O_CREAT | _O_TRUNC, _S_IREAD | _S_IWRITE);
    if (destination < 0) {
        printf("Error: Could not create copy.txt\n");
        _close(source);
        return 1;
    }

    // Copy loop
    while ((bytesRead = _read(source, buffer, sizeof(buffer))) > 0) {
        _write(destination, buffer, bytesRead);
    }

    printf("File copied successfully!\n");

    // Close both files
    _close(source);
    _close(destination);

    return 0;
}

