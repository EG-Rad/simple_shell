#include "the_shell_header.h"

int is_single_word(const char *command)
{
    // Check if the command contains any whitespace characters
    for (size_t i = 0; i < strlen(command); i++)
    {
        if (isspace(command[i]))
        {
            return 0; // Not a single word
        }
    }
    return 1; // Single word
}


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

