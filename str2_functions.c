#include "shell.h"

/**
 * _strdup - function that duplicates a string
 * @str:string to be duplicated
 *
 * Return:pointer to the duplicated string
 */

char *_strdup(const char *str)
{
	int i = 0;
	char *result;

	if (str == NULL)
		return (NULL);
	while (*str++)
		i++;
	result = malloc(sizeof(char) * (i + 1));
	if (!result)
		return (NULL);
	for (i++; i--)
		result[i] = *--str;
	return (result);
}

/**
 * _strncat-function that concatenates 2 strings
 * with n bytes
 *
 * @dest:destination of string
 * @src:source of string
 * @n:max bytes from src
 *
 * Return:return dest string
 */
char *_strncat(char *dest, char *src, int n)
{
	int i;
	int j;
	int p;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		j++;
	}
	for (p = 0; p < n; p++)
	{
		dest[i + 1] = src[j];
	}
	return (dest);
}

/**
 * _strchr - function that locates a character
 *
 * @s:the string
 * @c:the character
 * Return:pointer to first occurence
 */

char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] >= '\0'; i++)
	{
		if (s[i] == c)
			return (&s[i]);
	}
	return (0);
}

/**
 * starts_with - function that checks if needle is in the haystack
 *
 * @haystack:string to search
 * @needle:the substring to find
 *
 * Return:address of next character of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *) haystack);
}

/**
 * _putchar - writes the character c to standard output
 *
 * @c:character to print
 *
 * Return:1 on success
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
