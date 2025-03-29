
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

void echo (char ** args);
void pwd  (void);
void change_directory(const char * path);
void execute_command ( char **args);
