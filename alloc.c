#include "shell.h"

/**
 * _calloc - allocate memory and sets it to 0.
 * @size: size of memory.
 * Return: pointer to the allocated mem.
 */
char *_calloc(int size)
{
	char *p;
	int i;

	if (size <= 0)
		return (NULL);
	p = malloc(size);
	if (!p)
		return (NULL);

	for (i = 0; i < size; i++)
		*(p + i) = 0;

	return (p);
}

/**
 * _realloc - realloc to the new size
 *
 * @ptr: pointer to the mem
 * @old_size: the old mem size
 * @new_size: the new size of the mem
 * Return: pointer to the new mem
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p, *np = ptr;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		p = malloc(new_size);
		if (p == NULL)
			return (NULL);
		return (p);
	}
	p = malloc(sizeof(char) * new_size);
	if (p == NULL)
		return (NULL);

	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			p[i] = np[i];
	}
	if (new_size > old_size && old_size != 0)
	{
		for (i = 0; i < new_size; i++)
		{
			if (i < old_size)
				p[i] = np[i];
			else
				p[i] = 0;
		}
	}
	free(ptr);
	return (p);
}
