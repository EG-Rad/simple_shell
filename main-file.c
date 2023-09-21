#include "the_shell_header.h"

#define MAX_COMMAND_LENGTH 256

int main(void)
{
    char command[MAX_COMMAND_LENGTH];

    while (1)
    {
        printf("#cisfun$ ");
        fflush(stdout);

        if (fgets(command, sizeof(command), stdin) == NULL)
        {
            printf("\nThank you for your time, Bye!\n");
            break;
        }

        command[strcspn(command, "\n")] = '\0';

        if (is_single_word(command)) {
            execute_command(command);
        } else {
            printf("Invalid command. Please enter a single-word command.\n");
        }
    }

    return 0;
}

