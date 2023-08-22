#include "shell.h"

/**
 * word_count - count words in a string
 * @str: pointer to string.
 * @del: delimeter
 * Return: number of words
 */
int word_count(char *str, char del)
{
	int i = 0, count = 0;

	while (str[i] != '\0')
	{
		if ((str[i] != del && str[i] != '\t') &&
				((str[i + 1] == del)
				|| (str[i + 1] == '\t')
				|| (str[i + 1] == '\0')))
			count++;
		i++;
	}
	return (count);
}

/**
 * word_len - count the length of words in strings.
 * @str: the string containing words.
 * @del: the delimeter
 * Return: the length of each word.
 */
int word_len(char *str, char del)
{
	int i = 0;

	while (str[i] != del &&
			str[i] != '\t' &&
			str[i] != '\0')
		i++;
	return (i);
}

/**
 * string_to_words - split a string to an array of words
 * @str: the string to split
 * @del: delimeter
 * Return: an array of chars or NULL;
 */
char **string_to_words(char *str, char del)
{
	char **arr;
	int i = 0, j = 0, h, count, len;

	if (!str || *str == '\0' || !*str)
		return (NULL);

	count = word_count(str, del);
	if (count == 0)
		return (NULL);

	arr = malloc(sizeof(char *) * (count + 1));
	if (!arr)
		return (NULL);

	while (str[i] != '\0')
	{
		while (str[i] == del ||
				str[i] == '\t')
			i++;

		if (str[i] == '\0')
			break;

		len = word_len(str + i, del);

		arr[j] = malloc(sizeof(char) * (len + 1));
		if (!arr[j])
			free_previous_mem(j, arr);

		for (h = 0; h < len && str[i] != '\0'; h++, i++)
			arr[j][h] = str[i];
		arr[j][h] = '\0';
		j++;
	}
	arr[j] = NULL;
	return (arr);
}
