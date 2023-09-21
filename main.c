#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include "shell.h"

int main(int argc, char *argv[]) {
    if (argc == 2) {
        // Open the file for reading
        FILE *file = fopen(argv[1], "r");
        if (file == NULL) {
            perror("Error opening file");
            exit(EXIT_FAILURE);
        }

        char *command = NULL;
        size_t command_size = 0;
        char *arguments[MAX_ARGUMENTS];

        while (getline(&command, &command_size, file) != -1) {
            // Remove newline character at the end of the line
            size_t length = strlen(command);
            if (length > 0 && command[length - 1] == '\n') {
                command[length - 1] = '\0';
            }

            // Execute the command
            execute_separated_commands(command);
            execute_logical_commands(command);
        }

        // Close the file and free allocated resources
        fclose(file);
        free(command);
    } else {

        char *command = NULL;
        size_t command_size = 0;
        char *arguments[MAX_ARGUMENTS];

        while (1) {
            printf(":) ");
            fflush(stdout);

            ssize_t line_length = read_line(&command);

            if (line_length <= 0) {
                // Handle Ctrl+D (EOF)
                printf("\nThank you for your time, bye!\n");
                free(command);
                break;
            }

            // Check if the command is "exit"
            if (strncmp(command, "exit", 4) == 0) {
                char *exit_status = command + 4;
                while (*exit_status == ' ') {
                    exit_status++; // Skip spaces after "exit"
                }

                if (*exit_status != '\0') {
                    int status = atoi(exit_status);
                    printf("Exiting with status %d\n", status);
                    free(command);
                    exit(status);
                } else {
                    printf("Exiting with status 0\n");
                    free(command);
                    exit(0);
                }
            }

            // Check if the command is "env"
            if (strcmp(command, "env") == 0) {
                // Print environment variables
                execute_command("env", arguments);
            } else if (strncmp(command, "alias", 5) == 0) {
                // Handle the "alias" command
                char *alias_arguments[MAX_ARGUMENTS];
                alias_arguments[0] = "alias"; // Set the first argument as "alias"
                int alias_argument_count = 1;

                // Tokenize the "alias" command
                tokenize_input(command, alias_arguments + 1);

                // Call the custom_alias function to handle aliases
                custom_alias(alias_arguments);
            } else {
                // Execute commands separated by ; and with logical operators && and ||
                execute_separated_commands(command);
                execute_logical_commands(command);
            }
        }
    }

    // Free allocated memory for aliases
    for (int i = 0; i < num_aliases; i++) {
        free(aliases[i].name);
        free(aliases[i].value);
    }

    return 0;
}

