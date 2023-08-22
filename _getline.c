#include "shell.h"

/**
 * clear_line - clear the of any previous inout.
 * @line: the pointer to the string.
 *
 * Return: void.
 */
void clear_line(char *line)
{
	int i;

	for (i = 0; i < BUFFER; i++)
		line[i] = 0;
}

/**
 * _getline - read the inputed line by the user
 * @line: the pointer to the string to fill.
 * @size: size of the line.
 *
 * Return: the number of chars or -1.
 */
int _getline(char *line, int size)
{
	int i, value;

	if (is_interactive() == 0)
		_puts(PROMPT);

	clear_line(line);

	for (i = 0; i < size - 1; i++)
	{
		value = read(STDIN_FILENO, (line + i), 1);
		if (value == 0)
			return (-1); /** EOF or C-d **/
		if (line[i] == '\n')
			break;
	}
	line[i] = '\0';
	return (i);
}
