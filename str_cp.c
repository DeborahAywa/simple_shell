#include "shell.h"

/**
 * dn_strcpy - Copies a string from src to dest
 * @dest: Where to copy the string to.
 *@src: A source string to copy.
 *
 * Return: A pointer to the destination string @dest.
 */
char *dn_strcpy(char *dest, char *src)
{
	int index = 0;

	for (index = 0; src[index] != '\0'; index++)
	{
		dest[index] = src[index];
	}
	dest[index] = '\0';

	return (dest);
}
