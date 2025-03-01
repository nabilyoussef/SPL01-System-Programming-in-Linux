# SPL01-System-Programming-in-Linux

## Introduction
Hello 👋
Repo contains Soruce files of the 6th Assingment of SPL01-System-Programming-in-Linux [Link](https://www.udemy.com/course/spl01-system-programming-in-linux/)

Note: I used ChatGPT to fix and enhance my code.

## Contents
- Task 1: Implementing `pwd`(print work dirctory) command in C
- Task 2: Implementing `echo` command in C
- Task 3: Implementing `cp` (copy) command in C
- Task 4: Implementing `mv` (move) command in C


## Task 1: Implementing `pwd`(print work dirctory) command in C
### Code
```c
#include <stdio.h>
#include <unistd.h>

#include <limits.h> // for PATH_MAX


int main(int argc, char *argv[]) {

    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("%s\n", cwd);
    } else {
        perror("getcwd() error");
        return 1;
    }

}
```

### Execution Steps
1. **Compile the program:**
   ```sh
   gcc -o mypwd pwd.c
   ```
2. **Run the program:**
   ```sh
   ./mypwd
   ```
3. **Output:**
   ```sh
   /home/nabil/Desktop
   ```



## Task 2: Implementing `echo` command in C
### Code
```c
#include <stdio.h>
#include <unistd.h>

#include <string.h> // for strlen

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        write(1, argv[i], strlen(argv[i]));
        write(1, " ", 1);
    }
    write(1, "\n", 1);
}
```

### Execution Steps
1. **Compile the program:**
   ```sh
   gcc -o myecho echo.c
   ```
2. **Run the program:**
   ```sh
   ./myecho Hello, Linux!
   ```
3. **Output:**
   ```sh
   Hello, Linux!
   ```
## Task 3: Implementing `cp` (copy) command in C
### Code
```c
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
```

### Execution Steps
1. **Compile the program:**
   ```sh
   gcc -o mycp cp.c
   ```
2. **Run the program:**
   ```sh
   ./mycp cp.c nabil.c
   ```



## Task 4: Implementing `mv` (move) command in C
### Code
```c
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

```

### Execution Steps
1. **Compile the program:**
   ```sh
   gcc -o mymv mv.c
   ```
2. **Run the program:**
   ```sh
   ./mymv mv.c nabil.c
   ```