#include "the_shell-header.h"

/*
 * File: main-file.c
 * Description: A simple shell program that reads and executes user-entered commands.
 *              It uses fork() to create child processes for command execution.
 */

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

		execute_command(command);
	}

	return (0);
}

