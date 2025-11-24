#include <stdio.h>
#include <fcntl.h>      
#include <unistd.h>     
#include <string.h>    

int main() {
    int file;
    char writeData[] = "Hello! This is a UNIX system call demo.\n";
    char readBuffer[100];

  
    file = creat("demo.txt", 0777);  
    if (file < 0) {
        printf("File creation failed!\n");
        return 1;
    }
    printf("File created successfully.\n");
    close(file);

    
    file = open("demo.txt", O_WRONLY);
    if (file < 0) {
        printf("File open for writing failed!\n");
        return 1;
    }

    
    write(file, writeData, strlen(writeData));
    printf("Data written to file.\n");
    close(file);

    
    file = open("demo.txt", O_RDONLY);
    if (file < 0) {
        printf("File open for reading failed!\n");
        return 1;
    }

    
    int bytesRead = read(file, readBuffer, sizeof(readBuffer));
    readBuffer[bytesRead] = '\0';

    printf("Data read from file:\n%s\n", readBuffer);

   
    close(file);

    return 0;
}

