#include "shell.h"

/**
 * search_dirs - search for cmd in PATH dirs
 * @arr: directories of PATH.
 * @arg: the cmd input.
 * Return: the full dir of cmd
 */
char *search_dirs(char **arr, char *arg)
{
	char *dir;
	int i = 0, len1, len2 = _strlen(arg);

	while (arr[i])
	{
		len1 = _strlen(arr[i]);
		dir = malloc(sizeof(char) * (len1 + 1));
		if (!dir)
			return (NULL);
		dir = _strcpy(dir, arr[i]);

		dir = _realloc(dir, len1, len1 + 2);
		dir = _strcat(dir, "/");
		len1 = _strlen(dir);
		dir = _realloc(dir, len1, len1 + len2 + 1);
		dir = _strcat(dir, arg);
		if (access(dir, F_OK | X_OK) == 0)
			return (dir);

		free(dir);
		i++;
	}
	return (NULL);
}
