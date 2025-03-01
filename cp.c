#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv) {


    // Check for correct arguments
    if (argc != 3) {
        printf("Usage: cp <source> <destination>\n");
        return 1;
    }

    // Open source file
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        printf("Error: Could not open source file\n");
        return 1;
    }

    // Open destination file
    int fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd2 == -1) {
        printf("Error: Could not open destination file\n");
        close(fd);
        return 1;
    }

    // Buffer for copying
    char buffer[4096];
    ssize_t bytesRead, bytesWritten;

    // Read from source and write to destination
    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
        bytesWritten = write(fd2, buffer, bytesRead);
        if (bytesWritten != bytesRead) {
            printf("Error: Write operation failed\n");
            close(fd);
            close(fd2);
            return 1;
        }
    }

    if (bytesRead == -1) {
        printf("Error: Read operation failed\n");  
    }

    // Close file descriptors
    close(fd);
    close(fd2);
    
    return 0;
}
