#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "the_shell-header.h"

void execute_command(char *command) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0) {
        char *args[] = {command, NULL};
        if (execvp(command, args) == -1) {
            perror("Error");
            exit(EXIT_FAILURE);
        }
    } else if (pid < 0) {
        perror("Fork failed");
    } else {
        waitpid(pid, &status, 0);
    }
}

