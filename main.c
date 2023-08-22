#include "shell.h"

/**
 * main - entry point to the program
 *
 * Return: On Success 0.
 */

int main(void)
{
	char **env = environ;
	char *line;
	int result;

	line = malloc(sizeof(char) * BUFFER);
	if (!line)
		return (1);

	result = input_loop(line, env);

	free(line);
	return (result);
}
