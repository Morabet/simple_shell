#include "shell.h"

/**
 * _getenv - get the value of key from environ
 * @name: the key to look for.
 * @env: environ
 * Return: the value of the key if found, or NULL.
 */
char *_getenv(char *name, char **env)
{
	char *key, *value, *tmp, *result;
	int i = 0;

	if (!name)
		return (NULL);

	while (env[i])
	{
		tmp = malloc(sizeof(char) * (_strlen(env[i]) + 1));
		if (!tmp)
			return (NULL);
		tmp = _strcpy(tmp, env[i]);

		key = strtok(tmp, "=");

		if (_strcmp(key, name) == 0)
		{
			value = strtok(NULL, "\n");
			if (!value)
			{
				free(tmp);
				return (NULL);
			}

			result = malloc(sizeof(char) * (_strlen(value) + 1));
			if (!result)
			{
				free(tmp);
				return (NULL);
			}
			result = _strcpy(result, value);

			free(tmp);
			return (result);
		}
		free(tmp);
		i++;
	}
	return (NULL);
}
