#include "shell.h"

/**
 * _puts-function that prints a string
 *
 * @str:string to be printed
 */

void _puts(char *str)
{
	int j = 0;

	if (!str)
		return;
	while (str[j] != '\0')
	{
		_putchar(str[j]);
		j++;
	}
}

/**
 * _strncpy-function that copies a string
 *
 * @dest:string that src is copied to
 * @src:string that is to be copied
 * @n:maximum number of bytes to be copied
 *
 * Return:return dest string
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	return (dest);
}

/**
 * free_string - function that frees a string of strings
 *
 * @str:string of strings
 * Return:nothing
 */
void free_string(char **str)
{
	char **s = str;

	if (!str)
		return;
	while (*str)
		free(*str++);
	free(s);
}

/**
 * free_pointer - function that frees a pointer and NULLs the address
 * @str:address of the pointer to free
 *
 * Return: 1 if freed and 0 otherwise
 */
int free_pointer(void *str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
		return (1);
	}
	return (0);
}

/**
 * _strtok - function that splits a string into words
 *
 * @str:the input string
 * @d:the delimeter string
 *
 * Return:a pointer to an array of strings otherwise NULL
 */
char **_strtok(char *str, char *d)
{
	int i, j, p, q, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; str[i] != '\0'; i++)
	{
		if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || !str[i + 1]))
			numwords++;
		if (numwords == 0)
			return (NULL);
		s = malloc(sizeof(char *) * (1 + numwords));
		if (!s)
			return (NULL);
		for (i = 0; j = 0; j < numwords; j + 1)
		{
			while (is_delim(str[i], d))
				i++;
			p = 0;
			while (!is_delim(str[i + p], d) && str[i + p])
				p++;
			s[j] = malloc(sizeof(char) * (p + 1));
			if (!s[j])
			{
				for (p = 0; p < j; p++)
					free(s[p]);
				free(s);
				return (NULL);
			}
			for (q = 0; q < k; q++)
				s[j][q] = str[i++];
			s[j][q] = 0;
		}
		s[j] = NULL;
		return (s);
	}
}
