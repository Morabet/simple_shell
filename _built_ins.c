#include "shell.h"

/**
 * env_bin - implements the env built-in
 * @args: the cmd arguments.
 * @env: the environment variables.
 * Return: 0 On Success, else 1.
 */
int env_bin(char **args, char **env)
{
	int size, i = 0;

	size = array_size(args);

	if (size > 1)
	{
		_puts_err("env: ‘");
		_puts_err(args[1]);
		_puts_err("’: No such file or directory\n");
		return (1);
	}
	while (env && env[i])
	{
		_puts(env[i]);
		_puts("\n");
		i++;
	}
	return (0);
}

/**
 * exit_bin - implement exit built-in.
 * @args: the cmd args.
 * @it: the number of iteration
 * Return: on Success 0 else 1.
 */
int exit_bin(char **args, int it)
{
	int s, status;

	s = array_size(args);
	if (s < 1)
		return (1);
	if (s == 1)
		return (0);
	if (s >= 2)
	{
		status = is_int(args[1]);
		if (status == 1)
		{
			_puts_err("./hsh: ");
			print_number(it, STDERR_FILENO);
			_puts_err(": exit: Illegal number: ");
			_puts_err(args[1]);
			_puts_err("\n");
			return (2);
		}
		status = _atoi(args[1]);
		if (status != -1)
			return (status > 255 ? (status % 256) : status);
	}
	return (1);
}

/**
 * _built_ins - check if a built-in cmd
 * @args: the input cmd
 * @env: the variable environments
 * @it: the number of iteration
 * Return: if error 1, -1 if not found
 */
int _built_ins(char **args, char **env, int it)
{
	int i = 0, result;
	built_in bins[] = {
		{"exit", exit_bin},
		{"env", env_bin},
		{NULL, NULL}
	};

	if (!args)
		return (1);

	while ((bins + i)->name)
	{
		if (_strcmp((bins + i)->name, *args) == 0)
		{
			if (_strcmp("exit", *args) == 0)
			{
				result = ((bins + i)->func(args, it));
				return (result);
			}
			result = ((bins + i)->func(args, env));
			return (result);
		}
		i++;
	}
	return (-1);
}
