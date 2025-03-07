#include <stdio.h>
#include <string.h>

#define MAX_CMD 100

int main() {
    char str[MAX_CMD];  

    while (1) {
        printf("MyFemtoShell:~$ ");
        fgets(str, MAX_CMD, stdin);

        // Remove newline character
        str[strcspn(str, "\n")] = '\0';

        // Extract command
        char *cmd = strtok(str, " ");
        
        // Check if command exists
        if (cmd == NULL) {
            continue;  
        }

        // Check for exit command
        if (strcmp(cmd, "exit") == 0)  
            break;

        // Handle echo command
        else if (strcmp(cmd, "echo") == 0) {
            char *args = strtok(NULL, ""); 
            if (args)
                printf("%s\n", args);
        }

        else {
            printf("Error: Invalid Command\n");
        }
    }

    printf("Good Bye :)\n");
    return 0;
}
