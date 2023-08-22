#include "shell.h"

/**
 * _strlen - a function that returns the length of a string.
 * @str: pointer to char
 * Return: the number of characters..
 */
int _strlen(char *str)
{
	int i = 0;

	if (str[i] != '\0')
	{
		while (str[i] != '\0')
			i++;
	}
	return (i);
}

/**
 * _strchr - search if a char exists in a str
 * @str: the string to search in.
 * @del: the char to search for.
 * Return: 1 if exist else -1.
 */
int _strchr(char *str, char del)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == del)
			return (1);
		i++;
	}
	return (-1);
}

/**
 * _strcat - concatenate src to dest
 * @dest: pointer to the first string
 * @src: the second string
 * Return: string.
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, len = 0;

	len = _strlen(dest);

	while (src[i] != '\0')
	{
		dest[len + i] = src[i];
		i++;
	}

	dest[len + i] = '\0';

	return (dest);
}

/**
 * _strcmp - compare two strings
 * @s1: pointer to the first string
 * @s2: second string
 * Return: 0 if identical else -1.
 */
int _strcmp(char *s1, char *s2)
{
	int diff = 0;

	if (*s1 == '\0' || *s2 == '\0')
		return (-1);

	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 != *s2)
			return (-1);

		s1++;
		s2++;
	}
	return (diff);
}

/**
 * _strcpy - copy s2 to s1.
 * @dest: pointer to the first string
 * @src: second string
 * Return: string.
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}
