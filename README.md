# Simple Shell Project

## Introduction

Welcome to the Simple Shell project! This is a basic Unix-like shell implementation written in C. It's a part of the ALX Software Engineering curriculum.

## Project Details

### Description

The **Simple Shell** project, also known as `hsh`, is a command-line shell developed in C. It serves as a key milestone at the end of the first semester of ALX Software Engineering program. This shell is designed to provide a simplified interactive interface for users to interact with their computer's operating system.

### Environment

The project was primarily developed and tested on **Ubuntu 14.04 LTS**.

## Features

The Simple Shell comes with a range of features, including:

- **Interactive Mode:** When executed, the shell provides an interactive prompt to the user.
- **Full Path Execution:** If a command's full path is provided, the shell will execute it directly if it exists.
- **Path Search:** If a command isn't provided with its full path, the shell will search for it in the directories listed in the PATH environment variable.
- **Command Arguments:** The shell can handle arguments passed along with commands.
- **Error Handling:** Comprehensive error handling for various scenarios.
- **Exit Handling:** The user can exit the shell using the `exit` command or by pressing Ctrl-D (End Of File).
- **Built-in Commands:** Implements some built-in commands, such as `exit` and `env`.
- **Command Separator:** Supports command separation using the semicolon (`;`) character.
- **Comments:** Basic support for comments using the `#` character.

## File Descriptions

Here's a detailed list of the files, their associated functions, and their descriptions in the project:

| File               | Function                                                 | Description                                      |
|--------------------|----------------------------------------------------------|--------------------------------------------------|
| [main.c](https://github.com/AliMoussa-00/ALX_learinng/blob/main/C-projects/SHELL/simple_shell/main.c)             | main()                                                   | Entry point of the program.                     |
| [input\_loop.c](https://github.com/AliMoussa-00/ALX_learinng/blob/main/C-projects/SHELL/simple_shell/input_loop.c)      | _int is\_interactive(void)_                                | check if the user in interactive mod |
|                    | _char \*\*multiple\_cmd(char \*line)_                      | checks if the user enter multiple commands seperated by `;`|
|                    | _int input\_loop(char \*line, char \*\*env)_               | a loop that allows the user to keep entering and executing commands|
| [run\_cmd.c](https://github.com/AliMoussa-00/ALX_learinng/blob/main/C-projects/SHELL/simple_shell/run_cmd.c)        | **_int is\_path(char \*arg, int it)_**                         | Checks if a command has a full path provided.   |
|                    | _int exec\_cmd(char \*\*args, char \*\*env)_               | Executes a command in a child process.           |
|                    | _int run\_cmd(char \*\*args, char \*\*env, int it)_        | Handles command execution and path resolution.   |
| [\_built\_ins.c](https://github.com/AliMoussa-00/ALX_learinng/blob/main/C-projects/SHELL/simple_shell/_built_ins.c)     | _int env\_bin(char \*\*args, char \*\*env)_                | Implements the `env` built-in command by printing environment variables. |
|                    | _int exit\_bin(char \*\*args, int it)_                     | Implements the `exit` built-in command, allowing graceful shell termination. |
|                    | _int \_built\_ins(char \*\*args, char \*\*env, int it)_    | Checks if a command is a built-in and returns the associated function. |
| [\_getline.c](https://github.com/AliMoussa-00/ALX_learinng/blob/main/C-projects/SHELL/simple_shell/_getline.c)        | _void clear\_line(char \*line)_                               | Clears the line of any previous input.          |
|                    | _int \_getline(char \*line, int size)_                       | Reads a line of user input.                    |
| [\_getenv.c](https://github.com/AliMoussa-00/ALX_learinng/blob/main/C-projects/SHELL/simple_shell/_getenv.c)         | _char \*\_getenv(char \*name, char \*\*env)_                    | Retrieves the value of a specific environment variable. |
| [string\_to\_words.c](https://github.com/AliMoussa-00/ALX_learinng/blob/main/C-projects/SHELL/simple_shell/string_to_words.c)| _int word\_count(char \*str, char del)_                       | Counts the number of words in a string.         |
|                    | _int word\_len(char \*str, char del)_                        | Calculates the length of each word in a string. |
|                    | _char \*\* string\_to\_words(char \*str, char del)_                | Converts a string to an array of strings based on a delimiter. |
| [search\_dirs.c](https://github.com/AliMoussa-00/ALX_learinng/blob/main/C-projects/SHELL/simple_shell/search_dirs.c)    | _char \*search\_dirs(char \*\*arr, char \*arg)_                 | Searches for a command in the directories listed in the PATH environment variable. |
| [strings\_func.c](https://github.com/AliMoussa-00/ALX_learinng/blob/main/C-projects/SHELL/simple_shell/strings_func.c)    | _int \_strlen(char \*str)_                                   | Calculates the length of a string.             |
|                    | _int \_strchr(char \*str, char del)_                         | Searches for a character in a string.          |
|                    | _char \*\_strcat(char \*dest, char \*src)_                      | Concatenates two strings.                      |
|                    | _int \_strcmp(char \*s1, char \*s2)_                         | Compares two strings.                          |
|                    | _char \*\_strcpy(char \*dest, char \*src)_                      | Copies a string to another.                   |
| [strings\_func\_2.c](https://github.com/AliMoussa-00/ALX_learinng/blob/main/C-projects/SHELL/simple_shell/strings_func_2.c) | _int is\_int(char \*s)_                                      | Checks if a string contains only digits.       |
|                    | _int \_atoi(char \*s)_                                       | Converts a string to an integer.              |
| [printers.c](https://github.com/AliMoussa-00/ALX_learinng/blob/main/C-projects/SHELL/simple_shell/printers.c)         | _int \_putchar(char c, int OUT)_                             | Prints a character to stdout.                 |
|                    | _void \_puts(char \*str)_                                     | Prints a string to stdout.                     |
|                    | _void \_puts\_err(char \*str)_                                | Prints a string to stderr.                     |
|                    | _void print\_number(int n, int OUT)_                          | Prints a number to stdout.                    |
|                    | _void print\_err(char \*arg, int it)_                         | Prints an error message to stderr.            |
| [alloc.c](https://github.com/AliMoussa-00/ALX_learinng/blob/main/C-projects/SHELL/simple_shell/alloc.c)            | _char \*\_calloc(int size)_                                     | Implements memory allocation using calloc.    |
|                    | _void \*\_realloc(void \*ptr, unsigned int old\_size, unsigned int new\_size)_ | Implements realloc              |
| [free\_func.c](https://github.com/AliMoussa-00/ALX_learinng/blob/main/C-projects/SHELL/simple_shell/free_func.c)      | _int array\_size(char \*\*arr)_                              | get the size of the array of strings                  |
|                    | _void free\_array(char \*\*arr)_                                | free the array                           |
|                    | _void free\_previous\_mem(int index, char \*\*arr)_           | in case of an error while allocating memory we need to clear previous allocated memory |
## Contributors

- [Ali Moussaoui](https://github.com/AliMoussa-00)
- [Ismail Morabet](https://github.com/Morabet)
