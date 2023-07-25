#include "shell.h"

/**
 * _memset-function that fills the first n bytes
 * @b:the constant to fill the first n bytes
 * @n:bytes of the memory area
 * @s:memory area s
 * Return:returns s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}

/**
 * _free - function that frees a string of strings
 * @str:string of strings
 */
void _free(char **str)
{
	char **s = str;

	if (!str)
		return;
	while (*str)
		free(*str++);
	free(s);
}

/**
 * _realloc - function that reallocates a block of memory
 * @ptr:pointer to previous malloc allocated memory
 * @prev:byte size of previous block
 * @next:byte size of next malloc allocated memory
 *
 * Return:pointer to the next malloc block memory
 */
void *_realloc(void *ptr, unsigned int prev, unsigned int next)
{
	char *s;

	if (!ptr)
		return (malloc(next));
	if (!next)
		return (free(ptr), NULL);
	if (next == prev)
		return (ptr);
	s = malloc(next);
	if (!s)
		return (NULL);
	prev = prev < next ? prev : next;
	while (prev--)
		s[prev] = ((char *)ptr)[prev];
	free(ptr);
	return (s);
}

/**
 * free_address - function that frees a pointer to free
 * @str:address of the pointer to free
 *
 * Return: 1 on success and 0 on failure
 */
int free_address(void **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
		return (1);
	}
	return (0);
}
