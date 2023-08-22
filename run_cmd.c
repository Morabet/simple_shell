#include "shell.h"

/**
 * is_path - checks if the cmd is already a full path
 * @arg: string of the cmd
 * @it: the numbe of iteration
 * Return: if true 0, -1 if not valid and 1 else
 */
int is_path(char *arg, int it)
{
	int i;

	for (i = 0; arg[i] != '\0'; i++)
	{
		if (arg[i] == '/' && arg[i + 1] != '\0' &&
				arg[i + 1] != '/' &&
				access(arg, F_OK | X_OK) == 0)
			return (0);
	}
	if ((arg[0] == '/' || arg[0] == '.') && arg[i] == '\0')
	{
		print_err(arg, it);
		return (-1);
	}
	return (1);
}

/**
 * exec_cmd - execute cmd
 * @args: arguments of cmd
 * @env: the environment variables.
 * Return: 0 on Success else 1.
 */
int exec_cmd(char **args, char **env)
{
	pid_t child_pid;
	int status = 0;

	child_pid = fork();
	if (child_pid == -1)
		return (1);

	if (child_pid == 0)
	{
		if (execve(*args, args, env) == -1)
		{
			if (errno == ENOENT)
				exit(2);
			else
				exit(1);
		}
	}
	else
		wait(&status);

	if (WIFEXITED(status))
		status = WEXITSTATUS(status);

	return (status);
}

/**
 * run_cmd - run the command
 * @args: the user cmd and args
 * @env: variable environment
 * @it: the number of iteration.
 * Return: On success 0, else 1
 */
int run_cmd(char **args, char **env, int it)
{
	char *path_string, **path_arr, *dir;
	int is_p, result;

	is_p = is_path(*args, it);
	if (is_p == -1)
		return (1);
	else if (is_p == 0)
		return (exec_cmd(args, env));

	path_string = _getenv(PATH, env);
	if (!path_string)
	{
		print_err(*args, it);
		return (127);
	}

	path_arr = string_to_words(path_string, ':');
	if (!path_arr)
	{
		free(path_string);
		return (1);
	}

	dir = search_dirs(path_arr, *args);
	if (!dir)
	{
		print_err(*args, it);
		free(path_string);
		free_array(path_arr);
		return (127);
	}

	*args = _realloc(*args, _strlen(*args), _strlen(dir) + 1);
	*args = _strcpy(*args, dir);
	result = exec_cmd(args, env);

	free(dir);
	free(path_string);
	free_array(path_arr);
	return (result);
}
