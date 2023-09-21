// the_shell_header.h
#ifndef THE_SHELL_HEADER_H
#define THE_SHELL_HEADER_H

void execute_command(char *command);
int is_single_word(const char *command);
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>

#endif

