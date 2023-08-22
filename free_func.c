#include "shell.h"

/**
 * array_size - count the size of the array
 * @arr: the array of strings.
 * Return: integer.
 */
int array_size(char **arr)
{
	int c = 0;

	if (arr && *arr)
	{
		while (arr[c])
			c++;
	}
	return (c);
}

/**
 * free_array - free an array of string
 * @arr: the array to free.
 * Return: void.
 */
void free_array(char **arr)
{
	int i = 0, s;

	if (!arr || !*arr)
		return;

	s = array_size(arr);
	for (i = 0; i < s; i++)
	{
		if (arr[i])
			free(arr[i]);
	}
	free(arr);
}

/**
 * free_previous_mem - free the array in case of ERROR
 * @index: the index from where to free.
 * @arr: the arr to free;
 * Return: void.
 */
void free_previous_mem(int index, char **arr)
{
	int j;

	if (!arr || !*arr)
		return;

	for (j = index - 1; j >= 0; j--)
		free(arr[j]);
	free(arr);
}
