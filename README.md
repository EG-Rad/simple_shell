# Simple Shell Project

**Authors:** Alaa Radwan, Tshegofatso Tswai

## Overview

This is a simple shell project developed as part of a coding exercise. The project aims to create a basic command-line shell that can execute commands, handle aliases, variables, and basic shell operations. The shell can be used both interactively and to run commands from a file.

## Project Structure

The project is organized into several files and directories:

- `main.c`: Contains the main entry point of the shell program, which determines whether to run in interactive mode or execute commands from a file.
- `utils.c` and `utils.h`: Provide utility functions for reading input and tokenizing commands.
- `aliases.c` and `aliases.h`: Handle alias-related functionality.
- `commands.c` and `commands.h`: Implement command execution logic, including handling multiple commands, logical operators, and exit built-in.
- `variables.c` and `variables.h`: Manage shell variables and replace special variables like `$$` and `$?`.
- `shell.h`: Header file containing function prototypes and includes.
