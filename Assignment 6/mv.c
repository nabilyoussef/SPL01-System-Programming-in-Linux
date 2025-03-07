#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: mv <source> <destination>\n");
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error opening source file");
        return 1;
    }

    int fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd2 == -1) {
        perror("Error opening/creating destination file");
        close(fd);
        return 1;
    }

    // Copy file contents
    char buffer[4096];
    ssize_t bytes_read;
    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
        if (write(fd2, buffer, bytes_read) != bytes_read) {
            perror("Error writing to destination file");
            close(fd);
            close(fd2);
            return 1;
        }
    }

    if (bytes_read == -1) {
        perror("Error reading source file");
    }

    // Close files
    close(fd);
    close(fd2);

    // Remove the original source file to complete the "move"
    if (unlink(argv[1]) == -1) {
        perror("Error removing source file");
        return 1;
    }

    return 0;
}
