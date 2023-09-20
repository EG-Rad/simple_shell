#include "the_shell_header.h"

void execute_command(char *command)
{
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0)
    {
        char *args[2];
        args[0] = command;
        args[1] = NULL;

        if (execvp(command, args) == -1)
        {
            perror("Error");
            exit(EXIT_FAILURE);
        }
    }
    else if (pid < 0)
    {
        perror("Fork failed");
    }
    else
    {
        waitpid(pid, &status, 0);
    }
}

