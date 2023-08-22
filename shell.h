#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>

#define PROMPT "$ "
#define PATH "PATH"
#define BUFFER 1024

extern char **environ;
/**
 * struct builtins - structure to hold built ins
 * @name: the name of the built-in
 * @func: the associated function.
 *
 * Description: defining a built-in struct type.
 */
typedef struct builtins
{
	char *name;
	int (*func)();
} built_in;

/** input_loop.c **/
int is_interactive(void);
char **multiple_cmd(char *line);
int input_loop(char *line, char **env);

/** run_cmd.c **/
int is_path(char *arg, int it);
int exec_cmd(char **args, char **env);
int run_cmd(char **args, char **env, int it);

/** _built_ins.c **/
int exit_bin(char **args, int it);
int env_bin(char **args, char **env);
int _built_ins(char **args, char **env, int it);

/** _getline.c **/
void clear_line(char *line);
int _getline(char *line, int size);

/** _getenv.c **/
char *_getenv(char *name, char **env);

/** string_to_words.c **/
int word_count(char *str, char del);
int word_len(char *str, char del);
char **string_to_words(char *str, char del);

/** search_paths.c **/
char *search_dirs(char **arr, char *arg);

/** strings_func.c **/
int _strlen(char *str);
int _strchr(char *str, char del);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);

/** strings_func_2.c **/
int is_int(char *s);
int _atoi(char *s);

/** printers.c **/
int _putchar(char c, int OUT);
void _puts(char *str);
void _puts_err(char *str);
void print_number(int n, int OUT);
void print_err(char *arg, int it);

/** alloc.c **/
char *_calloc(int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/** free_array.c **/
int array_size(char **arr);
void free_array(char **arr);
void free_previous_mem(int index, char **arr);

#endif
