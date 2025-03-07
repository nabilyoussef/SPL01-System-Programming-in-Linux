#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 256

int main() {
    char input[MAX_INPUT_SIZE];
    char command[MAX_INPUT_SIZE];
    char args[MAX_INPUT_SIZE];

    printf("$ ./myFemtoShell\n");

    while (1) {
        printf("Femto shell prompt > ");
        fgets(input, MAX_INPUT_SIZE, stdin);

        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        // Parse the command
        if (sscanf(input, "%s %[^"]", command, args) < 1) {
            continue;  // Handle empty input
        }

        if (strcmp(command, "echo") == 0) {
            printf("%s\n", args);
        } else if (strcmp(command, "exit") == 0) {
            printf("Good Bye :)\n");
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}
