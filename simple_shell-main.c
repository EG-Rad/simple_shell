#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 256

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

int main() {
	char command[MAX_COMMAND_LENGTH];

	while (1) {
		printf("#ourFirstShell$ ");
		fflush(stdout);

		if (fgets(command, sizeof(command), stdin) == NULL) {

			printf("\nThank you for your time, Bye!\n");
			break;
		}


		command[strcspn(command, "\n")] = '\0';

		execute_command(command);
	}

	return 0;
}
