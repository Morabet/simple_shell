#include "shell.h"

/**
 * is_int - check if string contains digits only.
 * @s: string.
 * Return: On Success 0, else 1.
 */
int is_int(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

/**
 * _atoi -  a function that convert a string to an integer.
 * @s: pointer to string
 *
 * Return: posititve integer if success, else -1..
 */
int _atoi(char *s)
{
	unsigned int n = 0;
	int min = 1;
	int is_int = 0;

	while (*s)
	{
		if (*s == '-')
		{
			return (-1);
		}
		if (*s < '0' || *s > '9')
			return (-1);
		while (*s >= '0' && *s <= '9')
		{
			is_int = 1;
			n = (n * 10) + (*s - '0');
			s++;
		}
		if (is_int == 1)
		{
			break;
		}
		s++;
	}
	n *= min;
	return (n);
}
