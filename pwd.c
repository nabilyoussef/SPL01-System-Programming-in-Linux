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
