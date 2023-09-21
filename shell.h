#ifndef SHELL_H
#define SHELL_H

#define MAX_COMMAND_LENGTH 256
#define MAX_ARGUMENTS 64
#define BUFFER_SIZE 1024
#define MAX_ALIASES 64

// Structure to represent an alias
typedef struct {
    char *name;
    char *value;
} Alias;

extern Alias aliases[MAX_ALIASES]; // Array to store aliases
extern int num_aliases; // Number of aliases defined
extern int last_status; // Store the exit status of the last command

// Function prototypes
void execute_command(char *command, char *arguments[]);
ssize_t read_line(char **lineptr);
void tokenize_input(char *input, char *tokens[]);
int custom_setenv(char *variable, char *value);
int custom_unsetenv(char *variable);
int custom_cd(char *directory);
void execute_separated_commands(char *input);
void execute_logical_commands(char *input);
void print_aliases(char *name);
int define_alias(char *name, char *value);
int custom_alias(char *arguments[]);
char *replace_variables(char *command);

#endif

