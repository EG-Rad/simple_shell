#include <stdio.h>
#include <string.h>
#include "the_shell-header.h"

#define MAX_COMMAND_LENGTH 256

int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		printf("#ourFirstShell$ ");
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

