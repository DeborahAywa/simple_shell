#include "shell.h"

/**
 * *_strcat-function that concatenates string/
 * src to dest /
 *
 * @dest:the destination where src is to be /
 * appended
 *
 * @src:the string to be appended
 *
 * Return:a pointer to string dest
 */

char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;
	int p;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		j++;
	}
	for (p = 0; p <= j; p++)
	{
		dest[i + p] = src[p];
	}
	return (dest);
}
